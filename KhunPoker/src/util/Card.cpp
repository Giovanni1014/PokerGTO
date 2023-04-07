#include "Card.h"

/**
 * @file Card.cpp
 * @brief Holds the card representation consisting of rank and a suit.
 */
Card::Card(Rank r, Suit s) : cardAsString{Card::RANKS_AS_CHAR[r], Card::SUITS_AS_CHAR[s], '\0'}, rank(r), suit(s) {};

Card::Card(std::string card) : cardAsString{card[0], card[1], '\0'} {
    for (int i = 0; i < 13; i++) {
        if (card[0] == Card::RANKS_AS_CHAR[i]) {
            this->rank = static_cast<Rank>(i);
        }
    }

    for (int i = 0; i < 4; i++) {
        if (card[1] == Card::SUITS_AS_CHAR[i]) {
            this->suit = static_cast<Suit>(i);
        }
    }
}

std::string Card::toString() const {
    return this->cardAsString;
}

Rank Card::getRank() const {
    return this->rank;
}

Suit Card::getSuit() const {
    return this->suit;
}

void Card::operator=(const Card& card) {
    this->rank = card.getRank();
    this->suit = card.getSuit();
    this->cardAsString[0] = Card::RANKS_AS_CHAR[card.getRank()];
    this->cardAsString[1] = Card::SUITS_AS_CHAR[card.getSuit()];
}
