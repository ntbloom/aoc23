#include "one.hpp"
#include <gtest/gtest.h>

using namespace aoc;

TEST (MainTest, TestOneOne)
{
    One one{};
    EXPECT_EQ (one.one (), 54697);
    EXPECT_EQ (one.two (), 54885);
}

TEST (TestOne, TestCalibration)
{
    EXPECT_EQ (One::calibrate ("1abc2"), 12);
    EXPECT_EQ (One::calibrate ("pqr3stu8vwx"), 38);
    EXPECT_EQ (One::calibrate ("a1b2c3d4e5f"), 15);
    EXPECT_EQ (One::calibrate ("treb7uchet"), 77);
}

TEST (TestOne, TestRecalibration)
{
    EXPECT_EQ (One::recalibrate ("two1nine"), 29);
    EXPECT_EQ (One::recalibrate ("eightwothree"), 83);
    EXPECT_EQ (One::recalibrate ("abcone2threexyz"), 13);
    EXPECT_EQ (One::recalibrate ("xtwone3four"), 24);
    EXPECT_EQ (One::recalibrate ("4nineeightseven2"), 42);
    EXPECT_EQ (One::recalibrate ("zoneight234"), 14);
    EXPECT_EQ (One::recalibrate ("7pqrstsixteen"), 76);
    EXPECT_EQ (One::recalibrate ("fiveonethreeone"), 51);
    EXPECT_EQ (One::recalibrate ("zlmlk1"), 11);
}
