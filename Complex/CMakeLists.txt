cmake_minimum_required(VERSION 3.17)
project(Complex)

set(CMAKE_CXX_STANDARD 14)
include_directories(headers)

add_executable(Complex_test tests/test.cpp)