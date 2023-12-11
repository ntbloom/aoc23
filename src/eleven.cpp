#include "eleven.hpp"

aoc::Eleven::Eleven () : Day<size_t> (11)
{
    std::string line;
    size_t rowIdx = 0;
    while (this->_filestream)
        {
            getline (this->_filestream, line);
            if (line.empty ())
                {
                    break;
                }
            this->_lines.push_back (line);
            bool empty = true;
            for (auto i = 0; i < line.length () - 1; i++)
                {
                    auto ch = line.at (i);
                    if (ch == '#')
                        {
                            empty = false;
                            break;
                        }
                }
            if (empty)
                {
                    this->_emptyRows.push_back (rowIdx);
                }
            rowIdx++;
        }
    /* find a way to mark empty columns */
}

size_t
aoc::Eleven::one ()
{
    return -1;
}

size_t
aoc::Eleven::two ()
{
    return -2;
}

aoc::Eleven::~Eleven () = default;
