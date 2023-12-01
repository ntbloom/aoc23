#ifndef AOC23_ONE_HPP
#define AOC23_ONE_HPP

#include "day.hpp"
#include <array>

namespace aoc
{

static std::array<char, 2> intermediate = { 'X', 'X' };

class One final : public Day<int>
{
  public:
    One ();

    ~One () final;

    int one () final;

    int two () final;

    static int calibrate (const std::string &input);

    static int recalibrate (const std::string &input);
};
} // aoc

#endif // AOC23_ONE_HPP
