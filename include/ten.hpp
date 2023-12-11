#ifndef AOC23_TEN_HPP
#define AOC23_TEN_HPP

#include "day.hpp"

namespace aoc
{

struct pipeNode
{
    pipeNode *north;
    pipeNode *south;
    pipeNode *east;
    pipeNode *west;

    bool visited;

    size_t x;
    size_t y;
    char value;
};
typedef std::array<pipeNode *, 140> pipeRow;
typedef std::array<pipeRow, 140> pipeMap;

class Ten final : public Day<size_t>
{
  public:
    Ten ();

    ~Ten () final;

    size_t one () final;

    size_t two () final;

    void printMap ();

  private:
    pipeMap *_map;
    pipeNode *_start;
};
} // aoc

#endif // AOC23_TEN_HPP
