cmake_minimum_required(VERSION 3.16)
project(random_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        headers
        ../random_c/headers
)

add_executable(random_test
        tests/random_test.cpp
        sources/random.cpp
)

add_executable(random_cross_test
        tests/random_cross_test.cpp
        ../random_c/sources/random.c
        sources/random.cpp
)

add_executable(variation_search
        tests/variation_search.cpp
        sources/random.cpp
)
