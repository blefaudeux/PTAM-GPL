// Copyright 2008 Isis Innovation Limited
#define GL_GLEXT_PROTOTYPES 1
#include "ARDriver.h"

using namespace GVars3;
using namespace CVD;
using namespace std;

static bool CheckFramebufferStatus();

inline void VectorToFloatArray(const Vector<3> vec_in, float *vec_out);

ARDriver::ARDriver(const ATANCamera &cam,
                   ImageRef irFrameSize,
                   GLWindow2 &glw,
                   std::string ARSceneFile)
  :mCamera(cam), mGLWindow(glw)
{
  mirFrameSize = irFrameSize;
  mCamera.SetImageSize(mirFrameSize);

  if (!ARSceneFile.empty()) {
    target_model  = new AssimpRenderer(ARSceneFile);
    useEyeGame    = false;

  } else {
    target_model  = NULL;
    useEyeGame    = true;
  }

  mbInitialised = false;
}

void ARDriver::Init()
{
  cout << "ARDriver : init" << endl;

  // Init the window, and the GL context
  mirFBSize = GV3::get<ImageRef>("ARDriver.FrameBufferSize", ImageRef(1200,900), SILENT);
  glGenTextures(1, &mnFrameTex);
  glBindTexture(GL_TEXTURE_RECTANGLE_ARB,mnFrameTex);
  glTexImage2D(GL_TEXTURE_RECTANGLE_ARB, 0,
               GL_RGBA, mirFrameSize.x, mirFrameSize.y, 0,
               GL_RGBA, GL_UNSIGNED_BYTE, NULL);

  glewExperimental = GL_TRUE;   // fix the glBindVertexArrays bug
  glewInit();
  MakeFrameBuffer();

  if (NULL != target_model) {
    // Init the Assimp handler
    if (!target_model->init()) {
      cout << "ARDriver : could not initialise AssimpRenderer" << endl;
      delete target_model;
      target_model = NULL;
    }
  } else {
    // Init the GL-Eyes
    mGame.Init();
  }

  mbInitialised = true;
  cout << "ARDriver : Init done" << endl;
}

void ARDriver::Reset()  {
  mGame.Reset();
  mnCounter = 0;
}

void ARDriver::Render(Image<Rgb<byte> > &imFrame,
                      SE3<> se3CfromW,
                      bool render_3D_model)  {
  if(!mbInitialised)  {
    Init();
    Reset();

    // Init the auxiliary renderer, and bound it to the existing window
    if ((NULL != target_model) && (target_model->init())) {
      cout << "  ARDriver: Could not initialize Assimp renderer" << endl;
    }

    cout << "  ARDriver: Render initialized" << endl;
  };
  
  mnCounter++;
  
  // Upload the image to our frame texture
  glBindTexture(GL_TEXTURE_RECTANGLE_ARB, mnFrameTex);
  glTexSubImage2D(GL_TEXTURE_RECTANGLE_ARB,
                  0, 0, 0,
                  mirFrameSize.x, mirFrameSize.y,
                  GL_RGB,
                  GL_UNSIGNED_BYTE,
                  imFrame.data());
  
  // Set up rendering to go the FBO, draw undistorted video frame into BG
  glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, mnFrameBuffer);
  CheckFramebufferStatus();
  glViewport(0,0,mirFBSize.x,mirFBSize.y);
  DrawFBBackGround();
  glClearDepth(1);
  glClear(GL_DEPTH_BUFFER_BIT);
  
  if (render_3D_model) {
    // Set up 3D projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMultMatrix(mCamera.MakeUFBLinearFrustumMatrix(0.005, 100)); // Define near and far cutoffs
    glMultMatrix(se3CfromW);

    // Draw the base 3D stuff
    DrawFadingGrid();

    if (useEyeGame) {
      mGame.DrawStuff(se3CfromW.inverse().get_translation());
    } else {
      // Call the Assimp renderer to add the loaded 3D model to the scene
      if (NULL != target_model) {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glMultMatrix(se3CfromW.inverse());

        Vector<3> cam_pose = se3CfromW.inverse().get_translation();
        float f_cam_pose[3];
        VectorToFloatArray(cam_pose, &f_cam_pose[0]);

        target_model->renderSceneToFB(&f_cam_pose[0]);
      }
    }
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_BLEND);
  }

  // Set up for drawing 2D stuff:
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glBindFramebufferEXT(GL_FRAMEBUFFER_EXT,0);
  DrawDistortedFB();
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  mGLWindow.SetupViewport();
  mGLWindow.SetupVideoOrtho();
  mGLWindow.SetupVideoRasterPosAndZoom();
}

