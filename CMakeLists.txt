cmake_minimum_required (VERSION 2.6) 
project (PTAM)

# Get to know where all the dependencies are..
LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/libPTAM/dependencies)
message("Additional lookup directory:\n ${CMAKE_MODULE_PATH}")

# Try to find the needed packages
set(Boost_USE_STATIC_LIBS  OFF)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS system thread REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(LAPACK REQUIRED)
find_package(DevIL REQUIRED)

# Recurse into subdirectories. This does not actually 
# cause another cmake executable to run. The same process will walk through 
# the project's entire directory structure.
add_subdirectory(third_party) 		# Third party dependencies
add_subdirectory(libPTAM)		# The mono-SLAM PTAM lib
add_subdirectory(camera_calibrator)	# The application to calibrate cameras
add_subdirectory(demoPTAM)		# A demo application