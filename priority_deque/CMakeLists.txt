cmake_minimum_required(VERSION 3.5)
project(priority_deque)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest MODULE REQUIRED)
find_package(benchmark CONFIG REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(PriorityDequeTest test_main.cpp basic_test.cpp merge_test.cpp foreign_type_test.cpp)
# add_executable(PriorityDequeTestBench test_bench.cpp)
# add_executable(PriorityDequeBench bench_main.cpp)

target_link_libraries(PriorityDequeTest PRIVATE GTest::GTest GTest::Main)
# target_link_libraries(PriorityDequeTestBench PRIVATE benchmark::benchmark benchmark::benchmark_main)
