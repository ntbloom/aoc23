#include <gtest/gtest.h>

// clang-format off
#include "one.hpp"
#include "two.hpp"
#include "three.hpp"
#include "four.hpp"
#include "five.hpp"
#include "six.hpp"
#include "seven.hpp"
// clang-format on

using namespace aoc;

TEST (Test_Solutions, One_ONE)
{
    One one{};
    EXPECT_EQ (one.solve (1), 54697);
}

TEST (Test_Solutions, One_TWO)
{
    One one{};
    EXPECT_EQ (one.solve (2), 54885);
}

TEST (Test_Solutions, Two_ONE)
{
    Two two{};
    EXPECT_EQ (two.solve (1), 2283);
}

TEST (Test_Solutions, Two_TWO)
{
    Two two{};
    EXPECT_EQ (two.solve (2), 78669);
}

TEST (Test_Solutions, Three_ONE)
{
    Three three{};
    EXPECT_EQ (three.solve (1), 533784);
}

TEST (Test_Solutions, Three_TWO)
{
    Three three{};
    EXPECT_EQ (three.solve (2), 78826761);
}

TEST (Test_Solutions, Four_ONE)
{
    Four four{};
    EXPECT_EQ (four.solve (1), 22897);
}

TEST (Test_Solutions, Four_TWO)
{
    Four four{};
    EXPECT_EQ (four.solve (2), 5095824);
}

TEST (Test_Solutions, Five_ONE)
{
    Five five{};
    EXPECT_EQ (five.solve (1), 177942185);
}

TEST (Test_Solutions, DISABLED_Five_TWO)
{
    Five five{};
    EXPECT_EQ (five.solve (2), -1);
}

TEST (Test_Solutions, Six_ONE)
{
    Six six{};
    EXPECT_EQ (six.solve (1), 128700);
}

TEST (Test_Solutions, Six_TWO)
{
    Six six{};
    EXPECT_EQ (six.solve (2), 39594072);
}