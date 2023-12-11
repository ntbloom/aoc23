#include "ten.hpp"

aoc::Ten::Ten () : Day<size_t> (10)
{
    this->_map = new pipeMap{};
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
                    auto ch = line.at (idx++);
                    auto *node = new pipeNode{};
                    node->value = ch;
                    this->_map->at (lineNum).at (col) = node;
                    if (ch == 'S')
                        {
                            start = std::pair<size_t, size_t> (lineNum, col);
                        }
                }
            lineNum++;
        }
}

aoc::Ten::~Ten ()
{
    for (auto row : *this->_map)
        {
            for (auto node : row)
                {
                    delete node;
                }
        }
    delete this->_map;
}

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
    for (auto &row : *this->_map)
        {
            for (const auto &col : row)
                {
                    std::cout << col->value;
                }
            std::cout << "\n";
        }
}
