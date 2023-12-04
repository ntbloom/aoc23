#include "three.hpp"
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <fstream>

aoc::Three::Three () : Day<size_t> (3) {}

size_t
aoc::Three::one ()
{
    possible possibles{};
    this->process (&possibles);

    size_t count = 0;
    for (const auto &p : possibles)
        {
            if (p->valid)
                {
                    count += p->number;
                }
        }

    for (auto poss : possibles)
        {
            delete poss;
        }
    return count;
}

size_t
aoc::Three::two ()
{
    possible possibles{};
    this->process (&possibles);
    return this->reprocess ();
}

void
aoc::Three::process (possible *possibles)
{
    while (this->_filestream)
        {
            std::string line;
            getline (this->_filestream, line);
            lines.push_back (line);
        }

    std::string empty{};
    for (auto i = 0; i < lines.size (); i++)
        {
            auto above = i == 0 ? empty : lines.at (i - 1);
            auto current = lines.at (i);
            auto below = i == lines.size () - 1 ? empty : lines.at (i + 1);
            Three::processLine (i, above, current, below, possibles);
        }
}

void
aoc::Three::processLine (size_t lineNum, const std::string &above, const std::string &line,
                         const std::string &below, aoc::possible *poss)
{
    size_t numDigits = 0;
    char *end;
    possible intermediate{};

    for (auto i = line.length () - 1; i != -1; i--)
        {
            auto ch = line.at (i);
            if (isdigit (ch))
                {
                    numDigits++;
                    if (i == 0)
                        {
                            auto pn = new partNumber{
                                .number = size_t (strtol (&line.at (0), &end, 10)),
                                .x = 0,
                                .y = lineNum,
                                .len = numDigits + 1,
                                .valid = false,
                            };
                            intermediate.push_back (pn);
                            numDigits = 0;
                        }
                }
            else
                {
                    if (numDigits == 0)
                        {
                            continue;
                        }
                    else
                        {
                            auto pn = new partNumber{
                                .number = (size_t)strtol (&line.at (i + 1), &end, 10),
                                .x = i + 1,
                                .y = lineNum,
                                .len = numDigits + 1,
                                .valid = false,
                            };
                            intermediate.push_back (pn);
                            numDigits = 0;
                        }
                }
        }

    for (auto ptr : intermediate)
        {
            size_t x_begin = ptr->x == 0 ? 0 : ptr->x - 1;
            size_t length = ptr->len + 1;

            std::string allchars = line.substr (x_begin, length);
            if (!above.empty ())
                {
                    allchars += above.substr (x_begin, length);
                }
            if (!below.empty ())
                {
                    allchars += below.substr (x_begin, length);
                }
            if (allchars.find_first_of ("#$%&*+-/=@") != std::string::npos)
                {
                    ptr->valid = true;
                }

            poss->push_back (ptr);
        }
}

size_t
aoc::Three::reprocess ()
{
    auto *map = new char[140][140];

    size_t i = 0;
    for (const auto &line : this->lines)
        {
            size_t j = 0;
            for (const auto &ch : line)
                {
                    map[i][j] = ch;
                    j++;
                }
            i++;
        }

    std::vector<pair> pairs{};
    for (auto j = 0; j < LENGTH; j++)
        {
            char *row = map[j];
            char *end;
            for (auto col = 0; col < WIDTH; col++)
                {
                    char ch = row[col];
                    if (ch == '*')
                        {
                            std::vector<size_t> factors{};
                            // check left
                            if (col != 0 && isdigit (row[col - 1]))
                                {
                                    auto idx = col - 1;
                                    while (idx-- != 0 && isdigit (row[idx]))
                                        ;
                                    auto val = (size_t)strtol (&row[idx + 1], &end, 10);
                                    assert (val != 0);
                                    factors.push_back (val);
                                }
                            // check right
                            if (col != WIDTH - 1 && isdigit (row[col + 1]))
                                {
                                    auto val = (size_t)strtol (&row[col + 1], &end, 10);
                                    assert (val != 0);
                                    factors.push_back (val);
                                }

                            size_t leftIdx = col == 0 ? 0 : col - 1;
                            size_t rightIdx = col == WIDTH - 1 ? WIDTH - 1 : col + 1;

                            // look up
                            if (j != 0)
                                {
                                    findFactors (map[j - 1], leftIdx, rightIdx, &factors);
                                }
                            // look down
                            if (j != LENGTH - 1)
                                {
                                    findFactors (map[j + 1], leftIdx, rightIdx, &factors);
                                }

                            if (factors.size () == 2)
                                {
                                    auto one = factors.at (0);
                                    auto two = factors.at (1);
                                    assert (one != 0 && two != 0);
                                    pairs.push_back (pair{ one, two });
                                }
                        }
                }
        }

    // check for overflow...
    size_t answer = 0;
    for (const auto &p : pairs)
        {
            size_t orig = answer;
            auto factor = p.at (0) * p.at (1);
            answer += factor;
            assert (answer > orig);
        }

    return answer;
}
void
aoc::Three::findFactors (char *row, size_t start, size_t stop, std::vector<size_t> *factors)
{
    char *end = nullptr;
    for (auto i = 0; i <= stop; i++)
        {
            char c = row[i];
            if (isdigit (c))
                {
                    size_t beginning = i;
                    while (isdigit (row[i++]))
                        ;
                    i--;
                    if (i - 1 >= start)
                        {
                            auto val = (size_t)strtol (&row[beginning], &end, 10);
                            end = nullptr;
                            factors->push_back (val);
                        }
                }
        }
}

aoc::Three::~Three () = default;
