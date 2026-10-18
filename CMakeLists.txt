
cmake_minimum_required(VERSION 3.16)

project(SpaceSim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    test_gravity
    tests/test_gravity.cpp
)

enable_testing()
add_test(NAME GravityTest COMMAND test_gravity)
