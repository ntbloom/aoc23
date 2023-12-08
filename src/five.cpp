#include "five.hpp"
#include "regex"
#include <thread>

aoc::Five::Five () : Day<size_t> (5)
{
    lines = new std::vector<std::string>{};
    size_t lineNum = 0;

    while (this->_filestream)
        {
            std::string line{};
            getline (this->_filestream, line);
            lines->push_back (line);
        }

    size_t counter = 0;
    for (const auto &line : *lines)
        {
            counter++;
            if (lineNum++ == 0)
                {
                    parseSeeds (line);
                }
            if (line.empty () || isdigit (line.at (0)))
                {
                    continue;
                }
            if (line == seed2soilMap)
                {
                    seed2soil = counter;
                    continue;
                }
            if (line == soil2fertMap)
                {
                    soil2fert = counter;
                    continue;
                }
            if (line == fert2waterMap)
                {
                    fert2water = counter;
                    continue;
                }
            if (line == water2lightMap)
                {
                    water2light = counter;
                    continue;
                }
            if (line == light2tempMap)
                {
                    light2temp = counter;
                    continue;
                }
            if (line == temp2humidMap)
                {
                    temp2humid = counter;
                    continue;
                }
            if (line == humid2locationMap)
                {
                    humid2loc = counter;
                    continue;
                }
        }

    assert (!seeds.empty ());
    for (auto i : std::vector<size_t>{ seed2soil, soil2fert, fert2water, water2light, light2temp,
                                       temp2humid, humid2loc })
        {
            assert (i);
        }
}

size_t
aoc::Five::one ()
{
    size_t lowest = UINT64_MAX;
    for (auto seed : seeds)
        {
            auto num = getLoc ((ssize_t)seed);
            if (num < lowest)
                {
                    lowest = num;
                }
        }
    return lowest;
}

size_t
aoc::Five::two ()
{
    size_t start, range;

    size_t unaligned = 0;
    auto ranges = std::vector<seedRanges>{};
    for (auto i = 0; i < seeds.size (); i++)
        {
            if (i == 2 || i % 2 == 0)
                {
                    start = seeds.at (i);
                    range = seeds.at (++i);
                    auto group = seedRanges{ .start = start, .range = range };
                    unaligned += group.range;
                    ranges.push_back (group);
                }
        }
    std::sort (ranges.begin (), ranges.end (), compare);
    std::vector<seedRanges> actual{};

    for (auto i = 0; i < ranges.size () - 1; i++)
        {
            auto curr = ranges.at (i);
            actual.push_back (curr);
            if (i == ranges.size () - 1)
                {
                    break;
                }

            auto next = ranges.at (i + 1);
            assert (curr.start < next.start);
            while ((curr.start + curr.range) > (next.start + next.range))
                {
                    next = ranges.at (++i);
                }
            if ((curr.start + curr.range) > next.start)
                {
                    auto diff = curr.start + curr.range - next.start + 1;
                    next.start += diff;
                    next.range -= diff;
                }
        }
    size_t aligned = 0;
    for (auto rg : actual)
        {
            aligned += rg.range;
        }
    //    std::cout << "unaligned=\t" << unaligned << std::endl;
    //    std::cout << "aligned=\t" << aligned << std::endl;
    //    std::cout << "pairs\t=" << actual.size () << std::endl;

    for (auto ac : actual)
        {
            std::cout << "start=" << ac.start << " range=" << ac.range << std::endl;
        }

    std::vector<size_t> candidates{};
    for (auto i = 0; i < actual.size () - 1; i++)
        {
            auto num = std::atomic<size_t> (UINT64_MAX);
            candidates.push_back (num);
        }

    std::vector<std::thread *> threads{};
    for (auto i = 0; i < actual.size () - 1; i++)
        {
            //            auto *job = new std::thread (&Five::getLowestFromPair, this, actual.at
            //            (i).start,
            //                                         actual.at (i).range, &candidates.at (i));
            auto *job = new std::thread ([] {});
            threads.push_back (job);
        }
    for (const auto &t : threads)
        {
            t->join ();
            delete t;
        }

    size_t lowest = UINT64_MAX;
    for (auto i : candidates)
        {
            if (i < lowest)
                {
                    lowest = i;
                }
        }
    return lowest;
}

void
aoc::Five::getLowestFromPair (size_t start, size_t range, size_t *lowest)
{
    for (size_t j = 0; j < range; j++)
        {
            auto num = getLoc ((ssize_t)start + j);
            if (num < *lowest)
                {
                    *lowest = num;
                }
        }
}

void
aoc::Five::parseSeeds (const std::string &line)
{
    assert (line.substr (0, 7) == "seeds: ");
    char *end = nullptr;
    for (size_t i = 7; i < line.length () - 1; i++)
        {
            while (i != line.length () - 1 && !isdigit (line.at (i)))
                {
                    i++;
                }
            auto num = ((size_t)strtol (&line.at (i), &end, 10));
            seeds.push_back (num);
            while (i != line.length () - 1 && isdigit (line.at (i)))
                {
                    i++;
                };
        }
}

void
aoc::Five::parseNumbers (const std::string &line, gardenNums *nums)
{
    size_t zero = 0, one = 0, two = 0;
    for (auto i = 0; i < line.length () - 1; i++)
        {
            if (line.at (i) == ' ')
                {
                    if (!one)
                        {
                            one = i;
                        }
                    else
                        {
                            two = i;
                        }
                }
        }
    char *end = nullptr;
    nums->destStart = (ssize_t)strtol (&line.at (zero), &end, 10);
    nums->sourceStart = (ssize_t)strtol (&line.at (one), &end, 10);
    nums->length = (ssize_t)strtol (&line.at (two), &end, 10);

    std::stringstream ss;
    ss << nums->destStart << " " << nums->sourceStart << " " << nums->length;
    assert (ss.str () == line);
}

ssize_t
aoc::Five::getLoc (ssize_t seedNum)
{

    ssize_t target = seedNum;
    for (auto mapIdx : std::vector<size_t>{ seed2soil, soil2fert, fert2water, water2light,
                                            light2temp, temp2humid, humid2loc })
        {
            size_t i = mapIdx;
            gardenNums line{};
            ssize_t found;
            std::string ln = lines->at (i);
            do
                {
                    parseNumbers (ln, &line);
                    found = line.getDest (target);
                    ln = lines->at (++i);
                }
            while (found == -1 && !ln.empty ());
            target = found == -1 ? target : found;
        }
    assert (target != -1);
    return target;
}

aoc::Five::~Five () { delete lines; }

bool
aoc::compare (aoc::seedRanges one, aoc::seedRanges two)
{
    return (one.start < two.start);
}
