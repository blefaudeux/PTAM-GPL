 
# - Try to find TooN library
# Once done, this will define
#
#  TooN_FOUND - system has TooN
#  TooN_INCLUDE_DIRS - the TooN include directories
#  TooN_LIBRARIES - link these to use TooN


find_package(PkgConfig)
pkg_check_modules(PC_TooN QUIET TooN)
set(TOON_DEFINITIONS ${PC_TooN_CFLAGS_OTHER})

# Include dir
find_path(TOON_INCLUDE_DIR
  NAMES TooN/TooN.h
  HINTS /usr/local/include
  PATHS ${TooN_PKGCONF_INCLUDE_DIRS}
)

# Handle a plural naming..             
set(TOON_INCLUDE_DIRS ${TOON_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(TooN  DEFAULT_MSG
                                  TOON_INCLUDE_DIR)
                                  
mark_as_advanced(TOON_INCLUDE_DIR)