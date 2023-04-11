#ifndef CARD_H
#define CARD_H

#include <string>
#include "Rank.h"
#include "Suit.h"

/**
 * @file Card.h
 * @brief Holds the card representation consisting of rank and a suit.
 */
class Card {
private:
    const char SUITS_AS_CHAR[4] = { 'C', 'D', 'H', 'S' };
    const char RANKS_AS_CHAR[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

    char cardAsString[3];
    Rank rank;
    Suit suit;

public:
    Card(Rank rank, Suit suit);

    std::string toString() const;
    Rank getRank() const;
    Suit getSuit() const;

    void operator=(const Card& card);
    bool operator==(const Card& card) const;
    bool operator!=(const Card& card) const;
};

#endif //CARD_H
