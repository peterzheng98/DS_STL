cmake_minimum_required(VERSION 3.5)
project(deque)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest MODULE REQUIRED)
find_package(benchmark CONFIG REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(DequeTest test_main.cpp basic_test.cpp mocks/Integer.h mocks/Integer.cpp random_test.cpp mocks/Matrix.hpp mocks/Bint.cpp mocks/Bint.h mocks/DynamicType.cpp mocks/DynamicType.h series_test.cpp mocks/Int.hpp)
add_executable(DequeTestBench test_bench.cpp test_bench.cpp)
add_executable(DequeBench bench_main.cpp)

target_link_libraries(DequeTest PRIVATE GTest::GTest GTest::Main)
target_link_libraries(DequeTestBench PRIVATE benchmark::benchmark benchmark::benchmark_main)
