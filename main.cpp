#include <iostream>
#include <getopt.h>
#include <cassert>

#include "one.hpp"
#include "day.hpp"


int
help(int rc) {
    std::cout << "Usage:" << std::endl;
    std::cout << "\t[--help/-h]\tShow options" << std::endl;
    std::cout << "\t[--day/-d]\tPick a day" << std::endl;
    std::cout << "\t[--puzzle/-p]\tPick a puzzle" << std::endl;
    return rc;
}

int
main(int argc, char **argv) {
    int option, day = 0, puzzle = 0;

    struct option longOptions[] = {
            {"help",   0, nullptr, 'h'},
            {"day",    0, nullptr, 'd'},
            {"puzzle", 0, nullptr, 'p'},
            {nullptr,  0, nullptr, 0}
    };

    if (argc == 1) {
        return help(-1);
    }

    while ((option = getopt_long(argc, argv, "hd:p:", longOptions, nullptr)) != -1) {
        switch (option) {
            case 'h':
                return help(0);
            case 'd':
                day = atoi(optarg);
                break;
            case 'p':
                puzzle = atoi(optarg);
                break;
            default:
                return help(EINVAL);
        }
    }

    assert(day > 0 && day <= 25);
    assert(puzzle == 1 || puzzle == 2);

    aoc::Day<int> *intSolution{};

    switch (day) {
        case 1:
            intSolution = new aoc::One();
            break;
        default:
            throw std::runtime_error("Illegal day!");
    }

    if (intSolution) {
        intSolution->solve(puzzle);
        delete intSolution;
        return 0;
    }

    /* holding pattern for solutions that return something besides an int */
    return EINVAL;
}
