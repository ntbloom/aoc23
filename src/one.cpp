#include "one.hpp"
#include <cstring>
#include <format>
#include <fstream>
#include <vector>

aoc::One::One () : Day<int> (1) {}

void
aoc::One::_parse ()
{
}

int
aoc::One::one ()
{
    std::ifstream file;
    file.open (this->_inputFile);
    int answer = 0;
    if (file.is_open ())
        {
            while (file)
                {
                    std::string line;
                    std::getline (file, line);
                    answer += One::calibrate (line);
                }
        }

    return answer;
}

int
aoc::One::two ()
{
    std::ifstream file;
    file.open (this->_inputFile);
    int answer = 0;
    if (file.is_open ())
        {
            while (file)
                {
                    std::string line;
                    std::getline (file, line);
                    answer += One::recalibrate (line);
                }
        }

    return answer;
}

int
aoc::One::calibrate (const std::string &input)
{
    long first = 0, last = 0;
    for (char ch : input)
        {
            if (isdigit (ch))
                {
                    char *end;
                    auto num = strtol (&ch, &end, 10);
                    if (first == 0)
                        {
                            first = num;
                        }
                    else
                        {
                            last = num;
                        }
                }
        }
    if (last == 0)
        {
            last = first;
        }
    auto combined = std::format ("{}{}", first, last);
    char *end;
    return (int)strtol (combined.c_str (), &end, 10);
}

int
aoc::One::recalibrate (const std::string &input)
{
    std::vector<int> inputs (input.length ());
    std::array<std::string, 9> numbers{ "one", "two",   "three", "four", "five",
                                        "six", "seven", "eight", "nine" };

    for (unsigned long i = 0; i < input.size (); i++)
        {
            char ch = input.at (i);
            if (isdigit (ch))
                {
                    char *end;
                    intermediate[0] = ch;
                    auto num = (int)strtol (&intermediate.at (0), &end, 10);
                    if (num > 9 || num < 0)
                        {
                            throw std::logic_error ("Parsing error");
                        }
                    inputs.at (i) = num;
                }
            else
                {
                    for (unsigned long j = 0; j < numbers.size (); j++)
                        {
                            auto strNum = numbers.at (j);
                            if ((int)input.find (strNum, i) == i)
                                {
                                    inputs.at (i) = (int)j + 1;
                                }
                        }
                }
        }

    int first = 0, last = 0;
    for (const auto &i : inputs)
        {
            if (i != 0)
                {
                    if (first == 0)
                        {
                            first = i;
                        }
                    else
                        {
                            last = i;
                        }
                }
            if (last == 0)
                {
                    last = first;
                }
        }
    auto combined = std::format ("{}{}", first, last);
    char *end;
    return (int)strtol (combined.c_str (), &end, 10);
}

aoc::One::~One () = default;
