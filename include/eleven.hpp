#ifndef AOC23_ELEVEN_HPP
#define AOC23_ELEVEN_HPP

#include "day.hpp"
#include <set>

namespace aoc
{

struct galaxyNode
{
    size_t num;
    size_t x;
    size_t y;
};

typedef std::vector<galaxyNode *> galaxyRow;
typedef std::vector<galaxyRow> cosmos;

class Eleven final : public Day<size_t>
{
  public:
    Eleven ();

    ~Eleven () final;

    size_t one () final;

    size_t two () final;

  private:
    cosmos *_cosmos;
    std::vector<std::string> _lines{};
    std::set<size_t> _emptyColumns{};
    std::set<size_t> _emptyRows{};
};
} // aoc

#endif // AOC23_ELEVEN_HPP
