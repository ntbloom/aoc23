#ifndef AOC23_THREE_HPP
#define AOC23_THREE_HPP

#include "day.hpp"
#include <vector>

namespace aoc
{

static constexpr size_t WIDTH = 140;
static constexpr size_t LENGTH = 140;

struct partNumber
{
    size_t number;
    size_t x;
    size_t y;
    size_t len;
    bool valid;
};

typedef std::vector<partNumber *> possible;
typedef std::array<size_t, 2> pair;

class Three final : public Day<size_t>
{
  public:
    Three ();

    ~Three () final;

    size_t one () final;

    size_t two () final;

    void process (possible *possibles);

    static void processLine (size_t lineNum, const std::string &above, const std::string &line,
                             const std::string &below, possible *poss);

    size_t reprocess ();

    static void findFactors (char *row, size_t start, size_t stop, std::vector<size_t> *factors);

    std::vector<std::string> lines{};
};
} // aoc

#endif // AOC23_THREE_HPP
