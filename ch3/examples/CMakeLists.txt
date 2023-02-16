add_executable(coordinateTransform coordinateTransform.cpp)
include_directories("/usr/include/eigen3")

find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})   
# find_package fing location and give it to ${include_DIRS}
add_executable(plotTrajectory plotTrajectory.cpp)
target_link_libraries(plotTrajectory ${Pangolin_LIBRARIES}) 
# this must be Pangolin_LIBRARIES not Pangolin_INCLUDE_DIRS. you should link! lib!.

