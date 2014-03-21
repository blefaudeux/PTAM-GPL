 
cmake_minimum_required (VERSION 2.6) 
project (PTAM)

# Recurse into the "TooN", "gvars" and "cvd" subdirectories. This does not actually 
# cause another cmake executable to run. The same process will walk through 
# the project's entire directory structure.
add_subdirectory(cvd)
add_subdirectory(gvars)
add_subdirectory(TooN)
