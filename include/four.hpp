#ifndef AOC23_FOUR_HPP
#define AOC23_FOUR_HPP

#include "day.hpp"
#include <set>
#include <stack>

namespace aoc
{

typedef std::set<size_t> numbers;
struct card
{
    size_t idx;
    size_t winners;
};

class Four final : public Day<size_t>
{
  public:
    Four ();

    ~Four () final;

    size_t one () final;

    size_t two () final;

    static void getNums (const std::string &line, numbers *winners, numbers *yours);

    void drawCard ();

    static constexpr size_t
    getFactor (size_t matches)
    {
        switch (matches)
            {
            case 0:
                return 0;
            case 1:
                return 1;
            default:
                return 2 << (matches - 2);
            }
    }

    static constexpr std::string
    getReg ()
    {
        std ::string patternBuilder ("Card\\s+\\d+:\\s+");
        for (auto i = 0; i < 10; i++)
            {
                patternBuilder += "(\\d+)\\s+";
            }
        patternBuilder += "\\|\\s+";
        for (auto i = 0; i < 24; i++)
            {
                patternBuilder += "(\\d+)\\s+";
            }
        patternBuilder += "(\\d+)";
        return patternBuilder;
    };

    size_t answerOne = 0;
    size_t answerTwo = 0;
    static constexpr size_t CARD_MAX = 209;
    card cards[CARD_MAX + 1];

    std::stack<card> cardStack;

    size_t lineNum = 0;
};
} // aoc

#endif // AOC23_FOUR_HPP
