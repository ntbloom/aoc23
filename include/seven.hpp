#ifndef AOC23_SEVEN_HPP
#define AOC23_SEVEN_HPP

#include "day.hpp"

namespace aoc
{

enum score
{
    FIVE_OF_A_KIND = 6,
    FOUR_OF_A_KIND = 5,
    FULL_HOUSE = 4,
    THREE_OF_A_KIND = 3,
    TWO_PAIR = 2,
    ONE_PAIR = 1,
    HIGH_CARD = 0,
};

struct hand
{
    std::string cards;
    size_t bid;
    score handScore;
    size_t rank;
    size_t points;

    hand (std::string cards, size_t bid, bool adjusted);

    static score getScore (std::string &cards);

    static score getAdjustedScore (std::string &cards);
};

typedef std::array<hand *, 1000> hands;

class Seven final : public Day<size_t>
{
  public:
    Seven ();

    ~Seven () final;

    size_t one () final;

    size_t two () final;

  private:
    hands *_hands;
};
} // aoc

bool compare (const aoc::hand *one, const aoc::hand *two);

#endif // AOC23_SEVEN_HPP
