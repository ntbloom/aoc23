#ifndef AOC23_TEMPLATE_HPP
#define AOC23_TEMPLATE_HPP

#include "day.hpp"

namespace aoc
{
class Template final : public Day<TYPE>
{
  public:
    Template ();

    ~Template () final;

    void _parse () final;

    TYPE one () final;

    TYPE two () final;
};
} // aoc

#endif // AOC23_TEMPLATE_HPP
