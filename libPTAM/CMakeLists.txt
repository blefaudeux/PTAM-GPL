# Define the project's name
project(libPTAM)

cmake_minimum_required(VERSION 2.6)

# Add all the files we're interested in (mostly for QTCreator)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/headers/*.h)

# Define the included directories
find_package(Assimp REQUIRED)
find_package(GLEW REQUIRED)
message("Assimp found : \n " ${ASSIMP_LIBRARIES})

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/headers)

# GVars
set(gvars_folder ${PROJECT_SOURCE_DIR}/external_libs/gvars)

include_directories(${gvars_folder}/gvars3)
include_directories(${gvars_folder}/src)
include_directories(${gvars_folder})

file(GLOB SRC_Gvars ${gvars_folder}/src/*.cc)
file(GLOB HEAD_Gvars ${gvars_folder}/src/*.h)

# TooN
set(toon_folder ${PROJECT_SOURCE_DIR}/external_libs/TooN)

include_directories(${toon_folder})

# CVD
set(cvd_folder ${PROJECT_SOURCE_DIR}/external_libs/cvd)

include_directories(${cvd_folder}/cvd_src)
include_directories(${cvd_folder})
file(GLOB SRC_cvd ${gvars_folder}/cvd_src/*.cc)
file(GLOB SRC_cvd_x ${gvars_folder}/cvd_src/*.ccx)
file(GLOB HEAD_cvd ${gvars_folder}/cvd_src/*.h)

# Boost
include_directories(${Boost_INCLUDE_DIRS})

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
add_library(PTAMs STATIC ${SRC} ${SRC_cvd} ${SRC_cvd_x} ${SRC_Gvars} ${HEADERS} ${HEAD_Gvars} ${HEAD_cvd})
add_library(PTAMd SHARED ${SRC} ${SRC_cvd} ${SRC_cvd_x} ${SRC_Gvars} ${HEADERS} ${HEAD_Gvars} ${HEAD_cvd})

# Set the link libraries :
set(LINK_LIBS ${ASSIMP_LIBRARIES} ${IL_LIBRARIES} ${GLEW_LIBRARIES} ${DEVIL_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${LAPACK_LIBRARIES} ${Boost_LIBRARIES} ${ASSIMP_LIBRARIES})

target_link_libraries(PTAMs ${LINK_LIBS})
target_link_libraries(PTAMd ${LINK_LIBS})

### Define the installation procedure
# -- System install (need root credentials)
install(FILES ${HEADERS}  ${HEAD_Gvars} DESTINATION /usr/local/include/PTAM)
install(TARGETS PTAMd PTAMs DESTINATION /usr/local/lib)
