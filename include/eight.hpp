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
    size_t loopCount;
    size_t countToZ;
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

    static size_t getLoopCount (const elements *elements, const std::string &instructions,
                                const element *start);

    static size_t getToZend (const elements *elements, const std::string &instructions,
                             const element *start);

  private:
    elements *_elements;
    std::string _instructions;
    elements *_endsInA;
    elements *_endsInZ;
};
} // aoc

#endif // AOC23_EIGHT_HPP
