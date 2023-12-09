#ifndef AOC23_ONE_HPP
#define AOC23_ONE_HPP

#include "day.hpp"
#include <array>

namespace aoc
{

static std::array<char, 2> intermediate = { 'X', 'X' };

class One final : public Day<int64_t>
{
  public:
    One ();

    ~One () final;

    int64_t one () final;

    int64_t two () final;

    static int64_t calibrate (const std::string &input);

    static int64_t recalibrate (const std::string &input);
};
} // aoc

#endif // AOC23_ONE_HPP
