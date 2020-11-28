cmake_minimum_required(VERSION 3.16)
project(random_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(sources headers tests)

add_executable(random_test
        tests/random_test.cpp
        sources/random.cpp
        headers/common.hpp
        headers/random.hpp
)

add_executable(variation_search
        tests/variation_search.cpp
        sources/random.cpp
        headers/common.hpp
        headers/random.hpp
)
