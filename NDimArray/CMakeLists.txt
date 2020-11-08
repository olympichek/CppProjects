cmake_minimum_required(VERSION 3.16)
project(NDimArray)

set(CMAKE_CXX_STANDARD 14)

add_executable(NDimArray test.cpp NDimArray.hpp)