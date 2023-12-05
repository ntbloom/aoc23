#include "four.hpp"
#include <regex>

aoc::Four::Four () : Day<size_t> (4)
{

    assert (this->_filestream);
    while (this->_filestream)
        {
            std::string line{};
            getline (this->_filestream, line);
            numbers winners{};
            numbers yours{};
            if (line.empty ())
                {
                    continue;
                }
            getNums (line, &winners, &yours);
            size_t matches = 0;
            for (const auto &num : winners)
                {
                    if (yours.contains (num))
                        {
                            matches++;
                        }
                }
            assert (matches <= 10);
            this->answerOne += getFactor (matches);
            card cd{ .idx = lineNum, .winners = matches };
            cards[this->lineNum++] = cd;
        }
}

size_t
aoc::Four::one ()
{
    return this->answerOne;
}

size_t
aoc::Four::two ()
{
    for (auto i = 0; i < CARD_MAX; i++)
        {
            cardStack.push (cards[i]);
        }
    while (!cardStack.empty ())
        {
            drawCard ();
        }
    return answerTwo;
}

void
aoc::Four::drawCard ()
{
    answerTwo++;
    card cd = cardStack.top ();
    cardStack.pop ();
    for (auto i = 1; i < cd.winners + 1; i++)
        {
            cardStack.push (cards[cd.idx + i]);
        }
}

void
aoc::Four::getNums (const std::string &line, aoc::numbers *winners, aoc::numbers *yours)
{

    std::regex pattern (getReg ());
    std::smatch match;
    assert (std::regex_search (line, match, pattern));
    char *end = nullptr;
    for (auto m : match)
        {
            auto ch = m.str ();
            auto num = (size_t)strtol (ch.c_str (), &end, 10);
            if (num == 0)
                {
                    continue;
                }
            if (winners->size () < 10)
                {
                    winners->insert (num);
                }
            else
                {
                    yours->insert (num);
                }
        }
}

aoc::Four::~Four () = default;
