#ifndef ARMODEL
#define ARMODEL

/*
 * @author : Benjamin Lefaudeux
 * PTAM AR extension to load different OpenGL models as needed.
 */

// TODO : Try to use the renderer from Lighthouse3D to tap into the GLWindow
// managed by ARDriver..

#include "AssimpRenderer.h"

#include <TooN/TooN.h>
#include <TooN/se3.h>
#include <stdlib.h>
#include <cvd/convolution.h>
#include <OpenGL.h>

using namespace TooN;

class ARModel
{
public:
  ARModel();
  void draw(Vector<3> v3CamPos);
  bool loadModelFromFile(std::string model_file);
  void Reset();
  void Init();

private:
  bool mbInitialised;
  SE3<> worldFromModel;
  std::string model_file;

  // Scene data :
  double mdModelRadius;
  const aiScene* scene;
  Assimp::Importer importer;
  aiVector3D scene_min, scene_max, scene_center;

  void recursiveRender (const aiScene *sc, const aiNode* nd);
  void getBoundingBox (aiVector3D* min, aiVector3D* max);
  void getBoundingBoxForNode (const aiNode* nd,
                              aiVector3D* min,
                              aiVector3D* max,
                              aiMatrix4x4* trafo);
  void lookAt(Vector<3> v3, double dRotLimit);
};

#endif
