cmake_minimum_required(VERSION 3.6)
project(MN)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/debug/)


set(SOURCE_FILES main.cpp)
add_executable(MN ${SOURCE_FILES})