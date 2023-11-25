#ifndef AOC23_ONE_HPP
#define AOC23_ONE_HPP

#include "day.hpp"

namespace aoc {
    class One : public Day<int> {
    public:
        One();

        void _parse() override;

        int one() override;

        int two() override;

    };
} // aoc

#endif //AOC23_ONE_HPP
