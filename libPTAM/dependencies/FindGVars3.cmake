 
# - Try to find LibGVars3
# Once done this will define
#  LIBGVars3_FOUND - System has LibGVars3
#  LIBGVars3_INCLUDE_DIRS - The LibGVars3 include directories
#  LIBGVars3_LIBRARIES - The libraries needed to use LibGVars3
#  LIBGVars3_DEFINITIONS - Compiler switches required for using LibGVars3

find_package(PkgConfig)
pkg_check_modules(PC_GVars3 QUIET libGVars3)
set(GVARS3_DEFINITIONS ${PC_GVars3_CFLAGS_OTHER})

find_path(GVARS3_INCLUDE_DIR gvars3/GUI.h
          HINTS ${PC_GVars3_INCLUDEDIR} ${PC_GVars3_INCLUDE_DIRS}
          PATH_SUFFIXES GVars3)

find_library(GVARS3_LIBRARY NAMES GVars3 libGVars3
             HINTS ${PC_GVars3_LIBDIR} ${PC_GVars3_LIBRARY_DIRS} )

# Handle a plural naming..             
set(GVARS3_LIBRARIES ${GVARS3_LIBRARY} )
set(GVARS3_INCLUDE_DIRS ${GVARS3_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIBXML2_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(GVars3  DEFAULT_MSG
                                  GVARS3_LIBRARY GVARS3_INCLUDE_DIR)

mark_as_advanced(GVARS3_INCLUDE_DIR GVARS3_LIBRARY )