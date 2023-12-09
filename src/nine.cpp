#include "nine.hpp"
#include <regex>

aoc::Nine::Nine () : Day<size_t> (9)
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

size_t
aoc::Nine::one ()
{

    return -1;
}

size_t
aoc::Nine::two ()
{
    return -2;
}

aoc::Nine::~Nine ()
{
    for (auto hist : *this->_histories)
        {
            delete hist;
        }
    delete this->_histories;
}
