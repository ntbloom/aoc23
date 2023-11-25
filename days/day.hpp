#ifndef AOC23_DAY_HPP
#define AOC23_DAY_HPP

#include <string>
#include <iostream>

namespace aoc {
    template<typename T>
    class Day {
    public:
        explicit Day(const std::string &day) {
            this->_day = day;
        }

        T solve(int puzzle) {
            this->_parse();
            auto answer = puzzle == 1 ? this->one() : this->two();
            std::cout << "day " << this->_day << ", puzzle " << puzzle << std::endl;
            std::cout << "\t" << answer << std::endl;
            return answer;
        }

    protected:
        virtual T one() = 0;

        virtual T two() = 0;

        virtual void _parse() = 0;

        std::string _day;

    };

} // aoc

#endif //AOC23_DAY_HPP
