#include "seven.hpp"
#include <map>
#include <utility>

aoc::Seven::Seven () : Day<size_t> (7) { this->_hands = new hands{}; }

size_t
aoc::Seven::one ()
{
    size_t counter = 0;
    std::string line{};
    char *end;
    while (this->_filestream && counter < 1000)
        {
            getline (this->_filestream, line);
            this->_hands->at (counter++) = new hand (
                line.substr (0, 5), (size_t)strtol (line.substr (6).c_str (), &end, 10), false);
        }

    size_t total = 0;
    std::stable_sort (this->_hands->begin (), this->_hands->end (), compare);

    for (auto i = 0; i < this->_hands->size (); i++)
        {
            auto hand = this->_hands->at (i);
            hand->rank = 1000 - i;
            hand->points = hand->rank * hand->bid;
            total += hand->points;
        }

    return total;
}

size_t
aoc::Seven::two ()
{
    size_t counter = 0;
    std::string line{};
    char *end;
    while (this->_filestream && counter < 1000)
        {
            getline (this->_filestream, line);
            this->_hands->at (counter++) = new hand (
                line.substr (0, 5), (size_t)strtol (line.substr (6).c_str (), &end, 10), true);
        }

    size_t total = 0;
    std::stable_sort (this->_hands->begin (), this->_hands->end (), compare);

    for (auto i = 0; i < this->_hands->size (); i++)
        {
            auto hand = this->_hands->at (i);
            hand->rank = 1000 - i;
            hand->points = hand->rank * hand->bid;
            total += hand->points;
        }

    return total;
    return -2;
}

aoc::Seven::~Seven ()
{
    for (auto hand : *this->_hands)
        {
            delete hand;
        }
    delete this->_hands;
}

aoc::score
aoc::hand::getScore (std::string &cards)
{
    size_t score = aoc::score::HIGH_CARD;
    std::map<char, size_t> letters{};
    char T = 'A';
    char J = 'B';
    char Q = 'C';
    char K = 'D';
    char A = 'E';
    for (auto i = 0; i < cards.length (); i++)
        {
            /* rearrange face cards to ordered numbers so we can just do a gt/lt comparison */
            switch (cards.at (i))
                {
                case 'T':
                    cards.at (i) = T;
                    break;
                case 'J':
                    cards.at (i) = J;
                    break;
                case 'Q':
                    cards.at (i) = Q;
                    break;
                case 'K':
                    cards.at (i) = K;
                    break;
                case 'A':
                    cards.at (i) = A;
                    break;
                default:
                    break;
                }
            auto ch = cards.at (i);
            if (letters.contains (ch))
                {
                    letters.at (ch)++;
                }
            else
                {
                    letters.insert (std::pair<char, size_t> (ch, 1));
                }
        }
    for (auto &letter : letters)
        {

            switch (letter.second)
                {
                case 1:
                    continue;
                case 2:
                    score++;
                    break;
                case 3:
                    score += 3;
                    break;
                case 4:
                    score += 5;
                    break;
                case 5:
                    score += 6;
                    break;
                default:
                    throw std::logic_error ("illegal count");
                }
        }
    return static_cast<aoc::score> (score);
}

aoc::score
aoc::hand::getAdjustedScore (std::string &cards)
{
    size_t score = aoc::score::HIGH_CARD;
    std::map<char, size_t> letters{};
    char T = 'A';
    char J = '0';
    char Q = 'C';
    char K = 'D';
    char A = 'E';

    size_t jokers = 0;
    for (auto i = 0; i < cards.length (); i++)
        {
            /* rearrange face cards to ordered numbers so we can just do a gt/lt comparison */
            switch (cards.at (i))
                {
                case 'T':
                    cards.at (i) = T;
                    break;
                case 'J':
                    jokers++;
                    cards.at (i) = J;
                    break;
                case 'Q':
                    cards.at (i) = Q;
                    break;
                case 'K':
                    cards.at (i) = K;
                    break;
                case 'A':
                    cards.at (i) = A;
                    break;
                default:
                    break;
                }
            auto ch = cards.at (i);
            if (letters.contains (ch))
                {
                    letters.at (ch)++;
                }
            else
                {
                    letters.insert (std::pair<char, size_t> (ch, 1));
                }
        }
    for (auto &letter : letters)
        {
            switch (letter.second)
                {
                case 1:
                    continue;
                case 2:
                    score++;
                    break;
                case 3:
                    score += 3;
                    break;
                case 4:
                    score += 5;
                    break;
                case 5:
                    score += 6;
                    break;
                default:
                    throw std::logic_error ("illegal count");
                }
        }
    auto intermediate = static_cast<aoc::score> (score);
    switch (jokers)
        {
        case 0:
            return static_cast<aoc::score> (score);
        case 1:
            switch (intermediate)
                {
                case FOUR_OF_A_KIND:
                    return score::FIVE_OF_A_KIND;
                case THREE_OF_A_KIND:
                    return score::FOUR_OF_A_KIND;
                case TWO_PAIR:
                    return score::FULL_HOUSE;
                case ONE_PAIR:
                    return score::THREE_OF_A_KIND;
                case HIGH_CARD:
                    return score::ONE_PAIR;
                default:
                    throw;
                }
        case 2:
            switch (intermediate)
                {
                case FULL_HOUSE:
                    return score::FIVE_OF_A_KIND;
                case THREE_OF_A_KIND:
                    return score::FIVE_OF_A_KIND;
                case TWO_PAIR:
                    return score::FOUR_OF_A_KIND;
                case ONE_PAIR:
                    return score::THREE_OF_A_KIND; // jacks must be the pair
                case HIGH_CARD:
                    return score::THREE_OF_A_KIND;
                default:
                    throw;
                }
        case 3:
            switch (intermediate)
                {
                case FULL_HOUSE:
                    return score::FIVE_OF_A_KIND; // jacks add to other pair
                case THREE_OF_A_KIND:
                    return score::FOUR_OF_A_KIND; //  jacks add to a single other card
                case HIGH_CARD:
                    return score::FOUR_OF_A_KIND;
                default:
                    throw;
                }
        case 4:
            return score::FIVE_OF_A_KIND;
        case 5:
            return score::FIVE_OF_A_KIND;
        default:
            throw;
        }
    throw;
}

aoc::hand::hand (std::string cards, size_t bid, bool adjusted)
{
    this->cards = std::move (cards);
    this->bid = bid;
    this->handScore
        = adjusted ? hand::getAdjustedScore (this->cards) : hand::getScore (this->cards);
    this->rank = 0;
    this->points = 0;
}

bool
compare (const aoc::hand *one, const aoc::hand *two)
{
    if (one->handScore != two->handScore)
        {
            return one->handScore > two->handScore;
        }
    auto idx = 0;
    while (one->cards.at (idx) == two->cards.at (idx))
        {
            idx++;
        }
    return one->cards.at (idx) > two->cards.at (idx);
}
