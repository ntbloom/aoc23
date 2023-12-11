#ifndef AOC23_ELEVEN_HPP
#define AOC23_ELEVEN_HPP

#include "day.hpp"

namespace aoc
{

struct galaxyNode
{
    size_t num;
    size_t x;
    size_t y;
};

typedef std::vector<galaxyNode *> cosmosRow;

struct cosmos
{
    std::vector<cosmosRow> rows;

    cosmos () = default;
    ~cosmos ()
    {
        for (const auto &r : this->rows)
            {
                for (auto galPtr : r)
                    {
                        delete galPtr;
                    }
            }
    }
};

class Eleven final : public Day<size_t>
{
  public:
    Eleven ();

    ~Eleven () final;

    size_t one () final;

    size_t two () final;

  private:
    std::vector<std::string> _lines{};
    std::vector<size_t> _emptyColumns;
    std::vector<size_t> _emptyRows;
};
} // aoc

#endif // AOC23_ELEVEN_HPP
