#include "nine.hpp"
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
            auto firstRow = sequence->at (0);
            auto before = firstRow->at (firstRow->size () - 1);

            Nine::addNext (sequence);
            answer += firstRow->at (firstRow->size () - 1);

            for (auto *s : *sequence)
                {
                    delete s;
                }
            delete sequence;
        }
    return answer;
}

int64_t
aoc::Nine::two ()
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
            auto firstRow = sequence->at (0);
            Nine::addPrev (sequence);
            auto first = firstRow->at (0);
            answer += first;

            for (auto *s : *sequence)
                {
                    delete s;
                }
            delete sequence;
        }
    return answer;
}

void
aoc::Nine::buildRows (histories *sequence, history *row)
{
    sequence->push_back (row);
    if (allZeros (row))
        {
            row->push_back (0);
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

void
aoc::Nine::addNext (aoc::histories *sequence)
{
    for (auto i = sequence->size () - 1; i != 0; i--)
        {
            auto current = sequence->at (i);
            auto above = sequence->at (i - 1);
            auto currentEnd = current->at (current->size () - 1);
            auto aboveEnd = above->at (above->size () - 1);
            above->push_back (currentEnd + aboveEnd);
        }
}

void
aoc::Nine::addPrev (aoc::histories *sequence)
{
    for (auto i = sequence->size () - 1; i != 0; i--)
        {
            auto current = sequence->at (i);
            auto above = sequence->at (i - 1);
            auto currentStart = current->at (0);
            auto aboveStart = above->at (0);

            above->insert (above->begin (), aboveStart - currentStart);
        }
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
