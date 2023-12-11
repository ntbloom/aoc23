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
            for (size_t col = 0; col < 140; col++)
                {
                    auto ch = line.at (idx++);
                    auto *node = new pipeNode{
                        .north = nullptr,
                        .south = nullptr,
                        .east = nullptr,
                        .west = nullptr,
                        .visited = false,
                        .x = lineNum,
                        .y = col,
                        .value = ch,
                    };
                    this->_map->at (lineNum).at (col) = node;
                    if (ch == 'S')
                        {
                            this->_start = node;
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
    this->dfs (this->_start);
    //    printMap ();
    return count / 2;
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
                    if (col->visited)
                        {
                            std::cout << "\033[0;31m";
                        }
                    std::cout << col->value;
                    if (col->visited)
                        {
                            std::cout << "\033[0m";
                        }
                }
            std::cout << "\n";
        }
}

void
aoc::Ten::findNeighbors (aoc::pipeNode *node)
{
    pipeNode *potentialNorth = nullptr, *potentialSouth = nullptr, *potentialEast = nullptr,
             *potentialWest = nullptr;
    if (node->x != 0)
        {
            potentialNorth = this->_map->at (node->x - 1).at (node->y);
        }
    if (node->x != 139)
        {
            potentialSouth = this->_map->at (node->x + 1).at (node->y);
        }
    if (node->y != 0)
        {
            potentialWest = this->_map->at (node->x).at (node->y - 1);
        }
    if (node->y != 139)
        {
            potentialEast = this->_map->at (node->x).at (node->y + 1);
        }
    switch (node->value)
        {
        case '|':
            node->north = fromSouth (potentialNorth) ? potentialNorth : nullptr;
            node->south = fromNorth (potentialSouth) ? potentialSouth : nullptr;
            break;
        case '-':
            node->west = fromEast (potentialWest) ? potentialWest : nullptr;
            node->east = fromWest (potentialEast) ? potentialEast : nullptr;
            break;
        case 'L':
            node->east = fromWest (potentialEast) ? potentialEast : nullptr;
            node->north = fromSouth (potentialNorth) ? potentialNorth : nullptr;
            break;
        case 'J':
            node->west = fromEast (potentialWest) ? potentialWest : nullptr;
            node->north = fromSouth (potentialNorth) ? potentialNorth : nullptr;
            break;
        case '7':
            node->west = fromEast (potentialWest) ? potentialWest : nullptr;
            node->south = fromNorth (potentialSouth) ? potentialSouth : nullptr;
            break;
        case 'F':
            node->east = fromWest (potentialEast) ? potentialEast : nullptr;
            node->south = fromNorth (potentialSouth) ? potentialSouth : nullptr;
            break;
        case 'S':
            node->north = potentialNorth;
            node->south = potentialSouth;
            node->west = potentialWest;
            node->east = potentialEast;
            break;
        }
}
bool
aoc::Ten::fromSouth (aoc::pipeNode *node)
{
    if (!node)
        {
            return false;
        }
    switch (node->value)
        {
        case '|':
            return true;
        case '7':
            return true;
        case 'F':
            return true;
        default:
            return false;
        }
}
bool
aoc::Ten::fromNorth (aoc::pipeNode *node)
{
    if (!node)
        {
            return false;
        }
    switch (node->value)
        {
        case '|':
            return true;
        case 'L':
            return true;
        case 'J':
            return true;
        default:
            return false;
        }
}
bool
aoc::Ten::fromWest (aoc::pipeNode *node)
{
    if (!node)
        {
            return false;
        }
    switch (node->value)
        {
        case '-':
            return true;
        case 'J':
            return true;
        case '7':
            return true;
        default:
            return false;
        }
}
bool
aoc::Ten::fromEast (aoc::pipeNode *node)
{
    if (!node)
        {
            return false;
        }
    switch (node->value)
        {
        case '-':
            return true;
        case 'L':
            return true;
        case 'F':
            return true;
        default:
            return false;
        }
}

void
aoc::Ten::dfs (aoc::pipeNode *node)
{
    node->visited = true;
    if (count++ != 0 && node == this->_start)
        {
            return;
        }
    this->findNeighbors (node);
    for (auto n : std::array<pipeNode *, 4>{ node->north, node->south, node->east, node->west })
        {
            if (n && !n->visited)
                {
                    dfs (n);
                }
        }
}

bool
operator== (const aoc::pipeNode &one, const aoc::pipeNode &two)
{
    return one.x == two.x && one.y == two.y;
}
