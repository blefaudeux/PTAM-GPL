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


#ifdef _WIN32
#pragma comment(lib,"assimp.lib")
#pragma comment(lib,"devil.lib")
#pragma comment(lib,"glew32.lib")
#endif

#include "AssimpRenderer.h"

static inline float DegToRad(float degrees) {
  return (float)(degrees * (M_PI / 180.0f));
}

AssimpRenderer::AssimpRenderer(const std::string ARSceneFile) {
  // Vertex Attribute Locations
  vertexLoc=0;
  normalLoc=1;
  texCoordLoc=2;

  // Uniform Bindings Points
  matricesUniLoc = 1;
  materialUniLoc = 2;

  // The sampler uniform for textured models
  // we are assuming a single texture so this will
  //always be texture unit 0
  texUnit = 0;

  // the global Assimp scene object
  scene = NULL;

  // Camera Position
  camX = 0, camY = 0, camZ = 5;

  // Camera Spherical Coordinates
  alpha = 0.0f, beta = 0.0f;
  r = 5.0f;

  // Frame counting and FPS computation
  timebase = 0,frame = 0;

  // Set the object to load :
  modelname = ARSceneFile;
  importer = new Assimp::Importer();
}

AssimpRenderer::~AssimpRenderer()
{
  // cleaning up
  textureIdMap.clear();

  // clear myMeshes stuff
  for (unsigned int i = 0; i < myMeshes.size(); ++i) {

    glDeleteVertexArrays(1,&(myMeshes[i].vao));
    glDeleteTextures(1,&(myMeshes[i].texIndex));
    glDeleteBuffers(1,&(myMeshes[i].uniformBlockIndex));
  }
  // delete buffers
  glDeleteBuffers(1,&matricesUniBuffer);
}

// Setup
void AssimpRenderer::buildProjectionMatrix(float fov, float ratio, float nearp, float farp) {

  float projMatrix[16];

  float f = 1.0f / tan (fov * (M_PI / 360.0f));

  setIdentityMatrix(projMatrix,4);

  projMatrix[0] = f / ratio;
  projMatrix[1 * 4 + 1] = f;
  projMatrix[2 * 4 + 2] = (farp + nearp) / (nearp - farp);
  projMatrix[3 * 4 + 2] = (2.0f * farp * nearp) / (nearp - farp);
  projMatrix[2 * 4 + 3] = -1.0f;
  projMatrix[3 * 4 + 3] = 0.0f;

  glBindBuffer(GL_UNIFORM_BUFFER,matricesUniBuffer);
  glBufferSubData(GL_UNIFORM_BUFFER, ProjMatrixOffset, MatrixSize, projMatrix);
  glBindBuffer(GL_UNIFORM_BUFFER,0);
}


void AssimpRenderer::crossProduct( float *a, float *b, float *res) {

  res[0] = a[1] * b[2]  -  b[1] * a[2];
  res[1] = a[2] * b[0]  -  b[2] * a[0];
  res[2] = a[0] * b[1]  -  b[0] * a[1];
}

// Model loading and OpenGL setup
bool AssimpRenderer::init()
{
  // Load a model if needed
  if (modelname.empty()) {
    cout << "AssimpRenderer: No model defined, quitting" << endl;
    return false;
  }

  import3DFromFile(modelname); // defines Assimp "scene"
  loadGLTextures(scene);
  cout << "AssimpRenderer: Model loaded" << endl;

  program = setupShaders();
  genVAOsAndUniformBuffer(scene); // Generate Vertex Arrays Objects and buffers

  glEnable(GL_DEPTH_TEST);
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

  glGenBuffers(1,&matricesUniBuffer);
  glBindBuffer(GL_UNIFORM_BUFFER, matricesUniBuffer);
  glBufferData(GL_UNIFORM_BUFFER, MatricesUniBufferSize,NULL,GL_DYNAMIC_DRAW);
  glBindBufferRange(GL_UNIFORM_BUFFER, matricesUniLoc, matricesUniBuffer, 0, MatricesUniBufferSize);
  glBindBuffer(GL_UNIFORM_BUFFER,0);
  glEnable(GL_MULTISAMPLE);

  cout << "AssimpRenderer: Initialized" << endl;
  return true;
}


