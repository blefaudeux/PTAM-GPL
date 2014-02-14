# Define the project's name
project(PTAM)

cmake_minimum_required(VERSION 2.6)

# Get to know where all the dependencies are..
LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/dependencies)
message("Additional directory : ${CMAKE_MODULE_PATH}")

# Add all the files we're interested in (mostly for QTCreator)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/headers/*.h)

# Define the included directories
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/headers)

# Try to find the needed packages
find_package(Boost REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(LAPACK REQUIRED)
find_package(CVD REQUIRED)
find_package(GVars3 REQUIRED)

# Hard-code TooN, GVars3 and CVD 
set(TooN_INCLUDE_DIR "/usr/local/include")

include_directories(${TooN_INCLUDE_DIR} ${GVars3_INCLUDE_DIR})

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
add_library (PTAM_static STATIC ${SRC} ${HEADERS})
add_library (PTAM_dynamic SHARED ${SRC} ${HEADERS})

# Set the link libraries :
set(LINK_LIBS  ${Boost_LIBRARIES} ${CVD_LIBRARIES} ${GVars3_LIBRARIES} ${OpenGL_LIBRARIES} ${GLUT_LIBRARIES} ${LAPACK_LIBRARIES})

message("Libraries to be linked to : \n ${LINK_LIBS}")

TARGET_LINK_LIBRARIES(PTAM_static ${LINK_LIBS})
TARGET_LINK_LIBRARIES(PTAM_dynamic ${LINK_LIBS})

### Define the installation procedure
install(TARGETS PTAM_dynamic PTAM_static DESTINATION ${PROJECT_SOURCE_DIR}/lib)
install(FILES ${HEADERS} DESTINATION ${PROJECT_SOURCE_DIR}/include)
