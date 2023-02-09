cmake_minimum_required(VERSION 3.0)
project(useSophus)

find_package(Sophus REQUIRED)   #find location of header and library files of a library
include_directories(${Sophus_INCLUDE_DIRS}) 
#find_package is needed for this _INCLUDE_DIRS and _LIBRARIES

include_directories("usr/include/eigen3")
add_executable(useSophus useSophus.cpp)
target_link_libraries(useSophus Sophus::Sophus)

add_subdirectory(example)