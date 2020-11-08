cmake_minimum_required(VERSION 3.16)
project(Quaternion_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(sources headers tests)

add_executable(Quaternion_test
        tests/Quaternion_test.cpp
        sources/Quaternion.cpp
        headers/common.hpp
        headers/Quaternion.hpp
)