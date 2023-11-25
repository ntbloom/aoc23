#include "one.hpp"
#include <cassert>

aoc::One::One() : Day<int>(std::string{"one"}) {
}

void aoc::One::_parse() {
    std::cout << "calling member parse" << std::endl;
}

int aoc::One::one() {
    return 1;
}

int aoc::One::two() {
    return 2;
}


int main(int argc, char **argv) {
    auto one = aoc::One();
    assert(argc == 2);
    int day = atoi(argv[1]);
    assert(day == 1 || day == 2);
    return one.solve(day);
}
