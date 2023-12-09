#ifndef AOC23_NINE_HPP
#define AOC23_NINE_HPP

#include "day.hpp"

namespace aoc
{

typedef std::vector<int64_t> history;
typedef std::vector<history *> histories;

struct node
{
    int value;
    node *left;
    node *right;
};

void cleanup (node *nd);

class Nine final : public Day<int64_t>
{
  public:
    Nine ();

    ~Nine () final;

    int64_t one () final;

    int64_t two () final;

  private:
    histories *_histories;
};
} // aoc

#endif // AOC23_NINE_HPP
