 
# - Try to find TooN library
# Once done, this will define
#
#  TooN_FOUND - system has TooN
#  TooN_INCLUDE_DIRS - the TooN include directories
#  TooN_LIBRARIES - link these to use TooN

include(LibFindMacros)

# Dependencies
#libfind_package(Magick++ Magick)

# Use pkg-config to get hints about paths
libfind_pkg_check_modules(TooN_PKGCONF TooN)

# Include dir
find_path(TooN_INCLUDE_DIR
  NAMES TooN.h
  PATHS ${TooN_PKGCONF_INCLUDE_DIRS}
)

# Finally the library itself
find_library(TooN_LIBRARY
  NAMES TooN
  PATHS ${TooN_PKGCONF_LIBRARY_DIRS}
)

# Set the include dir variables and the libraries and let libfind_process do the rest.
# NOTE: Singular variables for this library, plural for libraries this this lib depends on.
set(TooN_PROCESS_INCLUDES TooN_INCLUDE_DIR TooN_INCLUDE_DIRS)
set(TooN_PROCESS_LIBS TooN_LIBRARY TooN_LIBRARIES)
libfind_process(TooN)