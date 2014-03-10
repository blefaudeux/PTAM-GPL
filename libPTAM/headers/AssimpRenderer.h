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

#ifdef _WIN32
#pragma comment(lib,"assimp.lib")
#pragma comment(lib,"devil.lib")
#pragma comment(lib,"glew32.lib")

#endif


// include DevIL for image loading
#include <IL/il.h>

// include GLEW to access OpenGL 3.3 functions
#include <GL/glew.h>

// GLUT is the toolkit to interface with the OS
#include <GL/freeglut.h>

// auxiliary C file to read the shader text files
#include "Textfile.h"

// assimp include files. These three are usually needed.
#include "assimp/Importer.hpp"	//OO version Header!
#include "assimp/postprocess.h"
#include "assimp/scene.h"

#include <math.h>
#include <fstream>
#include <map>
#include <string>
#include <vector>

#define MatricesUniBufferSize sizeof(float) * 16 * 3
#define ProjMatrixOffset 0
#define ViewMatrixOffset sizeof(float) * 16
#define ModelMatrixOffset sizeof(float) * 16 * 2
#define MatrixSize sizeof(float) * 16

#define printOpenGLError() printOglError(__FILE__, __LINE__)

// Information to render each assimp node
struct MyMesh{

	GLuint vao;
	GLuint texIndex;
	GLuint uniformBlockIndex;
	int numFaces;
};

std::vector<struct MyMesh> myMeshes;

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
	// Model Matrix (part of the OpenGL Model View Matrix)
	float modelMatrix[16];

	// For push and pop matrix
	std::vector<float *> matrixStack;

	// Vertex Attribute Locations
	GLuint vertexLoc=0, normalLoc=1, texCoordLoc=2;

	// Uniform Bindings Points
	GLuint matricesUniLoc = 1, materialUniLoc = 2;

	// The sampler uniform for textured models
	// we are assuming a single texture so this will
	//always be texture unit 0
	GLuint texUnit = 0;

	// Uniform Buffer for Matrices
	// this buffer will contain 3 matrices: projection, view and model
	// each matrix is a float array with 16 components
	GLuint matricesUniBuffer;

	// Program and Shader Identifiers
	GLuint program, vertexShader, fragmentShader;

	// Shader Names
	char *vertexFileName = "dirlightdiffambpix.vert";
	char *fragmentFileName = "dirlightdiffambpix.frag";

	// Create an instance of the Importer class
	Assimp::Importer importer;

	// the global Assimp scene object
	const aiScene* scene = NULL;

	// scale factor for the model to fit in the window
	float scaleFactor;


	// images / texture
	// map image filenames to textureIds
	// pointer to texture Array
	std::map<std::string, GLuint> textureIdMap;

	// Replace the model name by your model's filename
	static const std::string modelname = "bench.obj";


	// Camera Position
	float camX = 0, camY = 0, camZ = 5;

	// Mouse Tracking Variables
	int startX, startY, tracking = 0;

	// Camera Spherical Coordinates
	float alpha = 0.0f, beta = 0.0f;
	float r = 5.0f;

#define M_PI       3.14159265358979323846f

	static inline float
	DegToRad(float degrees)
	{
		return (float)(degrees * (M_PI / 180.0f));
	};

	// Frame counting and FPS computation
	long time,timebase = 0,frame = 0;
	char s[32];

	//-----------------------------------------------------------------
	// Support functions :
	static int printOglError(char *file, int line);
	static void crossProduct( float *a, float *b, float *res);
	static void normalize(float *a);

	// ----------------------------------------------------
	// MATRIX STUFF
	//

	// Push and Pop for modelMatrix
	void pushMatrix();
	void popMatrix();

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
	static void setScaleMatrix(float *mat, float sx, float sy, float sz);

	// Defines a transformation matrix mat with a rotation
	// angle alpha and a rotation axis (x,y,z)
	static void setRotationMatrix(float *mat,
																float angle,
																float x,
																float y,
																float z);

	// ----------------------------------------------------
	// Model Matrix
	//
	// Copies the modelMatrix to the uniform buffer
	void setModelMatrix();

	// The equivalent to glTranslate applied to the model matrix
	void translate(float x, float y, float z);

	// The equivalent to glRotate applied to the model matrix
	void rotate(float angle, float x, float y, float z);

	// The equivalent to glScale applied to the model matrix
	void scale(float x, float y, float z);

	// ----------------------------------------------------
	// Projection Matrix
	//
	// Computes the projection Matrix and stores it in the uniform buffer
	void buildProjectionMatrix(float fov,
														 float ratio,
														 float nearp,
														 float farp);

	// ----------------------------------------------------
	// View Matrix
	//
	// Computes the viewMatrix and stores it in the uniform buffer
	//
	// note: it assumes the camera is not tilted,
	// i.e. a vertical up vector along the Y axis (remember gluLookAt?)
	//
	void setCamera(float posX, float posY, float posZ,
								 float lookAtX, float lookAtY, float lookAtZ);
	// ----------------------------------------------------------------------------

#define aisgl_min(x,y) (x<y?x:y)
#define aisgl_max(x,y) (y>x?y:x)

	static void get_bounding_box_for_node (const aiNode* nd,
																				 aiVector3D* min,
																				 aiVector3D* max);

	static void get_bounding_box (aiVector3D* min, aiVector3D* max);

	static void set_float4(float f[4], float a, float b, float c, float d);

	static void color4_to_float4(const aiColor4D *c, float f[4]);

	bool Import3DFromFile( const std::string& pFile);

	int LoadGLTextures(const aiScene* scene);

	void genVAOsAndUniformBuffer(const aiScene *sc);


	// ------------------------------------------------------------
	//
	// Reshape Callback Function
	//
	void changeSize(int w, int h);


	// ------------------------------------------------------------
	//
	// Render stuff
	//

	// Render Assimp Model
	void recursive_render (const aiScene *sc, const aiNode* nd);

	// Rendering Callback Function
	void renderScene(void);


};

