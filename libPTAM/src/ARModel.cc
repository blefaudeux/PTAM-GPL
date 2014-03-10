/*
 * @author : Benjamin Lefaudeux
 * PTAM AR extension to load different OpenGL models as needed.
 *
 * @disclaimer : Some functions are taken straight from ASSIMP sample code. See their repo
 */

#include "ARModel.h"

#include "stdio.h"
#include "fstream"

#define aisgl_min(x,y) (x<y?x:y)
#define aisgl_max(x,y) (y>x?y:x)

using namespace TooN;
using namespace CVD;

ARModel::ARModel() {
  scene = NULL;
  mdModelRadius = 0.1;
  mbInitialised = false;
}

ARModel::~ARModel() {
  if (scene != NULL) {
    aiReleaseImport(scene);
  }
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
  scene = aiImportFile(model_file.c_str(), aiProcessPreset_TargetRealtime_MaxQuality);

  if (scene) {
    // Normalize the assets scale
    getBoundingBox(&scene_min,&scene_max);
    scene_center.x = (scene_min.x + scene_max.x) / 2.0f;
    scene_center.y = (scene_min.y + scene_max.y) / 2.0f;
    scene_center.z = (scene_min.z + scene_max.z) / 2.0f;
    return true;
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


void ARModel::getBoundingBoxForNode (const aiNode* nd,
                                     aiVector3D* min,
                                     aiVector3D* max,
                                     aiMatrix4x4* trafo){
  aiMatrix4x4 prev;
  unsigned int n = 0, t;

  prev = *trafo;
  aiMultiplyMatrix4(trafo,&nd->mTransformation);

  for (; n < nd->mNumMeshes; ++n) {
    const aiMesh* mesh = scene->mMeshes[nd->mMeshes[n]];
    for (t = 0; t < mesh->mNumVertices; ++t) {

      aiVector3D tmp = mesh->mVertices[t];
      aiTransformVecByMatrix4(&tmp,trafo);

      min->x = aisgl_min(min->x,tmp.x);
      min->y = aisgl_min(min->y,tmp.y);
      min->z = aisgl_min(min->z,tmp.z);

      max->x = aisgl_max(max->x,tmp.x);
      max->y = aisgl_max(max->y,tmp.y);
      max->z = aisgl_max(max->z,tmp.z);
    }
  }

  for (n = 0; n < nd->mNumChildren; ++n) {
    getBoundingBoxForNode(nd->mChildren[n],min,max,trafo);
  }
  *trafo = prev;
}

void ARModel::getBoundingBox(aiVector3D* min, aiVector3D* max)
{
  aiMatrix4x4 trafo;
  aiIdentityMatrix4(&trafo);

  min->x = min->y = min->z =  1e10f;
  max->x = max->y = max->z = -1e10f;
  getBoundingBoxForNode(scene->mRootNode,min,max,&trafo);
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
  glDisable(GL_BLEND);
  glEnable(GL_CULL_FACE);
  glFrontFace(GL_CW);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);
  glEnable(GL_COLOR_MATERIAL);

  // Update the lighting effects
  GLfloat af[4];
  af[0]=0.5; af[1]=0.5; af[2]=0.5; af[3]=1.0;
  glLightfv(GL_LIGHT0, GL_AMBIENT, af);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, af);
  af[0]=1.0; af[1]=0.0; af[2]=1.0; af[3]=0.0;
  glLightfv(GL_LIGHT0, GL_POSITION, af);
  af[0]=1.0; af[1]=1.0; af[2]=1.0; af[3]=1.0;
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, af);
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 50.0);

  // Update the model position and attitude (Thanks to the SLAM update in camera pose)
  this->lookAt(v3CamPos, 0.02);
}
