# Define the project's name
project(CamCalibrator)

cmake_minimum_required(VERSION 2.6)

# Get to know where all the dependencies are..
#LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/dependencies)
#message("Additional directory : ${CMAKE_MODULE_PATH}")

# Add all the files we're interested in (mostly for QTCreator)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/headers/*.h)

# Define the included directories
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/headers)
include_directories(${PROJECT_SOURCE_DIR}/../libPTAM/include)
include_directories(${PROJECT_SOURCE_DIR}/../libPTAM/lib)

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

# Build the executable
ADD_EXECUTABLE(CamCalibrator ${SRC} ${HEADERS})
TARGET_LINK_LIBRARIES(CamCalibrator PTAMs  ${OPENGL_LIBRARIES})

### Define the installation procedure
#install(TARGETS PTAM_dynamic PTAM_static DESTINATION ${PROJECT_SOURCE_DIR}/lib)
#install(FILES ${HEADERS} DESTINATION ${PROJECT_SOURCE_DIR}/include)
