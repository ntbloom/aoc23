#ifndef AOC23_NINE_HPP
#define AOC23_NINE_HPP

#include "day.hpp"

namespace aoc
{
typedef std::vector<int64_t> history;
typedef std::vector<history *> histories;

class Nine final : public Day<int64_t>
{
  public:
    Nine ();

    ~Nine () final;

    int64_t one () final;

    int64_t two () final;

    static void buildRows (histories *sequence, history *row);

    static bool allZeros (history *row);

    static int64_t findNext (histories *sequence);

  private:
    histories *_inputLines;
};
} // aoc

#endif // AOC23_NINE_HPP