void AssimpRenderer::genVAOsAndUniformBuffer(const aiScene *sc) {
  struct MyMesh aMesh;
  struct MyMaterial aMat;
  GLuint buffer;

  // For each mesh
  for (unsigned int n = 0; n < sc->mNumMeshes; ++n)
  {
    const aiMesh* mesh = sc->mMeshes[n];

    // create array with faces
    // have to convert from Assimp format to array
    unsigned int *faceArray;
    faceArray = (unsigned int *)malloc(sizeof(unsigned int) * mesh->mNumFaces * 3);
    unsigned int faceIndex = 0;

    for (unsigned int t = 0; t < mesh->mNumFaces; ++t) {
      const aiFace* face = &mesh->mFaces[t];

      memcpy(&faceArray[faceIndex], face->mIndices,3 * sizeof(unsigned int));
      faceIndex += 3;
    }
    aMesh.numFaces = sc->mMeshes[n]->mNumFaces;

    // generate Vertex Array for mesh
    glGenVertexArrays(1,&(aMesh.vao));
    glBindVertexArray(aMesh.vao);

    // buffer for faces
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * mesh->mNumFaces * 3, faceArray, GL_STATIC_DRAW);

    // buffer for vertex positions
    if (mesh->HasPositions()) {
      glGenBuffers(1, &buffer);
      glBindBuffer(GL_ARRAY_BUFFER, buffer);
      glBufferData(GL_ARRAY_BUFFER, sizeof(float)*3*mesh->mNumVertices, mesh->mVertices, GL_STATIC_DRAW);
      glEnableVertexAttribArray(vertexLoc);
      glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, 0, 0, 0);
    }

    // buffer for vertex normals
    if (mesh->HasNormals()) {
      glGenBuffers(1, &buffer);
      glBindBuffer(GL_ARRAY_BUFFER, buffer);
      glBufferData(GL_ARRAY_BUFFER, sizeof(float)*3*mesh->mNumVertices, mesh->mNormals, GL_STATIC_DRAW);
      glEnableVertexAttribArray(normalLoc);
      glVertexAttribPointer(normalLoc, 3, GL_FLOAT, 0, 0, 0);
    }

    // buffer for vertex texture coordinates
    if (mesh->HasTextureCoords(0)) {
      float *texCoords = (float *)malloc(sizeof(float)*2*mesh->mNumVertices);
      for (unsigned int k = 0; k < mesh->mNumVertices; ++k) {

        texCoords[k*2]   = mesh->mTextureCoords[0][k].x;
        texCoords[k*2+1] = mesh->mTextureCoords[0][k].y;

      }
      glGenBuffers(1, &buffer);
      glBindBuffer(GL_ARRAY_BUFFER, buffer);
      glBufferData(GL_ARRAY_BUFFER, sizeof(float)*2*mesh->mNumVertices, texCoords, GL_STATIC_DRAW);
      glEnableVertexAttribArray(texCoordLoc);
      glVertexAttribPointer(texCoordLoc, 2, GL_FLOAT, 0, 0, 0);
    }

    // unbind buffers
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

    // create material uniform buffer
    aiMaterial *mtl = sc->mMaterials[mesh->mMaterialIndex];

    aiString texPath;	//contains filename of texture
    if(AI_SUCCESS == mtl->GetTexture(aiTextureType_DIFFUSE, 0, &texPath)){
      //bind texture
      unsigned int texId = textureIdMap[texPath.data];
      aMesh.texIndex = texId;
      aMat.texCount = 1;
    }
    else
      aMat.texCount = 0;

    float c[4];
    set_float4(c, 0.8f, 0.8f, 0.8f, 1.0f);
    aiColor4D diffuse;
    if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse))
      color4_to_float4(&diffuse, c);
    memcpy(aMat.diffuse, c, sizeof(c));

    set_float4(c, 0.2f, 0.2f, 0.2f, 1.0f);
    aiColor4D ambient;
    if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_AMBIENT, &ambient))
      color4_to_float4(&ambient, c);
    memcpy(aMat.ambient, c, sizeof(c));

    set_float4(c, 0.0f, 0.0f, 0.0f, 1.0f);
    aiColor4D specular;
    if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_SPECULAR, &specular))
      color4_to_float4(&specular, c);
    memcpy(aMat.specular, c, sizeof(c));

    set_float4(c, 0.0f, 0.0f, 0.0f, 1.0f);
    aiColor4D emission;
    if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_EMISSIVE, &emission))
      color4_to_float4(&emission, c);
    memcpy(aMat.emissive, c, sizeof(c));

    float shininess = 0.0;
    unsigned int max;
    aiGetMaterialFloatArray(mtl, AI_MATKEY_SHININESS, &shininess, &max);
    aMat.shininess = shininess;

    glGenBuffers(1,&(aMesh.uniformBlockIndex));
    glBindBuffer(GL_UNIFORM_BUFFER,aMesh.uniformBlockIndex);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(aMat), (void *)(&aMat), GL_STATIC_DRAW);

    myMeshes.push_back(aMesh);
  }
}


