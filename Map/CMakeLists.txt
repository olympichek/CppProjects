cmake_minimum_required(VERSION 3.17)
project(Map)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)

add_executable(test tests/test.cpp)