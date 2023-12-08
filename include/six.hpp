#ifndef AOC23_SI6_HPP
#define AOC23_SI6_HPP

#include "day.hpp"

namespace aoc
{

struct race
{
    size_t time;
    size_t distance;
    size_t wins;
    size_t winStart;
    size_t winStop;
};

typedef std::array<race, 4> races;

class Six final : public Day<size_t>
{
  public:
    Six ();

    ~Six () final;

    size_t one () final;

    size_t two () final;

  private:
    races *_races;
    static bool wins (const race &race, size_t holdMs);
};
} // aoc

#endif // AOC23_SI6_HPP
