#include "one.hpp"
#include "three.hpp"
#include "two.hpp"
#include <fstream>
#include <gtest/gtest.h>

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
TEST (TestOne, TestCalibration)
{
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

TEST (TestTwo, TestIsPossible)
{
    std::vector<possible_t> cases{
        Two::isPossible ("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"),
        Two::isPossible ("Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue"),
        Two::isPossible (
            "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red"),
        Two::isPossible (
            "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red"),
        Two::isPossible ("Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"),
        Two::isPossible ("Game 10: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"),
        Two::isPossible ("Game 100: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"),
    };
    std::vector<size_t> gameNums{
        1, 2, 3, 4, 5, 10, 100,
    };
    std::vector<size_t> possibles{
        POSSIBLE, POSSIBLE, IMPOSSIBLE, IMPOSSIBLE, POSSIBLE, POSSIBLE, POSSIBLE,
    };
    assert (cases.size () == gameNums.size () && gameNums.size () == possibles.size ());
    for (auto i = 0; i < cases.size (); i++)
        {
            auto gameNum = cases.at (i)[0];
            auto expectedGameNum = gameNums.at (i);
            auto possible = cases.at (i)[1];
            auto expectedPossible = possibles.at (i);
            ASSERT_TRUE (gameNum == expectedGameNum);
            ASSERT_TRUE (possible == expectedPossible);
        }
}

TEST (TestTwo, TestPower)
{
    std::vector<size_t> cases{
        Two::minPower ("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"),
        Two::minPower ("Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue"),
        Two::minPower ("Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red"),
        Two::minPower ("Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red"),
        Two::minPower ("Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"),
        Two::minPower ("Game 10: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"),
        Two::minPower ("Game 100: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"),
    };
    std::vector<size_t> expected{ 48, 12, 1560, 630, 36, 36, 36 };
    for (auto i = 0; i < cases.size (); i++)
        {
            ASSERT_EQ (cases.at (i), expected.at (i));
        }
}

TEST (TestThree, TestProcessLine)
{
    // clang-format off
    std::vector<std::string>inputs{
        "467..114..",
        "...*......",
        "..35..633.",
        "......#...",
        "617*......",
        ".....+.58.",
        "..592.....",
        "......755.",
        "...$.*....",
        ".664.598..",
    };
    // clang-format on
    std::vector<size_t> expectedNumbers{
        114, 467, 633, 35, 617, 58, 592, 755, 598, 664,
    };
    possible poss{};
    std::string empty{};
    for (auto i = 0; i < inputs.size (); i++)
        {
            auto above = i == 0 ? empty : inputs.at (i - 1);
            auto current = inputs.at (i);
            auto below = i == inputs.size () - 1 ? empty : inputs.at (i + 1);
            Three::processLine (i, above, current, below, &poss);
        }

    std::vector<size_t> actualNumbers{};
    for (const auto &p : poss)
        {
            actualNumbers.push_back (p->number);
        }
    ASSERT_EQ (expectedNumbers.size (), actualNumbers.size ()) << "parsed incorrect qty of numbers";
    for (auto i = 0; i < expectedNumbers.size (); i++)
        {
            ASSERT_EQ (expectedNumbers.at (i), actualNumbers.at (i));
        }

    // check some positional stuff
    ASSERT_EQ (poss.at (0)->x, 5);
    ASSERT_EQ (poss.at (0)->y, 0);

    ASSERT_EQ (poss.at (1)->x, 0);
    ASSERT_EQ (poss.at (1)->y, 0);

    ASSERT_EQ (poss.at (3)->x, 2);
    ASSERT_EQ (poss.at (3)->y, 2);

    for (auto pn : poss)
        {
            if (pn->number == 114 || pn->number == 58)
                {
                    ASSERT_FALSE (pn->valid);
                }
            else
                {
                    ASSERT_TRUE (pn->valid);
                }
        }
}