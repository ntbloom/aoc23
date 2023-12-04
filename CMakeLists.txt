cmake_minimum_required(VERSION 3.26)
project(aoc23)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(
        -DLIBCXX_ENABLE_INCOMPLETE_FEATURES=ON
)

file(GLOB SRC src/*.cpp)

add_executable(aoc23
        main.cpp
        ${SRC}
)
include_directories(include)

# enable gtest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/b10fad38c4026a29ea6561ab15fc4818170d1c10.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
        mainTest
        test/mainTest.cpp
        ${SRC}
)
target_link_libraries(
        mainTest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(mainTest)

