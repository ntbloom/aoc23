#include "eight.hpp"
#include "regex"
#include <algorithm>
#include <ranges>

aoc::Eight::Eight () : Day<size_t> (8)
{
    this->_elements = new elements{};
    this->_endsInA = new std::map<std::string, element *>{};

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
        }
    assert (!this->_endsInA->empty ());
}

size_t
aoc::Eight::one ()
{
    size_t counter = 0;
    std::string target ("ZZZ");
    std::string first = ("AAA");
    element *current = this->_elements->at (first);

    std::string instructions = this->_instructions;
    size_t i = 0;

    while (current->key != target)
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
                    current = this->_elements->at (current->left);
                    break;
                case 'R':
                    current = this->_elements->at (current->right);
                    break;
                default:
                    throw std::logic_error ("invalid instruction");
                }
        }

    return counter;
}

size_t
aoc::Eight::two ()
{

    size_t counter = 0;
    std::string instructions = this->_instructions;
    size_t i = 0;
    while (!done ())
        {
            counter++;
            char instruction = instructions.at (i++);
            if (i == instructions.size ())
                {
                    i = 0;
                }

            for (auto &elem : *this->_endsInA)
                {
                    element *next;
                    switch (instruction)
                        {
                        case 'L':
                            next = this->_elements->at (elem.second->left);
                            elem.second = next;
                            break;
                        case 'R':
                            next = this->_elements->at (elem.second->right);
                            elem.second = next;
                            break;
                        default:
                            throw std::logic_error ("bad code!");
                        }
                }
        }
    return counter;
}

bool
aoc::Eight::done ()
{
    for (const auto &elem : *this->_endsInA)
        {
            if (elem.second->key.at (2) != 'Z')
                {
                    return false;
                }
        }
    return true;
}

aoc::Eight::~Eight ()
{
    for (const auto &elem : *this->_elements)
        {
            delete elem.second;
        }
    delete this->_elements;
    delete this->_endsInA;
}
