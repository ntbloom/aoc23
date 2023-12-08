#ifndef AOC23_SEVEN_HPP
#define AOC23_SEVEN_HPP

#include "day.hpp"

namespace aoc
{
class Seven final : public Day<size_t>
{
  public:
    Seven ();

    ~Seven () final;

    size_t one () final;

    size_t two () final;
};
} // aoc

#endif // AOC23_SEVEN_HPP
