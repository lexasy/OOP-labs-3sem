cmake_minimum_required(VERSION 3.10)
project(lab)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab src/main.c++ src/twelwe.c++ src/dyn_array.c++)

# enable_testing()
# add_executable(tests src/tests.c++ src/twelwe.c++)
# target_link_libraries(tests ${GTEST_LIBRARIES})

# add_test(NAME BASIC COMMAND tests)