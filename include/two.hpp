#ifndef AOC23_TWO_HPP
#define AOC23_TWO_HPP

#include "day.hpp"
#include <array>

constexpr size_t POSSIBLE = 1;
constexpr size_t IMPOSSIBLE = 0;

namespace aoc
{

typedef std::array<size_t, 2> possible_t;

class Two final : public Day<size_t>
{
  public:
    Two ();

    ~Two () final;

    size_t one () final;

    size_t two () final;

    static possible_t isPossible (const std::string &input);

    static size_t minPower (const std::string &input);
};
} // aoc

#endif // AOC23_TWO_HPP