// Parse the Model file
bool AssimpRenderer::import3DFromFile(const std::string& pFile) {

  //check if file exists
  std::ifstream fin(pFile.c_str());
  if(!fin.fail()) {
    fin.close();
  } else{
    cout << "Couldn't open file: "<< pFile.c_str() << endl;
    cout << importer->GetErrorString() << endl;
    return false;
  }

  // Import the scene using Assimp C++ API
  scene = importer->ReadFile(pFile, aiProcessPreset_TargetRealtime_Quality);
  cout << "AssimpRenderer : Scene " << pFile << " import is OK" << endl;

  // If the import failed, report it
  if( !scene) {
    cout << importer->GetErrorString() << endl;
    return false;
  }

  // Now we can access the file's contents.
  aiVector3D scene_min, scene_max;
  get_bounding_box(&scene_min, &scene_max);
  float tmp;
  tmp = scene_max.x-scene_min.x;
  cout << "AssimpRenderer : Model scale " << tmp << endl;
  tmp = scene_max.y - scene_min.y > tmp?scene_max.y - scene_min.y:tmp;
  tmp = scene_max.z - scene_min.z > tmp?scene_max.z - scene_min.z:tmp;
  scaleFactor = 1.f / tmp;

  // We're done. Everything will be cleaned up by the importer destructor
  return true;
}

int AssimpRenderer::loadGLTextures(const aiScene* scene)
{
  ILboolean success;

  /* initialization of DevIL */
  ilInit();

  /* scan scene's materials for textures */
  for (unsigned int m=0; m<scene->mNumMaterials; ++m)   {
    int texIndex = 0;
    aiString path;
    aiReturn texFound = scene->mMaterials[m]->GetTexture(aiTextureType_DIFFUSE, texIndex, &path);

    while (texFound == AI_SUCCESS) {
      //fill map with textures, OpenGL image ids set to 0
      textureIdMap[path.data] = 0;
      // more textures?
      texIndex++;
      texFound = scene->mMaterials[m]->GetTexture(aiTextureType_DIFFUSE, texIndex, &path);
    }
  }

  int numTextures = textureIdMap.size();
  cout << "AssimpRenderer : loaded " << numTextures << " textures." << endl;

  /* create and fill array with DevIL texture ids */
  ILuint* imageIds = new ILuint[numTextures];
  ilGenImages(numTextures, imageIds);

  /* create and fill array with GL texture ids */
  GLuint* textureIds = new GLuint[numTextures];
  glGenTextures(numTextures, textureIds); /* Texture name generation */

  /* get iterator */
  std::map<std::string, GLuint>::iterator itr = textureIdMap.begin();
  int i=0;
  for (; itr != textureIdMap.end(); ++i, ++itr)
  {
    //save IL image ID
    std::string filename = (*itr).first;  // get filename
    (*itr).second = textureIds[i];        // save texture id for filename in map

    ilBindImage(imageIds[i]); /* Binding of DevIL image name */
    ilEnable(IL_ORIGIN_SET);
    ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
    success = ilLoadImage((ILstring)filename.c_str());

    if (success) {
      /* Convert image to RGBA */
      ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

      /* Create and load textures to OpenGL */
      glBindTexture(GL_TEXTURE_2D, textureIds[i]);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ilGetInteger(IL_IMAGE_WIDTH),
                   ilGetInteger(IL_IMAGE_HEIGHT), 0, GL_RGBA, GL_UNSIGNED_BYTE,
                   ilGetData());
    }
    else
      printf("Couldn't load Image: %s\n", filename.c_str());
  }
  /* Because we have already copied image data into texture data
    we can release memory used by image. */
  ilDeleteImages(numTextures, imageIds);

  //Cleanup
  delete [] imageIds;
  delete [] textureIds;

  //return success;
  return true;
}

