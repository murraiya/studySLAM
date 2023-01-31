# Add header file eigen3 (Eigen when import)
add_executable(eigenMatrix eigenMatrix.cpp)
include_directories("/usr/include/eigen3")
# target_link_libraries needed when it has library file, but eigen3 only has header files
# maybe others have eigen3 lib in other locations so later we will use find_package command 


