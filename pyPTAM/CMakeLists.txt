# Define the project's name
project(pyPTAM)
cmake_minimum_required(VERSION 2.6)

# Get to know where all the dependencies are..
LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../libPTAM/dependencies)
message("Additional lookup directory:\n ${CMAKE_MODULE_PATH}")

# Add all the files we're interested in (mostly for QTCreator)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Use Boost.python
set(Boost_USE_STATIC_LIBS  OFF)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost REQUIRED)
find_package(Assimp REQUIRED)
find_package(GLEW REQUIRED)
find_package(DevIL REQUIRED)

#find_package(PythonLibs REQUIRED) # Will depend on the Boost version...

# Find Python 2.7 (Boost <1.54)
find_path(PYTHON_INCLUDE_DIR python2.7/Python.h
          HINTS "/usr/include")
set(PYTHON_INCLUDE_DIR ${PYTHON_INCLUDE_DIR}/python2.7)

find_library(PYTHON_LIBRARIES NAMES python2.7 libpython2.7
             HINTS "/usr/lib/x86_64-linux-gnu")

message("\n Python libs : \n ${PYTHON_INCLUDE_DIR}\n ${PYTHON_LIBRARIES}\n")

# Get the PTAM lib and includes:
find_path(PTAM_INCLUDE_DIR PTAM/System.h
          HINTS "/usr/local/include"
          PATH_SUFFIXES PTAM)

set(PTAM_INCLUDE_DIR ${PTAM_INCLUDE_DIR}/PTAM)

find_library(PTAM_LIBRARY NAMES PTAMd libPTAMd
             HINTS "/usr/local/lib")

# Define the included directories
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLUT_INCLUDE_DIRS})
include_directories(${PYTHON_INCLUDE_DIR})
include_directories(${PTAM_INCLUDE_DIR})

message("\nPTAM lib :\n ${PTAM_LIBRARY}\n ${PTAM_INCLUDE_DIR}\n")

find_package(Boost COMPONENTS python thread)
message("\nBoost lib :\n ${Boost_LIBRARIES}\n")

# Set debug or release configurations
if( CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
    message( "INFO: DEBUG BUILD" )
    # for debug type builds, turn on verbose makefiles
    SET(CMAKE_VERBOSE_MAKEFILE ON)

    # Tell other CMake files that we're doing a debug build
    SET( DEBUG_BUILD 1 )

    # Tell C/C++ that we're doing a debug build
    ADD_DEFINITIONS( -DDEBUG )
endif()

if( CMAKE_BUILD_TYPE MATCHES "[Rr][Ee][Ll][Ee][Aa][Ss][Ee]" )
    message( "INFO: RELEASE BUILD" )
endif()

# Create static and dynamic libraries
add_library(pyPTAM SHARED ${SRC})

# Fix the static compilation issue
IF( CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" )
  SET_TARGET_PROPERTIES(pyPTAM PROPERTIES COMPILE_FLAGS "-fPIC")
ENDIF( CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" )

# Set the link libraries :
set(LINK_LIBS ${IL_LIBRARIES} ${ASSIMP_LIBRARIES} ${GLEW_LIBRARIES} ${PTAM_LIBRARY} ${Boost_LIBRARIES} ${CVD_LIBRARIES} ${GVARS3_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${LAPACK_LIBRARIES} ${PYTHON_LIBRARIES})

target_link_libraries(pyPTAM ${LINK_LIBS} )

### Define the installation procedure
install(TARGETS pyPTAM DESTINATION ${PROJECT_SOURCE_DIR}/Python)
