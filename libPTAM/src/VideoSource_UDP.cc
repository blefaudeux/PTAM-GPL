#include "VideoSource_UDP.h"
#include <cvd/colourspace_convert.h>
#include <cvd/colourspaces.h>
#include <gvars3/instances.h>


using namespace CVD;
using namespace std;
using namespace GVars3;

#define UDP_SRV_ADDRESS '192.168.1.1'

VideoSource_UDP::VideoSource_UDP()
{
  cout << "  VideoSource_UDP: Opening video stream..." << endl;

  sockfd=socket(AF_INET,SOCK_DGRAM,0);

  bzero(&servaddr,sizeof(servaddr));
  servaddr.sin_family       = AF_INET;
  servaddr.sin_addr.s_addr  = inet_addr(UDP_SRV_ADDRESS);
  servaddr.sin_port         = htons(32000);
}

ImageRef VideoSource::Size()
{
  return mirSize;
}

void VideoSource::GetAndFillFrameBWandRGB(Image<byte> &imBW, Image<Rgb<byte> > &imRGB)
{
  while (fgets(sendline, 10000,stdin) != NULL)  {
    sendto(sockfd,sendline,strlen(sendline),0,
           (struct sockaddr *)&servaddr,sizeof(servaddr));
    n = recvfrom(sockfd,recvline,10000,0,NULL,NULL);
    recvline[n] = 0;
    fputs(recvline,stdout);
  }

  // TODO

  /*
  V4LBuffer<yuv422>* pvb = (V4LBuffer<yuv422>*) mptr;
  VideoFrame<yuv422> *pVidFrame = pvb->get_frame();
  convert_image(*pVidFrame, imBW);
  convert_image(*pVidFrame, imRGB);
  pvb->put_frame(pVidFrame);
  */
}
