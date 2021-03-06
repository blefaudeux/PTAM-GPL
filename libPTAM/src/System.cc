// Copyright 2008 Isis Innovation Limited
#include "System.h"
#include <gvars3/instances.h>
#include <stdlib.h>
#include "ATANCamera.h"
#include "MapMaker.h"
#include "Tracker.h"
#include "ARDriver.h"
#include "MapViewer.h"

using namespace CVD;
using namespace std;
using namespace GVars3;

System::System(bool automate_start)
  : mGLWindow(mVideoSource.Size(), "PTAM"),
    b_draw_gui(false)
{
  GUI.RegisterCommand("exit", GUICommandCallBack, this);
  GUI.RegisterCommand("quit", GUICommandCallBack, this);
  
  mimFrameBW.resize(mVideoSource.Size());
  mimFrameRGB.resize(mVideoSource.Size());
  // First, check if the camera is calibrated.
  // If not, we need to run the calibration widget.
  Vector<NUMTRACKERCAMPARAMETERS> vTest;
  
  vTest = GV3::get<Vector<NUMTRACKERCAMPARAMETERS> >("Camera.Parameters", ATANCamera::mvDefaultParams, HIDDEN);
  mpCamera = new ATANCamera("Camera");
  Vector<2> v2;
  if(v2==v2) ;
  if(vTest == ATANCamera::mvDefaultParams)
  {
    cout << endl;
    cout << "! Camera.Parameters is not set, need to run the CameraCalibrator tool" << endl;
    cout << "  and/or put the Camera.Parameters= line into the appropriate .cfg file." << endl;
    exit(1);
  }
  
  mpMap       = new Map;
  mpMapMaker  = new MapMaker(*mpMap, *mpCamera);
  mpTracker   = new Tracker(mVideoSource.Size(), *mpCamera, *mpMap, *mpMapMaker, automate_start);
  
  GUI.ParseLine("GLWindow.AddMenu Menu Menu");
  GUI.ParseLine("Menu.ShowMenu Root");
  GUI.ParseLine("Menu.AddMenuButton Root Reset Reset Root");
  GUI.ParseLine("Menu.AddMenuButton Root Spacebar PokeTracker Root");
  GUI.ParseLine("DrawAR=0");
  GUI.ParseLine("DrawMap=0");
  GUI.ParseLine("Menu.AddMenuToggle Root \"View Map\" DrawMap Root");
  GUI.ParseLine("Menu.AddMenuToggle Root \"Draw AR\" DrawAR Root");
  
  b_done = false;
  b_is_alive = false;
  b_automated_track_start = automate_start;

  ARDriver_initialized = false;
  AR_assets_filename = "";
}

bool System::setARModel(const string model_file) {
  AR_assets_filename = model_file;
}

void System::resetMap(void) {
  this->mpMapMaker->RequestReset();

  // Wait until the reset has been done ?
  // FIXME
}

/*!
 * \brief System::Run
 * The loop function, grabbing the frames and updating the system.
 * Won't return until the SLAM is closed, start in a seperate thread if needed
 */
void System::Run()
{
  this->b_is_alive = true;

  if (!ARDriver_initialized) {
    // Initialize all the graphics here, so that it can be moved to a
    // seperate thread
    mpMapViewer = new MapViewer(*mpMap, mGLWindow);
    mpARDriver = new ARDriver(*mpCamera, mVideoSource.Size(), mGLWindow, AR_assets_filename);
    mpARDriver->Init();
    ARDriver_initialized = true;
  }

  while(!b_done)
  {
    // We use two versions of each video frame:
    // One black and white (for processing by the tracker etc)
    // and one RGB, for drawing.

    // Grab new video frame...
    mVideoSource.GetAndFillFrameBWandRGB(mimFrameBW, mimFrameRGB);

    mGLWindow.SetupViewport();
    mGLWindow.SetupVideoOrtho();
    mGLWindow.SetupVideoRasterPosAndZoom();

    if(!mpMap->IsGood())
      mpARDriver->Reset();

    static gvar3<int> gvnDrawMap("DrawMap", 0, HIDDEN|SILENT);
    static gvar3<int> gvnDrawAR("DrawAR", 0, HIDDEN|SILENT);

    bool bDrawMap = mpMap->IsGood() && *gvnDrawMap;
    bool bDrawAR = mpMap->IsGood() && *gvnDrawAR;

    // Update the camera pose and map (SLAM)
    mpTracker->TrackFrame(mimFrameBW, !bDrawAR && !bDrawMap);

    // Rendering : either the 3D view or AR
    if(bDrawMap)
      mpMapViewer->DrawMap(mpTracker->GetCurrentPose());
    else if(bDrawAR)
      mpARDriver->Render(mimFrameRGB, mpTracker->GetCurrentPose(), (mpTracker->GetLostFrames()<3));

    // Draw the menu and captions
    string sCaption;
    if(bDrawMap)
      sCaption = mpMapViewer->GetMessageForUser();
    else
      sCaption = mpTracker->GetMessageForUser();

    mGLWindow.DrawCaption(sCaption);
    mGLWindow.DrawMenus();

    mGLWindow.swap_buffers();
    mGLWindow.HandlePendingEvents();
  }
  cout << "Ending PTAM run" << endl;
  this->b_is_alive = false;
}

bool System::isAlive(void) const {
  return this->b_is_alive;
}

void System::GUICommandCallBack(void *ptr, string sCommand, string sParams)
{
  if(sCommand=="quit" || sCommand == "exit")
    static_cast<System*>(ptr)->b_done = true;
}

// A callable function to stop the computations
void System::Stop() {
  this->b_done = true;
}

/*!
 * \brief System::GetCurrentPose.
 * Get the current camera pose from the tracker state.
 * Output using a streamlined form, easier to use in Python
 * \return
 */
void System::GetCurrentPose(double *pose) const {
  SE3<> current_pose = this->mpTracker->GetCurrentPose();

  // Translation is simple, just a vector
  TooN::Vector<3, double> translation = current_pose.get_translation();

  // Handle the rotation (we get a matrix here)
  TooN::Matrix <3,3,double> rotation = current_pose.get_rotation().get_matrix();

  // We output the multiplexed values in a single array
  for (int i=0; i<3; ++i) {
    pose[i] = translation[i];
  }

  // A bit stupid, fast hack to see if the values are usable
  for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
      pose[3 + 3*i + j] = rotation(i,j);
    }
  }
}

int System::GetCurrentKeyframes() const {
  return this->mpMap->vpKeyFrames.size();
}

int System::GetCurrentPoints() const {
  return this->mpMap->vpPoints.size();
}

int System::GetDiscardedPoints(void) const {
  return this->mpMap->vpPointsTrash.size();
}
