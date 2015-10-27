cmake_minimum_required (VERSION 2.8) 
project (PTAM)

# Try to find the needed packages
set(Boost_USE_STATIC_LIBS  OFF)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS system thread REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(LAPACK REQUIRED)

find_package(DevIL REQUIRED)
if(DevIL_NOT_FOUND)
    message("Please install developper Image Library, including ilut")
endif()

# Grab ¹ build the external libraries
include(ExternalProject)

ExternalProject_Add ( dep_toon
       GIT_REPOSITORY "https://github.com/edrosten/TooN.git"
       GIT_TAG "master"
       PREFIX ${CMAKE_CURRENT_BINARY_DIR}/TooN
       UPDATE_COMMAND ""
       CONFIGURE_COMMAND ""
       BUILD_COMMAND cd <SOURCE_DIR> && ./configure && make
       INSTALL_COMMAND "make install PREFIX=${CMAKE_CURRENT_BINARY_DIR}/TooN" )

ExternalProject_Get_Property(dep_toon install_dir)

add_library(TooN STATIC IMPORTED)
set_property(TARGET TooN PROPERTY IMPORTED_LOCATION ${install_dir}/lib/TooN)
add_dependencies(TooN dep_toon)       

ExternalProject_Add ( dep_cvd 
       GIT_REPOSITORY "https://github.com/edrosten/libcvd.git"
       GIT_TAG "master"
       PREFIX ${CMAKE_CURRENT_BINARY_DIR}/CVD
       CONFIGURE_COMMAND ""
       BUILD_COMMAND cd <SOURCE_DIR> && ./configure && make
       INSTALL_COMMAND "make install PREFIX=${CMAKE_CURRENT_BINARY_DIR}/CVD" )

add_library(CVD STATIC IMPORTED)
set_property(TARGET CVD PROPERTY IMPORTED_LOCATION ${install_dir}/lib/CVD)
add_dependencies(CVD dep_cvd)       

ExternalProject_Add ( dep_gvars3 
       GIT_REPOSITORY "https://github.com/edrosten/gvars.git"
       GIT_TAG "master"
       PREFIX ${CMAKE_CURRENT_BINARY_DIR}/GVars3
       CONFIGURE_COMMAND ""
       BUILD_COMMAND cd <SOURCE_DIR> && ./configure && make
       INSTALL_COMMAND "make install PREFIX=${CMAKE_CURRENT_BINARY_DIR}/GVars3" )

add_library(GVars3 STATIC IMPORTED)
set_property(TARGET GVars3 PROPERTY IMPORTED_LOCATION ${install_dir}/lib/GVars3)
add_dependencies(GVars3 dep_gvars3)       

add_subdirectory(libPTAM)

# Build the demo app if needed
if(DEMO)
    add_subdirectory(demoPTAM)
endif()

# Build the camera calibration gui if needed
if(CAMERA_CALIBRATOR)
    add_subdirectory(camera_calibrator)
endif()

# Add the python bindings if needed
if(PYTHON_PTAM)
    add_subdirectory(pyPTAM)
endif()
