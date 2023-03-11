#include "card.h"


Card::Card(Rank r, Suit s)
{
    rank = r;
    suit = s;
}

// bool Card::operator<(const Card& other)s
// {
//     return rank < other.rank;
// }

Rank Card::getRank() const
{
    return rank;
}

Suit Card::getSuit() const
{
    return suit;
}

std::string Card::toString() const
{
    std::string s = "";
    switch (rank)
    {
        case TWO:
            s += "2";
            break;
        case THREE:
            s += "3";
            break;
        case FOUR:
            s += "4";
            break;
        case FIVE:
            s += "5";
            break;
        case SIX:
            s += "6";
            break;
        case SEVEN:
            s += "7";
            break;
        case EIGHT:
            s += "8";
            break;
        case NINE:
            s += "9";
            break;
        case TEN:
            s += "10";
            break;
        case JACK:
            s += "J";
            break;
        case QUEEN:
            s += "Q";
            break;
        case KING:
            s += "K";
            break;
        case ACE:
            s += "A";
            break;
    }
    switch (suit)
    {
        case C:
            s += "c";
            break;
        case D:
            s += "d";
            break;
        case H:
            s += "h";
            break;
        case S:
            s += "s";
            break;
    }
    return s;
}