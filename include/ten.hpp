#ifndef AOC23_TEN_HPP
#define AOC23_TEN_HPP

#include "day.hpp"
#include <stack>

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

    friend bool operator== (const pipeNode &one, const pipeNode &two);
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

    void findNeighbors (pipeNode *node);
    static bool fromSouth (pipeNode *node);
    static bool fromNorth (pipeNode *node);
    static bool fromWest (pipeNode *node);
    static bool fromEast (pipeNode *node);

    void dfs (pipeNode *node);

    void printMap ();

  private:
    pipeMap *_map;
    pipeNode *_start;
    size_t count = 0;
};
} // aoc

#endif // AOC23_TEN_HPP
