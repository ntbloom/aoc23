#include "eleven.hpp"

aoc::Eleven::Eleven () : Day<size_t> (11)
{
    std::string line;
    size_t rowIdx = 0;
    std::array<size_t, 148> columnCount{};
    while (this->_filestream)
        {
            getline (this->_filestream, line);
            if (line.empty ())
                {
                    break;
                }
            this->_lines.push_back (line);
            bool empty = true;
            for (size_t i = 0; i < line.length () - 1; i++)
                {
                    auto ch = line.at (i);
                    if (ch == '#')
                        {
                            columnCount.at (i) += 1;
                            empty = false;
                        }
                    else
                        {
                        }
                }
            if (empty)
                {
                    this->_emptyRows.insert (rowIdx);
                }
            rowIdx++;
        }
    for (auto i = 0; i < columnCount.size () - 1; i++)
        {
            if (columnCount.at (i) == 0)
                {
                    this->_emptyColumns.insert (i);
                }
        }
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
