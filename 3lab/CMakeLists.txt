cmake_minimum_required(VERSION 3.10)
project(lab)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab src/realisation/point.cpp src/realisation/figure.cpp src/realisation/pentagon.cpp src/realisation/hexagon.cpp src/realisation/octagon.cpp src/realisation/figure_array.cpp src/main.cpp)

enable_testing()
add_executable(tests src/realisation/point.cpp src/realisation/figure.cpp src/realisation/pentagon.cpp src/realisation/hexagon.cpp src/realisation/octagon.cpp src/realisation/figure_array.cpp src/tests/tests.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)