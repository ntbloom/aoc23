#include "ten.hpp"

aoc::Ten::Ten () : Day<size_t> (10)
{
    std::string line;
    size_t lineNum = 0;
    while (this->_filestream)
        {
            getline (this->_filestream, line);
            if (line.empty ())
                {
                    break;
                }
            auto idx = 0;
            for (auto col = 0; col < 140; col++)
                {
                    this->_map[lineNum][col] = (line.at (idx++));
                }
            lineNum++;
        }
}

aoc::Ten::~Ten () = default;

size_t
aoc::Ten::one ()
{
    printMap ();
    return -1;
}

size_t
aoc::Ten::two ()
{
    return -2;
}

void
aoc::Ten::printMap ()
{
    for (auto &row : this->_map)
        {
            for (unsigned char col : row)
                {
                    std::cout << col;
                }
            std::cout << "\n";
        }
}
