#include "six.hpp"
#include <regex>

aoc::Six::Six () : Day<size_t> (6)
{
    this->_races = new races{};
    std::array<size_t, 4> times{};
    std::array<size_t, 4> distances{};
    size_t idx = 0;
    std::string line{};
    std::regex pattern ("(\\d+)", std::regex_constants::ECMAScript);

    char *end = nullptr;
    while (this->_filestream)
        {
            getline (this->_filestream, line);
            {
                size_t numIdx = 0;
                auto nums = std::sregex_iterator (line.begin (), line.end (), pattern);
                auto numEnd = std::sregex_iterator ();
                for (auto i = nums; i != numEnd; ++i)
                    {
                        const std::smatch &match = *i;
                        auto num = (size_t)strtol (match.str ().c_str (), &end, 10);
                        if (idx == 0)
                            {
                                times.at (numIdx) = num;
                            }
                        else
                            {
                                distances.at (numIdx) = num;
                            }
                        numIdx++;
                    }
            }
            idx++;
        }
    for (auto i = 0; i < times.size (); i++)
        {
            this->_races->at (i) = race{ .time = times.at (i), .distance = distances.at (i) };
        }
}

size_t
aoc::Six::one ()
{

    std::cout << "\ntim dst sta sto win" << std::endl;
    size_t answer = 1;
    for (auto &race : *this->_races)
        {
            size_t idx = 0;
            while (!wins (race, idx++))
                ;
            race.winStart = idx - 1;
            while (wins (race, idx++))
                ;
            race.winStop = idx - 2;
            race.wins = race.winStop - race.winStart + 1;
            answer *= race.wins;
        }

    return answer;
}

size_t
aoc::Six::two ()
{
    std::stringstream times{}, distances{};
    for (const auto &race : *this->_races)
        {
            times << std::to_string (race.time);
            distances << std::to_string (race.distance);
        }
    char *end;
    race race{
        .time = (size_t)strtol (times.str ().c_str (), &end, 10),
        .distance = (size_t)strtol (distances.str ().c_str (), &end, 10),
    };

    size_t idx = 0;
    while (!wins (race, idx++))
        ;
    race.winStart = idx - 1;
    while (wins (race, idx++))
        ;
    race.winStop = idx - 2;
    return race.winStop - race.winStart + 1;
}

bool
aoc::Six::wins (const aoc::race &race, size_t holdMs)
{
    return ((race.time - holdMs) * holdMs) > race.distance;
}

aoc::Six::~Six () { delete this->_races; }
