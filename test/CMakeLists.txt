
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_bowling test_bowling.cpp)
target_link_libraries(test_bowling ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} bowling)

# changed library output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

