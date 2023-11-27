#include "one.hpp"
#include <gtest/gtest.h>

TEST (MainTest, TestOneOne)
{
    auto *one = new aoc::One ();
    EXPECT_NE (one->one (), -1) << "invalid answer for 1:1";
    delete one;
}
