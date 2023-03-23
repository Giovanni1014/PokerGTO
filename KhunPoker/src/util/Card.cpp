#include "Card.h"

/**
 * @file Card.cpp
 * @brief Holds the card representation consisting of rank and a suit.
 */
Card::Card(Rank r, Suit s) : card{Card::RANKS_AS_CHAR[r], Card::SUITS_AS_CHAR[s]}, rank(r), suit(s) {};

std::string Card::toString() const {
    return this->card;
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
    this->card[0] = Card::RANKS_AS_CHAR[card.getRank()];
    this->card[1] = Card::SUITS_AS_CHAR[card.getSuit()];
}