// Handle the matrix stack (modelview)
void AssimpRenderer::pushMatrix() {
  float *aux = (float *)malloc(sizeof(float) * 16);
  memcpy(aux, modelMatrix, sizeof(float) * 16);
  matrixStack.push_back(aux);
}

void AssimpRenderer::popMatrix() {
  float *m = matrixStack[matrixStack.size()-1];
  memcpy(modelMatrix, m, sizeof(float) * 16);
  matrixStack.pop_back();
  free(m);
}

void AssimpRenderer::setIdentityMatrix( float *mat,
                                        int size) {
  // fill matrix with 0s
  for (int i = 0; i < size * size; ++i)
    mat[i] = 0.0f;

  // fill diagonal with 1s
  for (int i = 0; i < size; ++i)
    mat[i + i * size] = 1.0f;
}

// Defines a transformation matrix mat with a translation
void AssimpRenderer::setTranslationMatrix(float *mat,
                                          float x,
                                          float y,
                                          float z) {
  setIdentityMatrix(mat,4);
  mat[12] = x;
  mat[13] = y;
  mat[14] = z;
}

// Defines a transformation matrix mat with a scale
void AssimpRenderer::setScaleMatrix(float *mat,
                                    float sx,
                                    float sy,
                                    float sz) {
  setIdentityMatrix(mat,4);
  mat[0] = sx;
  mat[5] = sy;
  mat[10] = sz;
}

// Defines a transformation matrix mat with a rotation
// angle alpha and a rotation axis (x,y,z)
void AssimpRenderer::setRotationMatrix(float *mat, float angle,
                                       float x, float y, float z) {
  float radAngle = DegToRad(angle);
  float co = cos(radAngle);
  float si = sin(radAngle);
  float x2 = x*x;
  float y2 = y*y;
  float z2 = z*z;

  mat[0] = x2 + (y2 + z2) * co;
  mat[4] = x * y * (1 - co) - z * si;
  mat[8] = x * z * (1 - co) + y * si;
  mat[12]= 0.0f;

  mat[1] = x * y * (1 - co) + z * si;
  mat[5] = y2 + (x2 + z2) * co;
  mat[9] = y * z * (1 - co) - x * si;
  mat[13]= 0.0f;

  mat[2] = x * z * (1 - co) - y * si;
  mat[6] = y * z * (1 - co) + x * si;
  mat[10]= z2 + (x2 + y2) * co;
  mat[14]= 0.0f;

  mat[3] = 0.0f;
  mat[7] = 0.0f;
  mat[11]= 0.0f;
  mat[15]= 1.0f;
}

// Render Assimp Model
void AssimpRenderer::recursiveRender (const aiScene *sc,
                                      const aiNode* nd)
{
  // Get node transformation matrix
  aiMatrix4x4 m = nd->mTransformation;

  m.Transpose();    // OpenGL matrices are column major
  pushMatrix();     // save model matrix and apply node transformation

  float aux[16];
  memcpy(aux,&m,sizeof(float) * 16);
  multMatrix(modelMatrix, aux);
  setModelMatrix();


  // Draw all meshes assigned to this node
  for (unsigned int n=0; n < nd->mNumMeshes; ++n){
    // Bind material uniform
    glBindBufferRange(GL_UNIFORM_BUFFER, materialUniLoc,
                      myMeshes[nd->mMeshes[n]].uniformBlockIndex, 0, sizeof(struct MyMaterial));
    // Bind texture
    glBindTexture(GL_TEXTURE_2D, myMeshes[nd->mMeshes[n]].texIndex);

    // Bind VAO
    glBindVertexArray(myMeshes[nd->mMeshes[n]].vao);

    // Draw
    glDrawElements(GL_TRIANGLES,myMeshes[nd->mMeshes[n]].numFaces*3,GL_UNSIGNED_INT,0);
  }

  // draw all children
  for (unsigned int n=0; n < nd->mNumChildren; ++n){
    recursiveRender(sc, nd->mChildren[n]);
  }
  popMatrix();
}


