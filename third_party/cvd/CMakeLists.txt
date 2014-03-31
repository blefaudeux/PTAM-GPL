# Define the project's name
project(cvd)

cmake_minimum_required(VERSION 2.6)

# Add all the files we're interested in (mostly for QTCreator)
file(GLOB HEAD_CVD ${PROJECT_SOURCE_DIR}/cvd_src/*.h)

FILE(GLOB SRC "cvd_src/diskbuffer2.cc"
      "cvd_src/deinterlacebuffer.cc"
      "cvd_src/exceptions.cc"
      "cvd_src/image_io.cc"
      "cvd_src/bayer.cc"
      "cvd_src/morphology.cc"
      "cvd_src/colourspace_convert.cc"
      "cvd_src/draw.cc"
      "cvd_src/yuv422.cc"
      "cvd_src/yuv420.cc"
      "cvd_src/image_io/pnm_grok.cc"
      "cvd_src/image_io/bmp.cc"
      "cvd_src/image_io/bmp_read.cc"
      "cvd_src/image_io/bmp_write.cc"
      "cvd_src/image_io/cvdimage.cc"
      "cvd_src/image_io/fits.cc"
      "cvd_src/image_io/fitswrite.cc"
      "cvd_src/image_io/save_postscript.cc"
      "cvd_src/image_io/text_write.cc"
      "cvd_src/image_io/text.cc"
      "cvd_src/fast_corner.cc"
      "cvd_src/convolution.cc"
      "cvd_src/nonmax_suppression.cc"
      "cvd_src/timeddiskbuffer.cc"
      "cvd_src/videosource.cc"
      "cvd_src/connected_components.cc"
      "cvd_src/cvd_timer.cc"
      "cvd_src/i686/yuv411_to_stuff_MMX_64.cc"
      "cvd_src/SSE2/half_sample.cc"
      "cvd_src/noarch/convert_rgb_to_y.cc"
      "cvd_src/i686/convolve_gaussian.cc"
      "cvd_src/i686/gradient.cc"
      "cvd_src/noarch/yuv420p_to_rgb_runner.cc"
      "cvd_src/noarch/yuv422_wrapper.cc"
      "cvd_src/i686/median_3x3.cc"
      "cvd_src/i686/utility_float.cc"
      "cvd_src/i686/utility_byte_differences.cc"
      "cvd_src/i686/utility_double_int.cc"
      "cvd_src/SSE2/two_thirds_sample.cc"
      "cvd_src/fast/fast_7_detect.cc"
      "cvd_src/fast/fast_7_score.cc"
      "cvd_src/slower_corner_7.cc"
      "cvd_src/fast/fast_8_detect.cc"
      "cvd_src/fast/fast_8_score.cc"
      "cvd_src/slower_corner_8.cc"
      "cvd_src/fast/fast_9_detect.cc"
      "cvd_src/fast/fast_9_score.cc"
      "cvd_src/fast_corner_9_nonmax.cc"
      "cvd_src/fast/fast_10_detect.cc"
      "cvd_src/fast/fast_10_score.cc"
      "cvd_src/fast/fast_11_detect.cc"
      "cvd_src/fast/fast_11_score.cc"
      "cvd_src/slower_corner_11.cc"
      "cvd_src/fast/fast_12_detect.cc"
      "cvd_src/fast/fast_12_score.cc"
      "cvd_src/SSE2/faster_corner_9.cc"
      "cvd_src/SSE2/faster_corner_10.cc"
      "cvd_src/SSE2/faster_corner_12.cc"
      "cvd_src/Linux/dvbuffer3_dc1394v2.cc"
      "cvd_src/videosource_dvbuffer.cc"
      "cvd_src/Linux/videosource_nov4l1buffer.cc"
      "cvd_src/Linux/v4lbuffer.cc"
      "cvd_src/Linux/videosource_v4lbuffer.cc"
      "cvd_src/Linux/v4l2buffer.cc"
      "cvd_src/Linux/v4lcontrol.cc"
      "cvd_src/OSX/videosource_noqtbuffer.cc"
      "cvd_src/posix/get_time_of_day_ns.cc"
      "cvd_src/synchronized.cc"
      "cvd_src/eventobject.cc"
      "cvd_src/thread.cc"
      "cvd_src/posix/sched_yield.cc"
      "cvd_src/noarch/posix_memalign.cc"
      "cvd_src/videodisplay.cc"
      "cvd_src/glwindow.cc"
      "cvd_src/gltext.cc"
      "cvd_src/image_io/jpeg.cc"
      "cvd_src/image_io/tiff.cc"
      "cvd_src/image_io/tiffwrite.cc"
      "cvd_src/image_io/png.cc"
      "cvd_src/videosource_novideofilebuffer.cc"
      "cvd_src/globlist.cc"
      "cvd_src/tensor_voting.cc"
      "cvd_src/brezenham.cc"
      "cvd_src/draw_toon.cc")

# Define the included directories
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/cvd_src)
include_directories(${PROJECT_SOURCE_DIR}/headers)

# Get dependencies
find_package(Boost COMPONENTS system thread REQUIRED)
find_package(OpenGL REQUIRED)

find_package(GLUT REQUIRED)
find_package(LAPACK REQUIRED)
find_package(DevIL REQUIRED)
find_package(Assimp REQUIRED)
find_package(GLEW REQUIRED)

# -ltiff -ljpeg -lpng -lpng -llapack -lGLU -lGL -lrt -ldc1394  -pthread -lX11 -lXext

# Visual studio solutions handling
if(ENABLE_SOLUTION_FOLDERS)
  set_target_properties(cvd PROPERTIES FOLDER "cvd")
endif()

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

# Create ad-hoc library
set(COMPILE_FLAGS ${COMPILE_FLAGS} "-fPIC")
message("Current compile flags : " ${COMPILE_FLAGS})
add_library(cvd SHARED ${SRC} ${HEAD_Gvars} ${HEAD_cvd})

# Set the link libraries :
set(LINK_LIBS ${ASSIMP_LIBRARIES}  ${DEVIL_LIBRARIES} ${GLUT_LIBRARIES} ${LAPACK_LIBRARIES} ${Boost_LIBRARIES} ${ASSIMP_LIBRARIES})
