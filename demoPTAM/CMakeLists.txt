# Define the project's name
project(demoPTAM)

cmake_minimum_required(VERSION 2.6)

# Add all the files we're interested in (mostly for QTCreator)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/headers/*.h)

# Define the included directories
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/headers)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLUT_INCLUDE_DIRS})
include_directories( ../libPTAM )

# Set debug or release configurations
if( CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
    message( "INFO: DEBUG BUILD" )
    set(CMAKE_VERBOSE_MAKEFILE ON)
    set(DEBUG_BUILD 1 )
    add_definitions( -DDEBUG )
endif()

if( CMAKE_BUILD_TYPE MATCHES "[Rr][Ee][Ll][Ee][Aa][Ss][Ee]" )
    message( "INFO: RELEASE BUILD" )
endif()

# Set the link libraries :
set(LINK_LIBS ${IL_LIBRARIES} ${ASSIMP_LIBRARIES} ${GLEW_LIBRARIES} ${CVD_LIBRARIES} ${GVARS3_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${LAPACK_LIBRARIES}  ${Boost_LIBRARIES})

# Build the executable
add_executable(demoPTAM ${SRC})
add_dependencies( demoPTAM libPTAM)

if( CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" )
  set_target_properties(demoPTAM PROPERTIES COMPILE_FLAGS "-fPIC")
endif( CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" )

target_link_libraries(demoPTAM ../libPTAM/libPTAMs.a ${LINK_LIBS})
