# Define the project's name
project(demoPTAM)

cmake_minimum_required(VERSION 2.6)

# Add all the files we're interested in (mostly for QTCreator)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/headers/*.h)

# Get the GUI and other dependencies
# - Get to know where all the findCMake are
LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../libPTAM/dependencies)
message("Additional lookup directory : ${CMAKE_MODULE_PATH}")

# Try to find the needed packages
set(Boost_USE_STATIC_LIBS  OFF)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS system thread REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(LAPACK REQUIRED)
find_package(CVD REQUIRED)
find_package(GVars3 REQUIRED)
find_package(TooN REQUIRED)
find_package(GLEW REQUIRED)
find_package(Assimp REQUIRED)
find_package(DevIL REQUIRED)

# Get the PTAM lib and includes:
find_path(PTAM_INCLUDE_DIR PTAM/System.h
          HINTS "/usr/local/include"
          PATH_SUFFIXES PTAM)

set (PTAM_INCLUDE_DIR ${PTAM_INCLUDE_DIR}/PTAM)

find_library(PTAM_LIBRARY NAMES PTAMd libPTAMd
             HINTS "/usr/local/lib")

# Define the included directories
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/headers)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLUT_INCLUDE_DIRS})
include_directories(${PTAM_INCLUDE_DIR})


message("\nPTAM lib :\n ${PTAM_LIBRARY}\n ${PTAM_INCLUDE_DIR}\n")

# Set debug or release configurations
if( CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
    message( "INFO: DEBUG BUILD" )
    # for debug type builds, turn on verbose makefiles
    set(CMAKE_VERBOSE_MAKEFILE ON)

    # Tell other CMake files that we're doing a debug build
    set(DEBUG_BUILD 1 )

    # Tell C/C++ that we're doing a debug build
    add_definitions( -DDEBUG )
endif()

if( CMAKE_BUILD_TYPE MATCHES "[Rr][Ee][Ll][Ee][Aa][Ss][Ee]" )
    message( "INFO: RELEASE BUILD" )
endif()

# Set the link libraries :
set(LINK_LIBS ${IL_LIBRARIES} ${ASSIMP_LIBRARIES} ${GLEW_LIBRARIES} ${PTAM_LIBRARY} ${CVD_LIBRARIES} ${GVARS3_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${LAPACK_LIBRARIES}  ${Boost_LIBRARIES})

# Build the executable
message("Source files : ${SRC}")

add_executable(demoPTAM ${SRC})

if( CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" )
  set_target_properties(demoPTAM PROPERTIES COMPILE_FLAGS "-fPIC")
endif( CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" )

target_link_libraries(demoPTAM PTAMs  ${LINK_LIBS})

### Define the installation procedure
#install(TARGETS exe DESTINATION folder)
