// Copyright 2008 Isis Innovation Limited
#include "System.h"
#include "OpenGL.h"
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


System::System()
  : mGLWindow(mVideoSource.Size(), "PTAM")
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
  
  mpMap = new Map;
  mpMapMaker = new MapMaker(*mpMap, *mpCamera);
  mpTracker = new Tracker(mVideoSource.Size(), *mpCamera, *mpMap, *mpMapMaker);
  
  GUI.ParseLine("GLWindow.AddMenu Menu Menu");
  GUI.ParseLine("Menu.ShowMenu Root");
  GUI.ParseLine("Menu.AddMenuButton Root Reset Reset Root");
  GUI.ParseLine("Menu.AddMenuButton Root Spacebar PokeTracker Root");
  GUI.ParseLine("DrawAR=0");
  GUI.ParseLine("DrawMap=0");
  GUI.ParseLine("Menu.AddMenuToggle Root \"View Map\" DrawMap Root");
  GUI.ParseLine("Menu.AddMenuToggle Root \"Draw AR\" DrawAR Root");
  
  mbDone = false;
  ARDriver_initialized = false;
};

/*!
 * \brief System::Run
 * The loop function, grabbing the frames and updating the system.
 * Won't return until the SLAM is closed, start in a seperate thread if needed
 */
void System::Run()
{
  if (!ARDriver_initialized) {
      // Initialize all the graphics here, so that it can be moved to a
      // seperate thread
      mpMapViewer = new MapViewer(*mpMap, mGLWindow);
      mpARDriver = new ARDriver(*mpCamera, mVideoSource.Size(), mGLWindow);
      mpARDriver->Init();
      ARDriver_initialized = true;
    }

  while(!mbDone)
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

      mpTracker->TrackFrame(mimFrameBW, !bDrawAR && !bDrawMap);

      if(bDrawMap)
        mpMapViewer->DrawMap(mpTracker->GetCurrentPose());
      else if(bDrawAR)
        mpARDriver->Render(mimFrameRGB, mpTracker->GetCurrentPose());

      //  mGLWindow.GetMousePoseUpdate();
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
}

void System::GUICommandCallBack(void *ptr, string sCommand, string sParams)
{
  if(sCommand=="quit" || sCommand == "exit")
    static_cast<System*>(ptr)->mbDone = true;
}

// A callable function to stop the computations
void System::Stop() {
  this->mbDone = true;
}

/*!
 * \brief System::GetCurrentPose.
 * Get the current camera pose from the tracker state.
 * Output using a streamlined form, easier to use in Python
 * \return
 */
void System::GetCurrentPose(float *pose) const {
  SE3<> current_pose = this->mpTracker->GetCurrentPose();

  // Translation is simple, just a vector
  TooN::Vector<3, float> translation = current_pose.get_translation();

  // Handle the rotation (we get a matrix here)
  TooN::Matrix <3,3,float> rotation = current_pose.get_rotation().get_matrix();

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

int System::GetCurrentKeyframes() {
 return this->mpMap->vpKeyFrames.size();
}

int System::GetCurrentPoints() {
  return this->mpMap->vpPoints.size();
}

int System::GetDiscardedPoints() {
  return this->mpMap->vpPointsTrash.size();
}
