cmake_minimum_required(VERSION 2.8)
project(HelloSLAM)

Set(CMAKE_BUILD_TYPE "Debug")
add_library(hello libHelloSLAM.cpp)           #making library from cpp file
add_library(hello_shared SHARED libHelloSLAM.cpp) 
add_executable(helloSLAM helloSLAM.cpp) 

add_executable(useHello useHello.cpp) # exe file making part
target_link_libraries(useHello hello_shared) # link library(function) to exe file

# this CMakeLists.txt file will be used to tell CMake what I want to do. 
# 