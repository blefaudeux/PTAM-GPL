# Define the project's name
project(gvars)

cmake_minimum_required(VERSION 2.6)

# Add all the files we're interested in (mostly for QTCreator)
file(GLOB HEADLESS_SRC  "src/gvars3.cc"
                        "src/GUI.cc"
                        "src/GStringUtil.cc"
                        "src/gvars2.cc"
                        "src/serialize.cc"
                        "src/GUI_none.cc"
                        "src/GUI_impl_headless.cc"
                        "src/inst.cc")

file(GLOB OBJS_SRC  "src/gvars3.cc"
                    "src/GUI.cc"
                    "src/GStringUtil.cc"
                    "src/gvars2.cc"
                    "src/serialize.cc"
                    "src/GUI_none.cc"
                    "src/GUI_non_readline.cc"
                    "src/inst.cc"
                    "src/GUI_readline.cc"
                    "src/GUI_impl_readline.cc")

set(COMPILE_FLAGS ${COMPILE_FLAGS} "-DGUI_HAVE_READLINE")

file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/gvars3/*.h)
file(GLOB HEADERS_X ${PROJECT_SOURCE_DIR}/src/*.h)

# Define the included directories
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/headers)
include_directories( ../TooN)

# Set debug or release configurations
if(CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
    message( "INFO: DEBUG BUILD" )
    # for debug type builds, turn on verbose makefiles
    SET(CMAKE_VERBOSE_MAKEFILE ON)

    # Tell other CMake files that we're doing a debug build
    SET( DEBUG_BUILD 1 )

    # Tell C/C++ that we're doing a debug build
    ADD_DEFINITIONS( -DDEBUG )
endif()

# Visual studio solutions handling
if(ENABLE_SOLUTION_FOLDERS)
  set_target_properties(cvd  PROPERTIES FOLDER "cvd")
endif()

if( CMAKE_BUILD_TYPE MATCHES "[Rr][Ee][Ll][Ee][Aa][Ss][Ee]" )
    message( "INFO: RELEASE BUILD" )
endif()

# Create libraries
add_library(gvars_headless SHARED ${HEADLESS_SRC} ${EXTRA_SRC})
add_library(gvars SHARED ${OBJS_SRC} ${EXTRA_SRC})

# Set the link libraries :
set(LINK_LIBS ${ASSIMP_LIBRARIES}  ${DEVIL_LIBRARIES} ${GLUT_LIBRARIES} ${LAPACK_LIBRARIES} ${Boost_LIBRARIES} ${ASSIMP_LIBRARIES})
