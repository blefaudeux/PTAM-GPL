 
# - Try to find LibGVars3
# Once done this will define
#  LIBGVars3_FOUND - System has LibGVars3
#  LIBGVars3_INCLUDE_DIRS - The LibGVars3 include directories
#  LIBGVars3_LIBRARIES - The libraries needed to use LibGVars3
#  LIBGVars3_DEFINITIONS - Compiler switches required for using LibGVars3

find_package(PkgConfig)
pkg_check_modules(PC_LIBGVars3 QUIET libGVars3)
set(LIBGVars3_DEFINITIONS ${PC_LIBGVars3_CFLAGS_OTHER})

find_path(LIBGVars3_INCLUDE_DIR gvars3/GUI.h
          HINTS ${PC_LIBGVars3_INCLUDEDIR} ${PC_LIBGVars3_INCLUDE_DIRS}
          PATH_SUFFIXES GVars3)

find_library(LIBGVars3_LIBRARY NAMES GVars3 libGVars3
             HINTS ${PC_LIBGVars3_LIBDIR} ${PC_LIBGVars3_LIBRARY_DIRS} )

set(LIBGVars3_LIBRARIES ${LIBGVars3_LIBRARY} )
set(LIBGVars3_INCLUDE_DIRS ${LIBGVars3_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIBXML2_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(libGVars3  DEFAULT_MSG
                                  LIBGVars3_LIBRARY LIBGVars3_INCLUDE_DIR)

mark_as_advanced(LIBGVars3_INCLUDE_DIR LIBGVars3_LIBRARY )