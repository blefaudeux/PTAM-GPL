# - Try to find LibCVD
# Once done this will define
#  LIBCVD_FOUND - System has LibCVD
#  LIBCVD_INCLUDE_DIRS - The LibCVD include directories
#  LIBCVD_LIBRARIES - The libraries needed to use LibCVD
#  LIBCVD_DEFINITIONS - Compiler switches required for using LibCVD

find_package(PkgConfig)
pkg_check_modules(PC_CVD QUIET libcvd)
set(CVD_DEFINITIONS ${PC_CVD_CFLAGS_OTHER})

find_path(CVD_INCLUDE_DIR cvd/abs.h
          HINTS ${PC_CVD_INCLUDEDIR} ${PC_CVD_INCLUDE_DIRS}
          PATH_SUFFIXES cvd)

find_library(CVD_LIBRARY NAMES cvd libcvd
             HINTS ${PC_CVD_LIBDIR} ${PC_CVD_LIBRARY_DIRS} )

# Handle a plural naming..             
set(CVD_LIBRARIES ${CVD_LIBRARY} )
set(CVD_INCLUDE_DIRS ${CVD_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIBXML2_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(libcvd  DEFAULT_MSG
                                  CVD_LIBRARY CVD_INCLUDE_DIR)

mark_as_advanced(CVD_INCLUDE_DIR CVD_LIBRARY )