// Rendering Callback Function
void AssimpRenderer::renderScene(void) {

  float step = 0.0f;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // set camera matrix
  setCamera(camX,camY,camZ,0,0,0);

  // set the model matrix to the identity Matrix
  setIdentityMatrix(modelMatrix,4);

  // sets the model matrix to a scale matrix so that the model fits in the window
  scale(scaleFactor, scaleFactor, scaleFactor);

  // keep rotating the model
  rotate(step, 0.0f, 1.0f, 0.0f);

  // use our shader
  glUseProgram(program);

  // we are only going to use texture unit 0
  // unfortunately samplers can't reside in uniform blocks
  // so we have set this uniform separately
  glUniform1i(texUnit,0);

  recursiveRender(scene, scene->mRootNode);

  // FPS computation and display
  frame++;
  time=glutGet(GLUT_ELAPSED_TIME);
  if (time - timebase > 1000) {
    sprintf(s,"FPS:%4.2f",
            frame*1000.0/(time-timebase));
    timebase = time;
    frame = 0;
    glutSetWindowTitle(s);
  }

  // swap buffers
  glutSwapBuffers();
}

/*
 * WARNING : This opengl rendering stack crushes previous definitions of :
 * - model view
 * - projection matrix
 * - camera matrix
 */
void AssimpRenderer::renderSceneToFB(const float *camera_pose) {

  glEnable(GL_DEPTH_TEST);

  // Set up the camera position, 'old style'
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(-camera_pose[0], -camera_pose[1], -camera_pose[2]);
  glScalef(scaleFactor, scaleFactor, scaleFactor);
  glRotatef(90.f, 1.0, 0.0, 0.0);
  glRotatef(180.f, 0.0, 1.0, 0.0);

  // FIXME : Still an issue with the translation of the modelview (?)
  glGetFloatv(GL_MODELVIEW_MATRIX, modelMatrix);
  pushMatrix();
  scale(scaleFactor, scaleFactor, scaleFactor);
  setModelMatrix();

  float pm[16];
  glGetFloatv(GL_PROJECTION_MATRIX, pm);
  glBindBuffer(GL_UNIFORM_BUFFER,matricesUniBuffer);
  glBufferSubData(GL_UNIFORM_BUFFER, ProjMatrixOffset, MatrixSize, pm);
  glBindBuffer(GL_UNIFORM_BUFFER,0);

  float vm[16];
  setIdentityMatrix(vm,4);
  glBindBuffer(GL_UNIFORM_BUFFER, matricesUniBuffer);
  glBufferSubData(GL_UNIFORM_BUFFER, ViewMatrixOffset, MatrixSize, vm);
  glBindBuffer(GL_UNIFORM_BUFFER,0);

  // Render all the models' nodes
  glUseProgram(program);
  glUniform1i(texUnit,0); // FIXME: possible issue with the textures, no rendering..

  if (NULL != scene) {
    recursiveRender(scene, scene->mRootNode);
  } else {
    cout << "AssimpRenderer: no model to display" << endl;
  }

  glUseProgram(0);      // Stop using the shaders
  glBindVertexArray(0); // Unbind VBA
}


