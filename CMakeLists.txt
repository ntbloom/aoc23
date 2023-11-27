cmake_minimum_required(VERSION 3.26)
project(aoc23)

set(CMAKE_CXX_STANDARD 23)

add_executable(aoc23
        main.cpp
        one.cpp
        two.cpp
)
include_directories(days)
