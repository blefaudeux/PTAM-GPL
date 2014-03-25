// -*- c++ *--
// Copyright 2008 Isis Innovation Limited
//
// VideoSource.h
// Declares the VideoSource class
// 
// This is a very simple class to provide video input; this can be
// replaced with whatever form of video input that is needed.  It
// should open the video input on construction, and provide two
// function calls after construction: Size() must return the video
// format as an ImageRef, and GetAndFillFrameBWandRGB should wait for
// a new frame and then overwrite the passed-as-reference images with
// GreyScale and Colour versions of the new frame.
//
#include <cvd/image.h>
#include <cvd/byte.h>
#include <cvd/rgb.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

struct VideoSourceData;

class VideoSource_UDP
{
 public:
  VideoSource_UDP();
  void GetAndFillFrameBWandRGB(CVD::Image<CVD::byte> &imBW, CVD::Image<CVD::Rgb<CVD::byte> > &imRGB);
  CVD::ImageRef Size();
  
 private:
  void *mptr;
  int sockfd,n;
  struct sockaddr_in servaddr,cliaddr;
  char sendline[1000];
  char recvline[1000];

  CVD::ImageRef mirSize;
};
