add_subdirectory(cvd)
add_subdirectory(gvars)
add_subdirectory(TooN)

if(ENABLE_SOLUTION_FOLDERS)
  set_target_properties(cvd  PROPERTIES FOLDER "third_party")
  set_target_properties(gvars  PROPERTIES FOLDER "third_party")
  set_target_properties(TooN  PROPERTIES FOLDER "third_party")
endif()
