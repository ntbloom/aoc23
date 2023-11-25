#include <iostream>

#include "one.hpp"
#include "day.hpp"

int main() {
    int day = 1;

    switch (day) {
        case 1:
            auto solution = new aoc::One();

        default:
            throw std::runtime_error("Illegal day!");
    }
}
