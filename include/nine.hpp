#ifndef AOC23_NINE_HPP
#define AOC23_NINE_HPP

#include "day.hpp"

namespace aoc
{

typedef std::vector<int> history;
typedef std::vector<history *> histories;

struct node
{
};

class Nine final : public Day<int>
{
  public:
    Nine ();

    ~Nine () final;

    int one () final;

    int two () final;

  private:
    histories *_histories;
};
} // aoc

#endif // AOC23_NINE_HPP
