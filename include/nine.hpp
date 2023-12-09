#ifndef AOC23_NINE_HPP
#define AOC23_NINE_HPP

#include "day.hpp"

namespace aoc
{

typedef std::vector<int64_t> history;
typedef std::vector<history *> histories;

class Nine final : public Day<size_t>
{
  public:
    Nine ();

    ~Nine () final;

    size_t one () final;

    size_t two () final;

  private:
    histories *_histories;
};
} // aoc

#endif // AOC23_NINE_HPP
