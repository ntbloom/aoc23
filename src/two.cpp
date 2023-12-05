#include "two.hpp"
#include <cassert>
#include <string>
#include <vector>

aoc::Two::Two () : Day<size_t> (2) {}

size_t
aoc::Two::one ()
{
    size_t answer = 0;
    assert (this->_filestream);
    while (this->_filestream)
        {
            std::string line{};
            std::getline (this->_filestream, line);
            if (!std::equal (line.begin (), line.end (), ""))
                {
                    auto res = Two::isPossible (line);
                    if (res.at (1) == POSSIBLE)
                        {
                            answer += res.at (0);
                        }
                }
        }

    return answer;
}

size_t
aoc::Two::two ()
{
    size_t answer = 0;
    assert (this->_filestream);
    while (this->_filestream)
        {
            std::string line{};
            std::getline (this->_filestream, line);
            if (!std::equal (line.begin (), line.end (), ""))
                {
                    answer += Two::minPower (line);
                }
        }

    return answer;
}

aoc::possible_t
aoc::Two::isPossible (const std::string &input)
{
    size_t gameNum;
    char *end;
    gameNum = strtol (input.c_str () + 5, &end, 10);

    auto splitIdx = input.find_first_of (':');
    std::string secondHalf = input.substr (splitIdx + 2, input.length () - splitIdx - 2);

    size_t maxRed = 12, maxGreen = 13, maxBlue = 14;
    size_t possible = POSSIBLE;

    std::stringstream secondhalfSS (secondHalf);
    std::string chunk;
    std::vector<std::string> games;
    while (secondhalfSS.good ())
        {
            std::string game;
            getline (secondhalfSS, game, ';');
            games.push_back (game);
        }
    for (const auto &game : games)
        {
            std::stringstream gameSS (game);
            std::vector<std::string> rounds;
            while (gameSS.good ())
                {
                    std::string round;
                    getline (gameSS, round, ',');
                    rounds.push_back (round);
                }

            for (const auto &item : rounds)
                {
                    auto pos = item.find_first_of ("1234567890");
                    size_t num = strtol (&item.at (pos), &end, 10);
                    if (item.find ("blue") != std::string::npos && num > maxBlue)
                        {
                            possible = IMPOSSIBLE;
                            break;
                        }
                    if (item.find ("red") != std::string::npos && num > maxRed)
                        {
                            possible = IMPOSSIBLE;
                            break;
                        }
                    if (item.find ("green") != std::string::npos && num > maxGreen)
                        {
                            possible = IMPOSSIBLE;
                            break;
                        }
                }
        }
    return std::array<size_t, 2>{ gameNum, possible };
}

size_t
aoc::Two::minPower (const std::string &input)
{
    auto splitIdx = input.find_first_of (':');
    std::string secondHalf = input.substr (splitIdx + 2, input.length () - splitIdx - 2);

    size_t red = 0, green = 0, blue = 0;

    std::stringstream secondhalfSS (secondHalf);
    std::string chunk;
    std::vector<std::string> games;
    while (secondhalfSS.good ())
        {
            std::string game;
            getline (secondhalfSS, game, ';');
            games.push_back (game);
        }
    for (const auto &game : games)
        {
            std::stringstream gameSS (game);
            std::vector<std::string> rounds;
            while (gameSS.good ())
                {
                    std::string round;
                    getline (gameSS, round, ',');
                    rounds.push_back (round);
                }

            for (const auto &item : rounds)
                {
                    auto pos = item.find_first_of ("1234567890");
                    char *end;
                    size_t num = strtol (&item.at (pos), &end, 10);
                    if (item.find ("blue") != std::string::npos)
                        {
                            if (num > blue)
                                {
                                    blue = num;
                                }
                            continue;
                        }
                    if (item.find ("red") != std::string::npos)
                        {
                            if (num > red)
                                {
                                    red = num;
                                }
                            continue;
                        }
                    if (item.find ("green") != std::string::npos)
                        {
                            if (num > green)
                                {
                                    green = num;
                                }
                            continue;
                        }
                }
        }
    return red * blue * green;
}

aoc::Two::~Two () = default;
