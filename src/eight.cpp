#include "eight.hpp"
#include "regex"
#include <algorithm>
#include <ranges>
#include <set>

aoc::Eight::Eight () : Day<size_t> (8)
{
    this->_elements = new elements{};
    this->_endsInA = new elements{};
    this->_endsInZ = new elements{};

    size_t idx = 0;
    std::string line{};

    while (this->_filestream)
        {
            getline (this->_filestream, line);
            if (idx == 0)
                {
                    idx += 2;
                    this->_instructions = line;
                    continue;
                }
            if (line.empty ())
                {
                    continue;
                }
            std::string key{}, left{}, right{};
            key = line.substr (0, 3);
            left = line.substr (7, 3);
            right = line.substr (12, 3);
            auto *elem = new element{ .key = key, .left = left, .right = right };
            this->_elements->insert (std::pair<std::string, element *> (key, elem));
            if (key.at (2) == 'A')
                {
                    this->_endsInA->insert (std::pair<std::string, element *> (key, elem));
                }
            else if (key.at (2) == 'Z')
                {
                    this->_endsInZ->insert (std::pair<std::string, element *> (key, elem));
                }
        }
    assert (!this->_endsInA->empty ());
}

aoc::Eight::~Eight ()
{
    for (const auto &elem : *this->_elements)
        {
            delete elem.second;
        }
    delete this->_elements;
    delete this->_endsInA;
    delete this->_endsInZ;
}

size_t
aoc::Eight::one ()
{
    auto start = this->_elements->at ("AAA");
    auto goal = this->_elements->at ("ZZZ");
    return Eight::countsToTarget (this->_elements, this->_instructions, start, goal);
}

size_t
aoc::Eight::two ()
{
    for (const auto &e : *this->_endsInA)
        {
            auto start = this->_elements->at (e.first);
            auto loopCount = Eight::getLoopCount (this->_elements, this->_instructions, start);
            std::cout << "seed=" << e.first << " loopCount=" << loopCount << std::endl;
        }
    return 0;
}

size_t
aoc::Eight::countsToTarget (const aoc::elements *elements, const std::string &instructions,
                            const aoc::element *start, const aoc::element *goal)
{
    size_t counter = 0;
    element *current = elements->at (start->key);
    size_t i = 0;

    do
        {
            counter++;
            char instruction = instructions.at (i++);
            if (i == instructions.size ())
                {
                    i = 0;
                }
            switch (instruction)
                {
                case 'L':
                    current = elements->at (current->left);
                    break;
                case 'R':
                    current = elements->at (current->right);
                    break;
                default:
                    throw std::logic_error ("invalid instruction");
                }
        }
    while (current->key != goal->key);

    return counter;
}
size_t
aoc::Eight::getLoopCount (const aoc::elements *elements, const std::string &instructions,
                          const aoc::element *start)
{
    size_t counter = 0;
    auto *current = elements->at (start->key);
    std::set<element *> uniques{};
    size_t i = 0;

    do
        {
            counter++;
            char instruction = instructions.at (i++);
            if (i == instructions.size ())
                {
                    i = 0;
                }
            switch (instruction)
                {
                case 'L':
                    current = elements->at (current->left);
                    break;
                case 'R':
                    current = elements->at (current->right);
                    break;
                default:
                    throw std::logic_error ("invalid instruction");
                }
            uniques.insert (current);
        }
    while (uniques.size () == counter);

    return counter;
}
