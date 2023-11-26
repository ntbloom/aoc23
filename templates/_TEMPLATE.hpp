#ifndef AOC23_TEMPLATE_HPP
#define AOC23_TEMPLATE_HPP

#include "day.hpp"

namespace aoc {
    class Template final : public Day<int> {
    public:
        Template();

        ~Template() final;

        void _parse() final;

        int one() final;

        int two() final;

    };
} // aoc

#endif //AOC23_TEMPLATE_HPP