GLuint AssimpRenderer::setupShaders() {
  char *vs = NULL,*fs = NULL,*fs2 = NULL;

  GLuint p,v,f;

  v = glCreateShader(GL_VERTEX_SHADER);
  f = glCreateShader(GL_FRAGMENT_SHADER);

  // TODO: Handle automatically the opengl capabilities of the platform
  // OpengGL 2
  static const std::string vertexShaderFile = "dirLightAmbDiffSpec.vert";
  static const std::string fragmentShaderFile = "dirLightAmbDiffSpec.frag";
  handle_matrix_stack = false;

//  // OpenGL 3,3 and above
//  static const std::string vertexShaderFile = "dirlightdiffambpix.vert";
//  static const std::string fragmentShaderFile = "dirlightdiffambpix.frag";

//  // Custom shaders
//  static const std::string vertexShaderFile = "vertexShader.vert";
//  static const std::string fragmentShaderFile = "fragmentShader.frag";
  handle_matrix_stack = false;

  vs = textFileRead(vertexShaderFile.c_str());
  fs = textFileRead(fragmentShaderFile.c_str());

  const char * vv = vs;
  const char * ff = fs;

  glShaderSource(v, 1, &vv,NULL);
  glShaderSource(f, 1, &ff,NULL);

  free(vs);
  free(fs);

  glCompileShader(v);
  std::string title_str = "AssimpRenderer";
  const char *title = title_str.c_str();
  printOglError(title, 711);

  glCompileShader(f);
  printOglError(title, 714);

  cout << "Shader info : " << endl;
  printShaderInfoLog(v);
  printShaderInfoLog(f);
  cout << "-----" << endl;

  p = glCreateProgram();
  glAttachShader(p,v);
  glAttachShader(p,f);

  glBindFragDataLocation(p, 0, "output");

  glBindAttribLocation(p,vertexLoc,"position");
  glBindAttribLocation(p,normalLoc,"normal");
  glBindAttribLocation(p,texCoordLoc,"texCoord");

  // Bind Material uniform buffer ?
//  GLint glGetUniformLocation(GLuint program, const char *name);
  glBindAttribLocation (p, 0, "materialUniLoc");
// DEBUG

  glLinkProgram(p);
  glValidateProgram(p);
  printProgramInfoLog(p);

  program = p;
  vertexShader = v;
  fragmentShader = f;

  GLuint k = glGetUniformBlockIndex(p,"Matrices");
  glUniformBlockBinding(p, k, matricesUniLoc);
  glUniformBlockBinding(p, glGetUniformBlockIndex(p,"Material"), materialUniLoc);

  texUnit = glGetUniformLocation(p,"texUnit");

  cout << "AssimpRenderer: Shaders loaded"  << endl;
  return(p);
}

// MODEL MATRIX
//
void AssimpRenderer::rotate(float angle, float x, float y, float z) {
  float aux[16];
  setRotationMatrix(aux,angle,x,y,z);
  multMatrix(modelMatrix,aux);
  setModelMatrix();
}

void AssimpRenderer::scale(float x, float y, float z) {
  float aux[16];
  setScaleMatrix(aux,x,y,z);
  multMatrix(modelMatrix,aux);
  setModelMatrix();
}

void AssimpRenderer::setModelMatrix() {
  glBindBuffer(GL_UNIFORM_BUFFER,matricesUniBuffer);
  glBufferSubData(GL_UNIFORM_BUFFER,
                  ModelMatrixOffset, MatrixSize, modelMatrix);
  glBindBuffer(GL_UNIFORM_BUFFER,0);
}

void AssimpRenderer::setCamera(float posX, float posY, float posZ,
                               float lookAtX, float lookAtY, float lookAtZ) {

  float dir[3], right[3], up[3];

  up[0] = 0.0f;	up[1] = 1.0f;	up[2] = 0.0f;

  dir[0] =  (lookAtX - posX);
  dir[1] =  (lookAtY - posY);
  dir[2] =  (lookAtZ - posZ);
  normalize(dir);

  crossProduct(dir,up,right);
  normalize(right);

  crossProduct(right,dir,up);
  normalize(up);

  float viewMatrix[16],aux[16];

  viewMatrix[0]  = right[0];
  viewMatrix[4]  = right[1];
  viewMatrix[8]  = right[2];
  viewMatrix[12] = 0.0f;

  viewMatrix[1]  = up[0];
  viewMatrix[5]  = up[1];
  viewMatrix[9]  = up[2];
  viewMatrix[13] = 0.0f;

  viewMatrix[2]  = -dir[0];
  viewMatrix[6]  = -dir[1];
  viewMatrix[10] = -dir[2];
  viewMatrix[14] =  0.0f;

  viewMatrix[3]  = 0.0f;
  viewMatrix[7]  = 0.0f;
  viewMatrix[11] = 0.0f;
  viewMatrix[15] = 1.0f;

  setTranslationMatrix(aux, -posX, -posY, -posZ);

  multMatrix(viewMatrix, aux);

  glBindBuffer(GL_UNIFORM_BUFFER, matricesUniBuffer);
  glBufferSubData(GL_UNIFORM_BUFFER, ViewMatrixOffset, MatrixSize, viewMatrix);
  glBindBuffer(GL_UNIFORM_BUFFER,0);
}

