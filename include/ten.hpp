#ifndef AOC23_TEN_HPP
#define AOC23_TEN_HPP

#include "day.hpp"

namespace aoc
{
class Ten final : public Day<size_t>
{
  public:
    Ten ();

    ~Ten () final;

    size_t one () final;

    size_t two () final;

    char _map[140][140];
    void printMap ();
};
} // aoc

#endif // AOC23_TEN_HPP