void ARDriver::MakeFrameBuffer()
{
  cout << "  ARDriver: Creating FBO... " << endl;
  glGenTextures(1, &mnFrameBufferTex);
  glBindTexture(GL_TEXTURE_RECTANGLE_ARB,mnFrameBufferTex);
  glTexImage2D(GL_TEXTURE_RECTANGLE_ARB, 0,
               GL_RGBA, mirFBSize.x, mirFBSize.y, 0,
               GL_RGBA, GL_UNSIGNED_BYTE, NULL);
  glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  // Initialize DepthBuffer
  GLuint DepthBuffer;
  glGenRenderbuffersEXT(1, &DepthBuffer);
  glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, DepthBuffer);
  glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT24, mirFBSize.x, mirFBSize.y);

  // Initialize mnFramebuffer
  glGenFramebuffersEXT(1, &mnFrameBuffer);
  glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, mnFrameBuffer);
  glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT,
                            GL_TEXTURE_RECTANGLE_ARB, mnFrameBufferTex, 0);

  // Bound mnFrameBuffer and DephtBuffer
  glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT,
                               GL_RENDERBUFFER_EXT, DepthBuffer);
  CheckFramebufferStatus();

  // Unbind framebuffers (bind to 0)
  glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
  cout << "  ARDriver: FBO.allocated" << endl;
}

void ARDriver::DrawFBBackGround() {
  static bool bFirstRun = true;
  static GLuint nList;
  mGLWindow.SetupUnitOrtho();
  
  glEnable(GL_TEXTURE_RECTANGLE_ARB);
  glBindTexture(GL_TEXTURE_RECTANGLE_ARB, mnFrameTex);
  glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glDisable(GL_POLYGON_SMOOTH);
  glDisable(GL_BLEND);
  // Cache the cpu-intesive projections in a display list..
  if(bFirstRun)
  {
    bFirstRun = false;
    nList = glGenLists(1);
    glNewList(nList, GL_COMPILE_AND_EXECUTE);
    glColor3f(1,1,1);
    // How many grid divisions in the x and y directions to use?
    int nStepsX = 24; // Pretty arbitrary..
    int nStepsY = (int) (nStepsX * ((double) mirFrameSize.x / mirFrameSize.y)); // Scaled by aspect ratio
    if(nStepsY < 2)
      nStepsY = 2;
    for(int ystep = 0; ystep< nStepsY; ystep++) {
      glBegin(GL_QUAD_STRIP);
      for(int xstep = 0; xstep <= nStepsX; xstep++)
        for(int yystep = ystep; yystep<=ystep+1; yystep++) { // Two y-coords in one go - magic.
          Vector<2> v2Iter;
          v2Iter[0] = (double) xstep / nStepsX;
          v2Iter[1] = (double) yystep / nStepsY;

          // If this is a border quad, draw a little beyond the
          // outside of the frame, this avoids strange jaggies
          // at the edge of the reconstructed frame later:
          if(xstep == 0 || yystep == 0 || xstep == nStepsX || yystep == nStepsY)
            for(int i=0; i<2; i++)
              v2Iter[i] = v2Iter[i] * 1.02 - 0.01;

          Vector<2> v2UFBDistorted = v2Iter;
          Vector<2> v2UFBUnDistorted = mCamera.UFBLinearProject(mCamera.UFBUnProject(v2UFBDistorted));
          glTexCoord2d(v2UFBDistorted[0] * mirFrameSize.x, v2UFBDistorted[1] * mirFrameSize.y);
          glVertex(v2UFBUnDistorted);
        }
      glEnd();
    }
    glEndList();
  }
  else
    glCallList(nList);
  glDisable(GL_TEXTURE_RECTANGLE_ARB);
}


