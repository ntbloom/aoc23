#ifndef AOC23_DAY_HPP
#define AOC23_DAY_HPP

#include <cassert>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

typedef std::chrono::steady_clock steadyTimer_t;
typedef std::chrono::duration<long, std::ratio<1, 1000000000> > nanosecDuration_t;
typedef std::chrono::time_point<steadyTimer_t, nanosecDuration_t> timestamp_t;

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
        this->_filestream.open (this->_inputFile);
        if (!this->_filestream.is_open ())
            {
                throw std::runtime_error ("unable to open file");
            }
    }

    virtual ~Day () { this->_filestream.close (); };

    T
    solve (int puzzle)
    {
        timestamp_t start, stop;

        start = steadyTimer_t::now ();
        auto answer = puzzle == 1 ? this->one () : this->two ();
        stop = steadyTimer_t::now ();
        auto duration = stop - start;

        std::string border{ "**************************************" };
        std::cout << border << std::endl;
        std::cout << "            Day " << this->_num << "/Puzzle " << puzzle << std::endl;
        std::cout << "Answer = " << answer << std::endl;
        std::cout << "Duration (μs) = " << duration.count () / 1000 << std::endl;
        std::cout << border << std::endl;

        return answer;
    }

  protected:
    virtual T
    one ()
    {
        return 0;
    };

    virtual T
    two ()
    {
        return 0;
    };

    int _num;
    std::filesystem::path _inputFile;
    std::ifstream _filestream;
};

} // aoc

#endif // AOC23_DAY_HPP
