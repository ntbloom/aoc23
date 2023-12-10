#include "nine.hpp"
#include <cstring>
#include <regex>

aoc::Nine::Nine () : Day<int64_t> (9)
{
    this->_inputLines = new histories{};
    std::regex pattern ("(-?\\d+)", std::regex_constants::ECMAScript);
    std::string line;
    char *end;
    while (this->_filestream)
        {
            getline (this->_filestream, line);
            if (line.empty ())
                {
                    break;
                }
            auto *hist = new history{};
            auto nums = std::sregex_iterator (line.begin (), line.end (), pattern);
            auto numend = std::sregex_iterator ();
            for (auto i = nums; i != numend; ++i)
                {
                    const std::smatch &match = *i;
                    auto num = strtol (match.str ().c_str (), &end, 10);
                    hist->push_back (num);
                }
            this->_inputLines->push_back (hist);
        }
}

aoc::Nine::~Nine ()
{
    for (auto h : *this->_inputLines)
        {
            delete h;
        }
    delete this->_inputLines;
}

int64_t
aoc::Nine::one ()
{
    int64_t answer = 0;

    for (const auto &input : *this->_inputLines)
        {
            auto *sequence = new histories{};
            auto *start = new history{};
            for (auto i : *input)
                {
                    start->push_back (i);
                }

            Nine::buildRows (sequence, start);

            for (auto row : *sequence)
                {
                    for (auto num : *row)
                        {
                            std::cout << num << " ";
                        }
                    std::cout << std::endl;
                }
            std::cout << std::endl;

            answer += this->findNext (sequence);
            for (auto *s : *sequence)
                {
                    delete s;
                }
            delete sequence;
        }
    return -1;
}

int64_t
aoc::Nine::two ()
{
    return -2;
}

void
aoc::Nine::buildRows (histories *sequence, history *row)
{
    sequence->push_back (row);
    if (allZeros (row))
        {
            return;
        }

    auto *next = new history{};
    for (auto i = 0; i < row->size () - 1; i++)
        {
            auto nextNum = row->at (i + 1);
            auto currNum = row->at (i);
            next->push_back (nextNum - currNum);
        }
    buildRows (sequence, next);
}

int64_t
aoc::Nine::findNext (aoc::histories *sequence)
{
    return 0;
}

bool
aoc::Nine::allZeros (aoc::history *row)
{
    for (const auto &item : *row)
        {
            if (item != 0)
                {
                    return false;
                }
        }
    return true;
}
