cmake_minimum_required(VERSION 3.10)
project(lab)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab src/point.cpp src/pentagon.cpp src/hexagon.cpp src/octagon.cpp src/main.cpp)