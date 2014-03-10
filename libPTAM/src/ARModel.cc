/*
 * @author : Benjamin Lefaudeux
 * PTAM AR extension to load different OpenGL models as needed.
 *
 * @disclaimer : Some functions are taken straight from ASSIMP sample code. See their repo
 */

#include "ARModel.h"

// Try to use the renderer from Lighthouse3D
#include "l3classimport.cc"

#include "stdio.h"
#include "fstream"

#define aisgl_min(x,y) (x<y?x:y)
#define aisgl_max(x,y) (y>x?y:x)

using namespace TooN;
using namespace CVD;
using namespace std;

ARModel::ARModel() {
  scene = NULL;
  mdModelRadius = 0.1;
  mbInitialised = false;
}

bool ARModel::loadModelFromFile(std::string model_file) {

  // Check if the file exists
  std::ifstream fin(model_file.c_str());
  if (!fin.fail()) {
    fin.close();
  } else {
    printf("Could not open the assets: %s\n", model_file.c_str());
    return false;
  }

  // Load the assets using ASSIMP
  scene = importer.ReadFile(model_file.c_str(), aiProcessPreset_TargetRealtime_MaxQuality);

  if (scene) {
    // Normalize the assets scale
      AssimpRenderer.get_bounding_box(&scene_min, &scene_max);
      // TODO
    scene_center.x = (scene_min.x + scene_max.x) / 2.0f;
    scene_center.y = (scene_min.y + scene_max.y) / 2.0f;
    scene_center.z = (scene_min.z + scene_max.z) / 2.0f;
    return true;
  } else {
      cout << "PTAM::System : could not load " << model_file << endl;
      cout << "PTA:::System : " << importer.GetErrorString() << endl;
    }

  return false;
  // TODO: also load the textures, pictures...
}

void ARModel::Reset() {
  worldFromModel= SE3<>();

  worldFromModel.get_translation()[0] = -mdModelRadius;
  worldFromModel.get_translation()[1] = -mdModelRadius;
  worldFromModel.get_translation()[2] = mdModelRadius;
}

void ARModel::lookAt(Vector<3> v3, double dRotLimit) {
  Vector<3> v3E = worldFromModel.inverse() * v3;

  if(v3E * v3E == 0.0)
    return;

  normalize(v3E);
  Matrix<3> m3Rot = Identity;
  m3Rot[2] = v3E;
  m3Rot[0] -= m3Rot[2]*(m3Rot[0]*m3Rot[2]);
  normalize(m3Rot[0]);
  m3Rot[1] = m3Rot[2] ^ m3Rot[0];

  SO3<> so3Rotator = m3Rot;
  Vector<3> v3Log = so3Rotator.ln();
  v3Log[2] = 0.0;
  double dMagn = sqrt(v3Log * v3Log);
  if(dMagn > dRotLimit)
    {
      v3Log = v3Log * ( dRotLimit / dMagn);
    }
  worldFromModel.get_rotation() = worldFromModel.get_rotation() * SO3<>::exp(-v3Log);
}

void ARModel::draw(Vector<3> v3CamPos) {
  cout << "AR : Draw something" << endl;

  // Update the model position and attitude (Thanks to the SLAM update in camera pose)
  // lookAt(v3CamPos, 0.02);
}
