 
# - Try to find libassimp
# Once done this will define
#  LIBAssimp_FOUND - System has libassimp
#  LIBAssimp_INCLUDE_DIRS - The libassimp include directories
#  LIBAssimp_LIBRARIES - The libraries needed to use libassimp
#  LIBAssimp_DEFINITIONS - Compiler switches required for using libassimp

find_package(PkgConfig)
pkg_check_modules(PC_Assimp QUIET libassimp)
set(ASSIMP_DEFINITIONS ${PC_Assimp_CFLAGS_OTHER})

find_path(ASSIMP_INCLUDE_DIR assimp/mesh.h
          HINTS ${PC_Assimp_INCLUDEDIR} ${PC_Assimp_INCLUDE_DIRS}
          PATH_SUFFIXES assimp)

find_library(ASSIMP_LIBRARY NAMES assimp libassimp
             HINTS ${PC_Assimp_LIBDIR} ${PC_Assimp_LIBRARY_DIRS} )

# Handle a plural naming..             
set(ASSIMP_LIBRARIES ${ASSIMP_LIBRARY} )
set(ASSIMP_INCLUDE_DIRS ${ASSIMP_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set ASSIMP to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(libassimp  DEFAULT_MSG
                                  ASSIMP_LIBRARY ASSIMP_INCLUDE_DIR)

mark_as_advanced(ASSIMP_INCLUDE_DIR ASSIMP_LIBRARY )