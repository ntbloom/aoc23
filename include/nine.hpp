#ifndef AOC23_NINE_HPP
#define AOC23_NINE_HPP

#include "day.hpp"

namespace aoc
{
class Nine final : public Day<size_t>
{
  public:
    Nine ();

    ~Nine () final;

    size_t one () final;

    size_t two () final;
};
} // aoc

#endif // AOC23_NINE_HPP
