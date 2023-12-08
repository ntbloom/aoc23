#ifndef AOC23_EIGHT_HPP
#define AOC23_EIGHT_HPP

#include "day.hpp"

namespace aoc
{
class Eight final : public Day<size_t>
{
  public:
    Eight ();

    ~Eight () final;

    size_t one () final;

    size_t two () final;
};
} // aoc

#endif // AOC23_EIGHT_HPP
