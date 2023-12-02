#ifndef AOC23_DAY_HPP
#define AOC23_DAY_HPP

#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>

namespace aoc
{
template <typename T> class Day
{
  public:
    explicit Day (int num)
    {
        this->_num = num;
        std::stringstream filename;
        filename << num << ".txt";
        this->_inputFile = std::filesystem::current_path () / std::filesystem::path{ "inputs" }
                           / std::filesystem::path{ filename.str () };
        if (!exists (this->_inputFile))
            {
                std::stringstream err;
                err << absolute (this->_inputFile) << " doesn't exist";
                throw std::runtime_error (err.str ());
            }
    }

    virtual ~Day () = default;

    T
    solve (int puzzle)
    {
        auto answer = puzzle == 1 ? this->one () : this->two ();
        std::string border{ "**************************************" };
        std::cout << border << std::endl;
        std::cout << "Day " << this->_num << "/Puzzle " << puzzle << std::endl;
        std::cout << "Answer = " << answer << std::endl;
        std::cout << border << std::endl;

        return answer;
    }

  protected:
    virtual T one () = 0;

    virtual T two () = 0;

    int _num;
    std::filesystem::path _inputFile;
};

} // aoc

#endif // AOC23_DAY_HPP
