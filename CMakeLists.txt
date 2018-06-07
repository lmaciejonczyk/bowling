
cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME "bowling")
project(${PROJECT_NAME})

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-Og -ggdb")

add_subdirectory(src) 
add_subdirectory(test)

enable_testing()
add_test(TEST_BOWLING test_bowling)

