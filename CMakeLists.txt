cmake_minimum_required(VERSION 3.26)
project(aoc23)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/b10fad38c4026a29ea6561ab15fc4818170d1c10.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(aoc23
        main.cpp
        one.cpp
)
include_directories(days)

enable_testing()

add_executable(
        mainTest
        test/mainTest.cpp
        one.cpp
)
target_link_libraries(
        mainTest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(mainTest)

