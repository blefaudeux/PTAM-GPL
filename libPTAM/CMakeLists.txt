# Define the project's name
project(libPTAM)

cmake_minimum_required(VERSION 2.6)

# Add all the files we're interested in (mostly for QTCreator)
file(GLOB SRC_PTAM ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB HEAD_PTAM ${PROJECT_SOURCE_DIR}/headers/*.h)

# Define the included directories
find_package(Assimp REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/headers)

# Boost
include_directories(${Boost_INCLUDE_DIRS})

# Global config for third party libs:
include_directories( ../third_party/TooN ../third_party/gvars ../third_party/cvd)

# Set debug or release configurations
if( CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
    message( "INFO: DEBUG BUILD" )
    # for debug type builds, turn on verbose makefiles
    SET(CMAKE_VERBOSE_MAKEFILE ON)

    # Tell other CMake files that we're doing a debug build
    SET(DEBUG_BUILD 1)

    # Tell C/C++ that we're doing a debug build
    ADD_DEFINITIONS(-DDEBUG)
endif()

# Visual studio solutions handling
if(ENABLE_SOLUTION_FOLDERS)
  set_target_properties(libPTAM  PROPERTIES FOLDER "libPTAM")
endif()

if( CMAKE_BUILD_TYPE MATCHES "[Rr][Ee][Ll][Ee][Aa][Ss][Ee]" )
    message( "INFO: RELEASE BUILD" )
endif()

# Create static and dynamic libraries
add_library(PTAMs STATIC ${SRC_PTAM} ${HEAD_PTAM})
add_library(PTAMd SHARED ${SRC_PTAM} ${HEAD_PTAM})

# Set the link libraries :
set(LINK_LIBS ${ASSIMP_LIBRARIES} ${IL_LIBRARIES} ${GLEW_LIBRARIES} ${DEVIL_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${LAPACK_LIBRARIES} ${Boost_LIBRARIES} ${ASSIMP_LIBRARIES})

target_link_libraries(PTAMs ${LINK_LIBS} cvd gvars)
target_link_libraries(PTAMd ${LINK_LIBS} cvd gvars)

### Define the installation procedure
# -- System install (need root credentials)
install(FILES ${HEAD_PTAM} ${HEAD_Gvars} DESTINATION /usr/local/include/PTAM)
install(TARGETS PTAMd PTAMs DESTINATION /usr/local/lib)
