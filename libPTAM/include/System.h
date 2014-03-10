// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited
//
// System.h
//
// Defines the System class
//
// This stores the main functional classes of the system, like the
// mapmaker, map, tracker etc, and spawns the working threads.
//
#ifndef __SYSTEM_H
#define __SYSTEM_H
#include "VideoSource.h"
#include "GLWindow2.h"

#include <cvd/image.h>
#include <cvd/rgb.h>
#include <cvd/byte.h>
#include <boost/thread.hpp>

class ATANCamera;
class Map;
class MapMaker;
class Tracker;
class ARDriver;
class MapViewer;

class System
{
public:
  System();
  void  GetCurrentPose(double *pose) const;
  void  Run();
  void  Stop();
  int   GetCurrentKeyframes();
  int   GetCurrentPoints();
  int   GetDiscardedPoints();
  bool  LoadARModel(std::string model_file);

private:
  VideoSource mVideoSource;
  GLWindow2 mGLWindow;
  CVD::Image<CVD::Rgb<CVD::byte> > mimFrameRGB;
  CVD::Image<CVD::byte> mimFrameBW;
  
  boost::thread *sys_thread;
  Map *mpMap; 
  MapMaker *mpMapMaker; 
  Tracker *mpTracker; 
  ATANCamera *mpCamera;
  ARDriver *mpARDriver;
  MapViewer *mpMapViewer;
  
  bool mbDone;
  bool ARDriver_initialized;
  bool ARDriver_load_pending;
  std::string AR_assets_filename;

  static void GUICommandCallBack(void* ptr, std::string sCommand, std::string sParams);
};



#endif
