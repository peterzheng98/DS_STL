cmake_minimum_required(VERSION 3.14)
project(deque)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest MODULE REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(DequeTest test_main.cpp test_1.cpp mocks/Integer.h mocks/Integer.cpp test_2.cpp mocks/Matrix.hpp mocks/Bint.cpp mocks/Bint.h mocks/DynamicType.cpp mocks/DynamicType.h)
target_link_libraries(DequeTest PRIVATE GTest::GTest GTest::Main)
