# Define the project's name
project(cvd)

cmake_minimum_required(VERSION 2.6)

# Add all the files we're interested in (mostly for QTCreator)
file(GLOB_RECURSE HEAD_CVD ${PROJECT_SOURCE_DIR} *.h)

# Define the included directories
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/headers)

file(GLOB SRC "src/diskbuffer2.cc"
      "src/deinterlacebuffer.cc"
      "src/exceptions.cc"
      "src/image_io.cc"
      "src/bayer.ccx"
      "src/morphology.cc"
      "src/colourspace_convert.ccx"
      "src/draw.cc"
      "src/yuv422.cc"
      "src/yuv420.cc"
      "src/image_io/pnm_grok.ccx"
      "src/image_io/bmp.ccx"
      "src/image_io/bmp_read.cc"
      "src/image_io/bmp_write.cc"
      "src/image_io/cvdimage.ccx"
      "src/image_io/fits.cc"
      "src/image_io/fitswrite.cc"
      "src/image_io/save_postscript.ccx"
      "src/image_io/text_write.cc"
      "src/image_io/text.ccx"
      "src/fast_corner.ccx"
      "src/convolution.cc"
      "src/nonmax_suppression.ccx"
      "src/timeddiskbuffer.cc"
      "src/videosource.cc"
      "src/connected_components.cc"
      "src/cvd_timer.cc"
      "src/i686/yuv411_to_stuff_MMX_64.cc"
      "src/SSE2/half_sample.cc"
      "src/noarch/convert_rgb_to_y.cc"
      "src/i686/convolve_gaussian.cc"
      "src/i686/gradient.cc"
      "src/noarch/yuv420p_to_rgb_runner.cc"
      "src/noarch/yuv422_wrapper.cc"
      "src/i686/median_3x3.cc"
      "src/i686/utility_float.cc"
      "src/i686/utility_byte_differences.cc"
      "src/i686/utility_double_int.cc"
      "src/SSE2/two_thirds_sample.cc"
      "src/fast_corner_9_nonmax.ccx"
      "src/fast/fast_7_detect.ccx"
      "src/fast/fast_7_score.ccx"
      "src/fast/fast_8_detect.ccx"
      "src/fast/fast_8_score.ccx"
      "src/fast/fast_9_detect.ccx"
      "src/fast/fast_9_score.ccx"
      "src/fast/fast_10_detect.ccx"
      "src/fast/fast_10_score.ccx"
      "src/fast/fast_11_detect.ccx"
      "src/fast/fast_11_score.ccx"
      "src/slower_corner_7.ccx"
      "src/slower_corner_8.ccx"
      "src/slower_corner_11.ccxx"
      "src/fast/fast_12_detect.cc"
      "src/fast/fast_12_score.cc"
      "src/SSE2/faster_corner_9.ccx"
      "src/SSE2/faster_corner_10.ccx"
      "src/SSE2/faster_corner_12.ccx"
      "src/Linux/dvbuffer3_dc1394v2.cc"
      "src/videosource_dvbuffer.cc"
      "src/Linux/videosource_nov4l1buffer.cc"
      "src/Linux/v4lbuffer.cc"
      "src/Linux/videosource_v4lbuffer.cc"
      "src/Linux/v4l2buffer.cc"
      "src/Linux/v4lcontrol.cc"
      "src/OSX/videosource_noqtbuffer.cc"
      "src/posix/get_time_of_day_ns.cc"
      "src/synchronized.cc"
      "src/eventobject.cc"
      "src/thread.cc"
      "src/posix/sched_yield.cc"
      "src/noarch/posix_memalign.cc"
      "src/videodisplay.cc"
      "src/glwindow.cc"
      "src/gltext.cc"
      "src/image_io/jpeg.ccx"
      "src/image_io/tiff.ccx"
      "src/image_io/tiffwrite.cc"
      "src/image_io/png.cc"
      "src/videosource_novideofilebuffer.cc"
      "src/globlist.ccx"
      "src/tensor_voting.cc"
      "src/brezenham.cc"
      "src/draw_toon.cc")

# Get dependencies
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(LAPACK REQUIRED)
find_package(GLEW REQUIRED)
find_package(DC1394 REQUIRED)
find_package(TIFF REQUIRED)
find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)
find_package(X11 REQUIRED)

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
add_library(cvd SHARED ${SRC} ${HEAD_CVD})

# Set the link libraries :
set(LINK_LIBS ${DC1394_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}  ${GLEW_LIBRARIES} ${LAPACK_LIBRARIES} ${Boost_LIBRARIES})
set(LINK_LIBS ${LINK_LIBS} ${TIFF_LIBRARIES} ${PNG_LIBRARIES} ${JPEG_LIBRARIES} ${X11_LIBRARIES})

target_link_libraries(cvd ${LINK_LIBS} pthread rt) # final librairies are Linux only - do something for windows !
