cmake_minimum_required (VERSION 2.8)
project (PTAM)

# Build options
SET(DEMO         FALSE     CACHE  BOOL    "Build the demo app")
SET(PYTHON_PTAM   FALSE     CACHE  BOOL    "Build the python package")
SET(CAMERA_CALIBRATOR   FALSE     CACHE  BOOL    "A tool to calibrate cameras on the fly")

# Try to find the upfront needed packages
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

# Grab/ build the external libraries
include(ExternalProject)

# Force a build of the dependencies at configuration time
function (build_external_project target prefix url install_script) #FOLLOWING ARGUMENTS are the CMAKE_ARGS of ExternalProject_Add

    set(trigger_build_dir ${CMAKE_BINARY_DIR}/temp_dependency/force_${target})

    #mktemp dir in build tree
    file(MAKE_DIRECTORY ${trigger_build_dir} ${trigger_build_dir}/build)

    #generate false dependency project
    set(CMAKE_LIST_CONTENT "
    cmake_minimum_required(VERSION 2.8)

    include(ExternalProject)
    ExternalProject_add(${target}
            PREFIX ${prefix}
            GIT_REPOSITORY ${url}
            CMAKE_ARGS ${ARGN}
            CONFIGURE_COMMAND chmod +x ${install_script}
            BUILD_COMMAND cd <SOURCE_DIR> && ./configure && make
            INSTALL_COMMAND ${install_script} <SOURCE_DIR> ${prefix}
            )

            add_custom_target(trigger_${target})
            add_dependencies(trigger_${target} ${target})")

    file(WRITE ${trigger_build_dir}/CMakeLists.txt "${CMAKE_LIST_CONTENT}")

    execute_process(COMMAND ${CMAKE_COMMAND} ..
        WORKING_DIRECTORY ${trigger_build_dir}/build
        )
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${trigger_build_dir}/build
        )

endfunction()

build_external_project(toon ${CMAKE_CURRENT_BINARY_DIR}/TooN "https://github.com/edrosten/TooN.git" ${PROJECT_SOURCE_DIR}/install_scripts/toon.sh)

build_external_project(cvd ${CMAKE_CURRENT_BINARY_DIR}/CVD "https://github.com/edrosten/libcvd.git" ${PROJECT_SOURCE_DIR}/install_scripts/cvd.sh)

build_external_project(gvars3 ${CMAKE_CURRENT_BINARY_DIR}/GVars3 "https://github.com/edrosten/gvars.git" ${PROJECT_SOURCE_DIR}/install_scripts/gvars.sh)
add_definitions(-DCVD_HAVE_TOON)

# Dependencies are handled, we can proceed with our actual library
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
    add_dependencies( demoPTAM libPTAM)
    add_subdirectory(pyPTAM)
endif()
