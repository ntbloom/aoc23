#ifndef AOC23_EIGHT_HPP
#define AOC23_EIGHT_HPP

#include "day.hpp"
#include <array>
#include <map>

namespace aoc
{

struct element
{
    std::string key;
    std::string left;
    std::string right;
};

typedef std::map<std::string, element *> elements;

class Eight final : public Day<size_t>
{
  public:
    Eight ();

    ~Eight () final;

    size_t one () final;

    size_t two () final;

    static size_t countsToTarget (const elements *elements, const std::string &instructions,
                                  const element *start, const element *goal);

  private:
    elements *_elements;
    std::string _instructions;
    elements *_endsInA;
    elements *_endsInZ;

    size_t _counts[5][5]{};

    bool done ();
};
} // aoc

#endif // AOC23_EIGHT_HPP
