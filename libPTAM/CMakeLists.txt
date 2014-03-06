# Define the project's name
project(libPTAM)

cmake_minimum_required(VERSION 2.6)

# Add all the files we're interested in (mostly for QTCreator)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/headers/*.h)

# Define the included directories
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/headers)
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
add_library (PTAMs STATIC ${SRC} ${HEADERS})
add_library (PTAMd SHARED ${SRC} ${HEADERS})

# Set the link libraries :
set(LINK_LIBS ${CVD_LIBRARIES} ${GVARS3_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${LAPACK_LIBRARIES}  ${Boost_LIBRARIES})

target_link_libraries(PTAMs ${LINK_LIBS})
target_link_libraries(PTAMd ${LINK_LIBS})

### Define the installation procedure
install(TARGETS PTAMd PTAMs DESTINATION ${PROJECT_SOURCE_DIR}/lib)
install(FILES ${HEADERS} DESTINATION ${PROJECT_SOURCE_DIR}/include)

install(FILES ${HEADERS} DESTINATION /usr/local/include/PTAM)
install(TARGETS PTAMd PTAMs DESTINATION /usr/local/lib)

