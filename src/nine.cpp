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
                    auto *n = new node{ .value = num, .left = nullptr, .right = nullptr };
                    hist->push_back (n);
                }
            this->_histories->push_back (hist);
        }
}

aoc::Nine::~Nine ()
{
    for (auto hist : *this->_histories)
        {
            for (auto n : *hist)
                {
                    delete n;
                }
            delete hist;
        }
    delete this->_histories;
}

int64_t
aoc::Nine::one ()
{
    return -1;
}

int64_t
aoc::Nine::two ()
{
    return -2;
}

aoc::node *
aoc::Nine::buildTree (aoc::history *hist)
{
    //    auto *root = new node ();
    return nullptr;
}