void ARDriver::DrawDistortedFB()
{
  static bool bFirstRun = true;
  static GLuint nList;
  mGLWindow.SetupViewport();
  mGLWindow.SetupUnitOrtho();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_TEXTURE_RECTANGLE_ARB);
  glBindTexture(GL_TEXTURE_RECTANGLE_ARB, mnFrameBufferTex);
  glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glDisable(GL_POLYGON_SMOOTH);
  glDisable(GL_BLEND);
  if(bFirstRun)
  {
    bFirstRun = false;
    nList = glGenLists(1);
    glNewList(nList, GL_COMPILE_AND_EXECUTE);
    // How many grid divisions in the x and y directions to use?
    int nStepsX = 24; // Pretty arbitrary..
    int nStepsY = (int) (nStepsX * ((double) mirFrameSize.x / mirFrameSize.y)); // Scaled by aspect ratio
    if(nStepsY < 2)
      nStepsY = 2;
    glColor3f(1,1,1);
    for(int ystep = 0; ystep<nStepsY; ystep++)
    {
      glBegin(GL_QUAD_STRIP);
      for(int xstep = 0; xstep<=nStepsX; xstep++)
        for(int yystep = ystep; yystep<=ystep + 1; yystep++) // Two y-coords in one go - magic.
        {
          Vector<2> v2Iter;
          v2Iter[0] = (double) xstep / nStepsX;
          v2Iter[1] = (double) yystep / nStepsY;
          Vector<2> v2UFBDistorted = v2Iter;
          Vector<2> v2UFBUnDistorted = mCamera.UFBLinearProject(mCamera.UFBUnProject(v2UFBDistorted));
          glTexCoord2d(v2UFBUnDistorted[0] * mirFBSize.x, (1.0 - v2UFBUnDistorted[1]) * mirFBSize.y);
          glVertex(v2UFBDistorted);
        }
      glEnd();
    }
    glEndList();
  }
  else
    glCallList(nList);
  glDisable(GL_TEXTURE_RECTANGLE_ARB);
}

void ARDriver::DrawFadingGrid()
{
  double dStrength;
  if(mnCounter >= 60)
    return;
  if(mnCounter < 30)
    dStrength = 1.0;
  dStrength = (60 - mnCounter) / 30.0;
  
  glColor4f(1,1,1,dStrength);
  int nHalfCells = 8;
  if(mnCounter < 8)
    nHalfCells = mnCounter + 1;
  int nTot = nHalfCells * 2 + 1;
  Vector<3>  aaVertex[17][17];
  Vector<3> v3;

  for(int i=0; i<nTot; i++)
    for(int j=0; j<nTot; j++) {
      v3[0] = (i - nHalfCells) * 0.1;
      v3[1] = (j - nHalfCells) * 0.1;
      v3[2] = 0.0;
      aaVertex[i][j] = v3;
    }

  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glLineWidth(2);
  for(int i=0; i<nTot; i++)
  {
    glBegin(GL_LINE_STRIP);
    for(int j=0; j<nTot; j++)
      glVertex(aaVertex[i][j]);
    glEnd();

    glBegin(GL_LINE_STRIP);
    for(int j=0; j<nTot; j++)
      glVertex(aaVertex[j][i]);
    glEnd();
  };
}

// -- Support functions
inline void VectorToFloatArray(const Vector<3> vec_in, float *vec_out) {
  for (int i=0; i<3; ++i)
    vec_out[i] = vec_in[i];
}

static bool CheckFramebufferStatus()  {
  GLenum n;
  n = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);

  if(n == GL_FRAMEBUFFER_COMPLETE_EXT)
    return true; // All good

  cout << "glCheckFrameBufferStatusExt returned an error." << endl;
  return false;
}
