cmake_minimum_required(VERSION 2.6.4)
project(logger)

set (CMAKE_BUILD_TYPE Debug)

include_directories(include)
add_subdirectory(src ${PROJECT_SOURCE_DIR}/build/bin)

