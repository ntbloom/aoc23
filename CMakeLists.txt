cmake_minimum_required(VERSION 3.26)
project(aoc23)

set(CMAKE_CXX_STANDARD 23)
set(APP aoc23)

add_executable(${APP} main.cpp)
target_include_directories(days)