void AssimpRenderer::translate(float x, float y, float z) {
  float aux[16];
  setTranslationMatrix(aux,x,y,z);
  multMatrix(modelMatrix,aux);
  setModelMatrix();
}

// -- Support functions
void AssimpRenderer::color4_to_float4(const aiColor4D *c,
                                      float f[4]) {
  f[0] = c->r;
  f[1] = c->g;
  f[2] = c->b;
  f[3] = c->a;
}

void AssimpRenderer::get_bounding_box_for_node (const aiNode* nd,
                                                aiVector3D* min,
                                                aiVector3D* max) const {
  aiMatrix4x4 prev;
  unsigned int n = 0, t;

  for (; n < nd->mNumMeshes; ++n) {
    const aiMesh* mesh = scene->mMeshes[nd->mMeshes[n]];
    for (t = 0; t < mesh->mNumVertices; ++t) {

      aiVector3D tmp = mesh->mVertices[t];

      min->x = aisgl_min(min->x,tmp.x);
      min->y = aisgl_min(min->y,tmp.y);
      min->z = aisgl_min(min->z,tmp.z);

      max->x = aisgl_max(max->x,tmp.x);
      max->y = aisgl_max(max->y,tmp.y);
      max->z = aisgl_max(max->z,tmp.z);
    }
  }

  for (n = 0; n < nd->mNumChildren; ++n) {
    get_bounding_box_for_node(nd->mChildren[n],min,max);
  }
}

void AssimpRenderer::get_bounding_box (aiVector3D* min, aiVector3D* max) const{
  min->x = min->y = min->z =  1e10f;
  max->x = max->y = max->z = -1e10f;
  get_bounding_box_for_node(scene->mRootNode,min,max);
}

// Not quite optimal... recode with GLM lib ?
void AssimpRenderer::multMatrix(float *a,
                                float *b) {
  float res[16];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      res[j*4 + i] = 0.0f;
      for (int k = 0; k < 4; ++k) {
        res[j*4 + i] += a[k*4 + i] * b[j*4 + k];
      }
    }
  }
  memcpy(a, res, 16 * sizeof(float));
}

void AssimpRenderer::normalize(float *a) {

  float mag = sqrt(a[0] * a[0]  +  a[1] * a[1]  +  a[2] * a[2]);

  a[0] /= mag;
  a[1] /= mag;
  a[2] /= mag;
}

void AssimpRenderer::set_float4(float f[4], float a, float b, float c, float d) {
  f[0] = a;
  f[1] = b;
  f[2] = c;
  f[3] = d;
}

// -- Print logs.. --
void AssimpRenderer::printShaderInfoLog(GLuint obj)
{
  int infologLength = 0, charsWritten  = 0;
  char *infoLog;

  glGetShaderiv(obj, GL_INFO_LOG_LENGTH,&infologLength);

  if (infologLength > 0)  {
    infoLog = (char *)malloc(infologLength);
    glGetShaderInfoLog(obj, infologLength, &charsWritten, infoLog);
    printf("%s\n",infoLog);
    free(infoLog);
  } else {
    std::cout << "AssimpRenderer : Could not load shader" << endl;
  }
}

int AssimpRenderer::printOglError(const char *file,
                                  int line)
{
  GLenum glErr;
  int    retCode = 0;

  glErr = glGetError();
  if (glErr != GL_NO_ERROR)
  {
    printf("glError in file %s @ line %d: %s\n",
           file, line, gluErrorString(glErr));
    retCode = 1;
  }
  return retCode;
}

void AssimpRenderer::printProgramInfoLog(GLuint obj)
{
  int infologLength = 0, charsWritten  = 0;
  char *infoLog;

  glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &infologLength);

  if (infologLength > 0)
  {
    infoLog = (char *)malloc(infologLength);
    glGetProgramInfoLog(obj, infologLength, &charsWritten, infoLog);
    printf("%s\n",infoLog);
    free(infoLog);
  }
}
