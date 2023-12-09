#ifndef AOC23_NINE_HPP
#define AOC23_NINE_HPP

#include "day.hpp"

namespace aoc
{

struct node
{
    node ()
    {
        value = 0;
        left = nullptr;
        right = nullptr;
    }

    int64_t value;
    node *left;
    node *right;
};

typedef std::vector<node *> history;
typedef std::vector<history *> histories;

class Nine final : public Day<int64_t>
{
  public:
    Nine ();

    ~Nine () final;

    int64_t one () final;

    int64_t two () final;

    /* build a tree and return the root node */
    static node *buildTree (history *hist);

  private:
    histories *_histories;
    node *_root;
};
} // aoc

#endif // AOC23_NINE_HPP
