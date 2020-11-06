cmake_minimum_required(VERSION 3.16)
project(quaternion_cpp)

set(CMAKE_CXX_STANDARD 14)
add_executable(Quaternion_test
        src/Quaternion_test.cpp
        src/Quaternion.cpp
        headers/common.h
        headers/Quaternion.h
)