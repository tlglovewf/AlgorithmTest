cmake_minimum_required(VERSION 2.6)

project(Algorithm)

add_definitions(-std=c++11)

set(CMAKE_BUILD_TYPE "Debug")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

add_subdirectory(DataStruct)
add_subdirectory(StyleDesign)