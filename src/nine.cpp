#include "nine.hpp"
#include <regex>

aoc::Nine::Nine () : Day<int64_t> (9)
{
    this->_histories = new histories{};
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
            this->_histories->push_back (hist);
        }
}

aoc::Nine::~Nine ()
{
    for (auto h : *this->_histories)
        {
            delete h;
        }
    delete this->_histories;
}

int64_t
aoc::Nine::one ()
{
    int64_t answer = 0;

    for (const auto &row : *this->_histories)
        {
            auto *sequence = new histories{};
            this->buildRows (sequence, row);
            answer += this->findNext (sequence);
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
}

int64_t
aoc::Nine::findNext (aoc::histories *)
{
    return 0;
}
