#ifndef AOC23_FIVE_HPP
#define AOC23_FIVE_HPP

#include "day.hpp"
#include <atomic>

const std::string seed2soilMap ("seed-to-soil map:");
const std::string soil2fertMap ("soil-to-fertilizer map:");
const std::string fert2waterMap ("fertilizer-to-water map:");
const std::string water2lightMap ("water-to-light map:");
const std::string light2tempMap ("light-to-temperature map:");
const std::string temp2humidMap ("temperature-to-humidity map:");
const std::string humid2locationMap ("humidity-to-location map:");

static constexpr size_t NPROC = 16;

namespace aoc
{

struct seedRanges
{
    size_t start;
    size_t range;
};

struct gardenNums
{
    ssize_t destStart;
    ssize_t sourceStart;
    ssize_t length;

    [[nodiscard]] ssize_t
    getDest (ssize_t seed) const
    {
        if ((seed < sourceStart) || (seed > (sourceStart + length - 1)))
            {
                return -1;
            }
        ssize_t diff = seed - sourceStart;
        return destStart + diff;
    }
};

class Five final : public Day<size_t>
{
  public:
    Five ();

    ~Five () final;

    size_t one () final;

    size_t two () final;

    void parseSeeds (const std::string &line);

    static void parseNumbers (const std::string &line, gardenNums *nums);

    void getLowestFromPair (size_t start, size_t range, size_t *lowest);

    ssize_t getLoc (ssize_t seedNum);

    size_t seed2soil = 0, soil2fert = 0, fert2water = 0, water2light = 0, light2temp = 0,
           temp2humid = 0, humid2loc = 0;

    std::vector<size_t> seeds{};
    std::vector<std::string> *lines;
};

bool compare (seedRanges one, seedRanges two);
} // aoc

#endif // AOC23_FIVE_HPP
