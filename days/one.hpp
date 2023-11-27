#ifndef AOC23_ONE_HPP
#define AOC23_ONE_HPP

#include "day.hpp"

namespace aoc
{
class One final : public Day<int>
{
  public:
    One ();

    ~One () final;

    void _parse () final;

    int one () final;

    int two () final;
};
} // aoc

#endif // AOC23_ONE_HPP
