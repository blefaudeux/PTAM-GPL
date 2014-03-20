//
// Lighthouse3D.com OpenGL 3.3 + GLSL 3.3 Sample
//
// Loading and displaying a Textured Model
//
// Uses:
//  Assimp lybrary for model loading
//		http://assimp.sourceforge.net/
//  Devil for image loading
//		http://openil.sourceforge.net/
//	Uniform Blocks
//  Vertex Array Objects
//
// Some parts of the code are strongly based on the Assimp 
// SimpleTextureOpenGL sample that comes with the Assimp 
// distribution, namely the code that relates to loading the images
// and the model.
//
// The code was updated and modified to be compatible with 
// OpenGL 3.3 CORE version
//
// This demo was built for learning purposes only. 
// Some code could be severely optimised, but I tried to 
// keep as simple and clear as possible.
//
// The code comes with no warranties, use it at your own risk.
// You may use it, or parts of it, wherever you want. 
//
// If you do use it I would love to hear about it. Just post a comment
// at Lighthouse3D.com

// Have Fun :-)

#ifndef ASSIMP_RENDERER
#define ASSIMP_RENDERER

#ifdef _WIN32
#pragma comment(lib,"assimp.lib")
#pragma comment(lib,"devil.lib")
#pragma comment(lib,"glew32.lib")
#endif

// include GLEW to access OpenGL 3.3 functions
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <IL/il.h>

#include "Textfile.h"

// assimp include files. These three are usually needed.
#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"
#include "assimp/scene.h"

#include <math.h>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <iostream>

#define MatricesUniBufferSize sizeof(float) * 16 * 3
#define ProjMatrixOffset 0
#define ViewMatrixOffset sizeof(float) * 16
#define ModelMatrixOffset sizeof(float) * 16 * 2
#define MatrixSize sizeof(float) * 16

#define printOpenGLError() printOglError(__FILE__, __LINE__)

#define aisgl_min(x,y) (x<y?x:y)
#define aisgl_max(x,y) (y>x?y:x)
#ifndef M_PI
#define M_PI  3.14159265358979323846f
#endif

using namespace std;

// Information to render each assimp node
struct MyMesh{
  GLuint vao;
  GLuint texIndex;
  GLuint uniformBlockIndex;
  int numFaces;
};

// This is for a shader uniform block
struct MyMaterial{
  float diffuse[4];
  float ambient[4];
  float specular[4];
  float emissive[4];
  float shininess;
  int texCount;
};

class AssimpRenderer {
public :
  AssimpRenderer(const std::string ARSceneFile);
  ~AssimpRenderer();

  // Support functions :
  static void crossProduct( float *a, float *b, float *res);
  static void normalize(float *a);

  // sets the square matrix mat to the identity matrix,
  // size refers to the number of rows (or columns)
  static void setIdentityMatrix( float *mat, int size);
  static void multMatrix(float *a, float *b);

  // Defines a transformation matrix mat with a translation
  static void setTranslationMatrix(float *mat,
                                   float x,
                                   float y,
                                   float z);

  // Defines a transformation matrix mat with a scale
  static void setScaleMatrix(float *mat,
                             float sx,
                             float sy,
                             float sz);

  // Defines a transformation matrix mat with a rotation
  // angle alpha and a rotation axis (x,y,z)
  static void setRotationMatrix(float *mat,
                                float angle,
                                float x,
                                float y,
                                float z);

  static void set_float4(float f[4], float a, float b, float c, float d);

  static void color4_to_float4(const aiColor4D *c, float f[4]);

  bool  import3DFromFile( const string& pFile);
  bool  init();

  // - render in an external FB
  void  renderSceneToFB(const float *camera_pose);

private: 
  bool handle_matrix_stack;

  // Model Matrix (part of the OpenGL Model View Matrix)
  float modelMatrix[16];

  // For push and pop matrix
  vector<float *> matrixStack;

  // Vertex Attribute Locations
  GLuint vertexLoc, normalLoc, texCoordLoc;

  // Uniform Bindings Points
  GLuint matricesUniLoc, materialUniLoc;

  // The sampler uniform for textured models
  // we are assuming a single texture so this will
  //always be texture unit 0
  GLuint texUnit;

  // Store the meshes
  vector<struct MyMesh> myMeshes;

  // Uniform Buffer for Matrices
  // this buffer will contain 3 matrices: projection, view and model
  // each matrix is a float array with 16 components
  GLuint matricesUniBuffer;

  // Program and Shader Identifiers
  GLuint program, vertexShader, fragmentShader;

  // Create an instance of the Importer class
  Assimp::Importer *importer;

  // the global Assimp scene object
  const aiScene* scene;

  // images / texture
  // map image filenames to textureIds
  // pointer to texture Array
  map<string, GLuint> textureIdMap;

  // Replace the model name by your model's filename
  string modelname;

  // Camera Position & attitude
  float camX, camY, camZ, alpha, beta, r, scaleFactor;

  // Frame counting and FPS computation
  long time,timebase,frame;
  char s[32];

  void get_bounding_box_for_node (const aiNode* nd,
                                  aiVector3D* min,
                                  aiVector3D* max) const;

  void get_bounding_box (aiVector3D* min, aiVector3D* max) const;

  // -- Model matrices operations --
  void pushMatrix(); // Push and Pop for modelMatrices
  void popMatrix();

  void setModelMatrix(); // Copies the modelMatrix to the uniform buffer
  void translate(float x, float y, float z);   // The equivalent to glTranslate applied to the model matrix
  void rotate(float angle, float x, float y, float z);  // The equivalent to glRotate applied to the model matrix
  void scale(float x, float y, float z); // The equivalent to glScale applied to the model matrix

  // Projection Matrix
  // Computes the projection Matrix and stores it in the uniform buffer
  void buildProjectionMatrix(float fov,
                             float ratio,
                             float nearp,
                             float farp);

  // View Matrix
  // Computes the viewMatrix and stores it in the uniform buffer
  // note: it assumes the camera is not tilted,
  // i.e. a vertical up vector along the Y axis (remember gluLookAt?)
  void  setCamera(float posX, float posY, float posZ,
                  float lookAtX, float lookAtY, float lookAtZ);

  GLuint  setupShaders();
  int     loadGLTextures(const aiScene* scene);
  void    genVAOsAndUniformBuffer(const aiScene *sc);

  // Log functions
  static int    printOglError(char *file, int line);
  static void   printShaderInfoLog(GLuint obj);
  static void   printProgramInfoLog(GLuint obj);

  // Rendering methods
  // - render Assimp Model
  void recursiveRender (const aiScene *sc, const aiNode* nd);

  // - rendering Callback Function
  void renderScene(void);
};

#endif

