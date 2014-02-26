cmake_minimum_required (VERSION 2.6) 
project (AR)

# Get to know where all the dependencies are..
LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/libPTAM/dependencies)
message("Additional directory : ${CMAKE_MODULE_PATH}")

# Try to find the needed packages
find_package(Boost REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(LAPACK REQUIRED)
find_package(CVD REQUIRED)
find_package(GVars3 REQUIRED)
find_package(TooN REQUIRED)

message("GVars3 found in: \n ${GVARS3_INCLUDE_DIR} \n ${GVARS3_LIBRARIES}\n")
message("CVD found in: \n ${CVD_INCLUDE_DIR}\n")
message("TooN found in: \n ${TOON_INCLUDE_DIR}\n")

include_directories(${BOOST_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} ${LAPACK_INCLUDE_DIR} ${CVD_INCLUDE_DIR} ${GVARS3_INCLUDE_DIR} ${TOON_INCLUDE_DIR})

# Recurse into the "libPTAM" and "camera_calibrator" subdirectories. This does not actually 
# cause another cmake executable to run. The same process will walk through 
# the project's entire directory structure.
add_subdirectory(libPTAM) 
add_subdirectory(camera_calibrator)
