#include "template.hpp"

aoc::Template::Template () : Day<TYPE> (X) {}

TYPE
aoc::Template::one ()
{
    return -1;
}

TYPE
aoc::Template::two ()
{
    return -2;
}

aoc::Template::~Template () = default;
