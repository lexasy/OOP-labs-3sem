cmake_minimum_required(VERSION 3.10)
project(lab)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab src/bear.cpp src/elf.cpp src/robber.cpp src/npc.cpp src/main.cpp)

enable_testing()
add_executable(tests src/bear.cpp src/elf.cpp src/robber.cpp src/npc.cpp tests/tests.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)