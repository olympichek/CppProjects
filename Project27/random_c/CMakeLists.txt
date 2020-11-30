cmake_minimum_required(VERSION 3.16)
project(random_c)

set(CMAKE_C_STANDARD 99)

include_directories(headers)

add_executable(random_test
        tests/random_test.c
        sources/random.c
)

add_executable(variation_search
        tests/variation_search.c
        sources/random.c
)

IF(NOT WIN32)
        target_link_libraries(random_test m)
        target_link_libraries(variation_search m)
ENDIF()
