#include <cassert>
#include <getopt.h>
#include <iostream>

#include "day.hpp"
#include "one.hpp"
#include "two.hpp"

int
help (int rc)
{
    std::cout << "Usage:" << std::endl;
    std::cout << "\t[--help/-h]\tShow options" << std::endl;
    std::cout << "\t[--day/-d]\tPick a day" << std::endl;
    std::cout << "\t[--puzzle/-p]\tPick a puzzle" << std::endl;
    return rc;
}

int
main (int argc, char **argv)
{
    int option, day = 0, puzzle = 0;

    struct option longOptions[] = { { "help", 0, nullptr, 'h' },
                                    { "day", 0, nullptr, 'd' },
                                    { "puzzle", 0, nullptr, 'p' },
                                    { nullptr, 0, nullptr, 0 } };

    if (argc == 1)
        {
            return help (-1);
        }

    char *input;
    char *end;
    while ((option = getopt_long (argc, argv, "hd:p:", longOptions, nullptr)) != -1)
        {
            switch (option)
                {
                case 'h':
                    return help (0);
                case 'd':
                    input = optarg;
                    day = (int)strtol (input, &end, 10);
                    break;
                case 'p':
                    input = optarg;
                    puzzle = (int)strtol (input, &end, 10);
                    break;
                default:
                    return help (EINVAL);
                }
        }

    assert (day > 0 && day <= 25);
    assert (puzzle == 1 || puzzle == 2);

    aoc::Day<int> *intSolution{};
    aoc::Day<size_t> *sizetSolution{};

    switch (day)
        {
        case 1:
            intSolution = new aoc::One ();
            break;
        case 2:
            sizetSolution = new aoc::Two ();
            break;
        default:
            throw std::runtime_error ("Illegal day!");
        }

    if (intSolution)
        {
            intSolution->solve (puzzle);
            delete intSolution;
            return 0;
        }

    if (sizetSolution)
        {
            sizetSolution->solve (puzzle);
            delete sizetSolution;
            return 0;
        }

    return EINVAL;
}
