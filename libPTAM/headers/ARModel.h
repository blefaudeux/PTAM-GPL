#ifndef ARMODEL
#define ARMODEL

/*
 * @author : Benjamin Lefaudeux
 * PTAM AR extension to load different OpenGL models as needed.
 */

#include <TooN/TooN.h>
#include <TooN/se3.h>
#include <stdlib.h>
#include "OpenGL.h"

// Load assets
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


class ARModel
{
public:
  ARModel();
  void Draw(Toon::Vector<3> v3CamPos);
  void loadModelFromFile(std::string model_file);
  void Reset();
  void Init();


private:
  aiScene* scene;
  bool mbInitialised;
  void drawModel();
  std::string model_file;




};

#endif
