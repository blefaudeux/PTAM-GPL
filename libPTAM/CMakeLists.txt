# Define the project's name
project(libPTAM)

cmake_minimum_required(VERSION 2.6)

# Add all the files we're interested in (mostly for QTCreator)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/headers/*.h)

# Define the external dependencies
find_package(Assimp REQUIRED)
find_package(GLEW REQUIRED)

# Those are internal, present in the build directory
# -- CVD
find_path(CVD_INCLUDE_DIR cvd/abs.h
          HINTS ${PROJECT_BINARY_DIR}/../CVD )

find_library(CVD_LIBRARY NAMES cvd libcvd
             HINTS ${PROJECT_BINARY_DIR}/../CVD
             PATH_SUFFIXES lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(libcvd  DEFAULT_MSG
                                  CVD_LIBRARY CVD_INCLUDE_DIR)
set(CVD_LIBRARIES ${CVD_LIBRARY} )
set(CVD_INCLUDE_DIRS ${CVD_INCLUDE_DIR} )

message("CVD include : " ${CVD_INCLUDE_DIR})

mark_as_advanced(CVD_INCLUDE_DIR CVD_LIBRARY )

# -- GVars3
find_path(GVARS3_INCLUDE_DIR gvars3/GUI.h
          HINTS ${PROJECT_BINARY_DIR}/../GVars3 )

find_library(GVARS3_LIBRARY NAMES GVars3 libGVars3
             HINTS ${PROJECT_BINARY_DIR}/../GVars3
             PATH_SUFFIXES lib)

set(GVARS3_LIBRARIES ${GVARS3_LIBRARY} )
set(GVARS3_INCLUDE_DIRS ${GVARS3_INCLUDE_DIR} )
find_package_handle_standard_args(GVars3  DEFAULT_MSG
                                  GVARS3_LIBRARY GVARS3_INCLUDE_DIR)
mark_as_advanced(GVARS3_INCLUDE_DIR GVARS3_LIBRARY )

# -- TooN
# Include dir
find_path(TOON_INCLUDE_DIR
  NAMES TooN/TooN.h
  HINTS ${PROJECT_BINARY_DIR}/../TooN
)

# Handle a plural naming..             
set(TOON_INCLUDE_DIRS ${TOON_INCLUDE_DIR} )
find_package_handle_standard_args(TooN  DEFAULT_MSG TOON_INCLUDE_DIR)
                                  
mark_as_advanced(TOON_INCLUDE_DIR)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/headers)
include_directories(${Boost_INCLUDE_DIRS} ${CVD_INCLUDE_DIR} ${TOON_INCLUDE_DIR} ${GVARS3_INCLUDE_DIR})

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
add_library (PTAMs STATIC ${SRC} ${HEADERS})
add_library (PTAMd SHARED ${SRC} ${HEADERS})

# Set the link libraries :
set(LINK_LIBS ${ASSIMP_LIBRARIES} ${IL_LIBRARIES} ${GLEW_LIBRARIES} ${DEVIL_LIBRARIES} ${CVD_LIBRARIES} ${GVARS3_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${LAPACK_LIBRARIES}  ${Boost_LIBRARIES} ${ASSIMP_LIBRARIES})

target_link_libraries(PTAMs ${LINK_LIBS})
target_link_libraries(PTAMd ${LINK_LIBS})

### Define the installation procedure
# -- Local install
# install(TARGETS PTAMd PTAMs DESTINATION ${PROJECT_SOURCE_DIR}/lib)
# install(FILES ${HEADERS} DESTINATION ${PROJECT_SOURCE_DIR}/include)

# -- System install
install(FILES ${HEADERS} DESTINATION /usr/local/include/PTAM)
install(TARGETS PTAMd PTAMs DESTINATION /usr/local/lib)

