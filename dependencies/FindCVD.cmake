# - Try to find LibCVD
# Once done this will define
#  LIBCVD_FOUND - System has LibCVD
#  LIBCVD_INCLUDE_DIRS - The LibCVD include directories
#  LIBCVD_LIBRARIES - The libraries needed to use LibCVD
#  LIBCVD_DEFINITIONS - Compiler switches required for using LibCVD

find_package(PkgConfig)
pkg_check_modules(PC_LIBCVD QUIET libcvd)
set(LIBCVD_DEFINITIONS ${PC_LIBCVD_CFLAGS_OTHER})

find_path(LIBCVD_INCLUDE_DIR cvd/abs.h
          HINTS ${PC_LIBCVD_INCLUDEDIR} ${PC_LIBCVD_INCLUDE_DIRS}
          PATH_SUFFIXES cvd)

find_library(LIBCVD_LIBRARY NAMES cvd libcvd
             HINTS ${PC_LIBCVD_LIBDIR} ${PC_LIBCVD_LIBRARY_DIRS} )

set(LIBCVD_LIBRARIES ${LIBCVD_LIBRARY} )
set(LIBCVD_INCLUDE_DIRS ${LIBCVD_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIBXML2_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(libcvd  DEFAULT_MSG
                                  LIBCVD_LIBRARY LIBCVD_INCLUDE_DIR)

mark_as_advanced(LIBCVD_INCLUDE_DIR LIBCVD_LIBRARY )