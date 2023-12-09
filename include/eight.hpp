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

  private:
    elements *_elements;
    std::string _instructions;
    elements *_endsInA;

    bool done ();
};
} // aoc

#endif // AOC23_EIGHT_HPP
