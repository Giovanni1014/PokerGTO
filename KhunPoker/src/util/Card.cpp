#include "Card.h"

/**
 * @file Card.cpp
 * @brief Holds the card representation consisting of rank and a suit.
 */
Card::Card(Rank r, Suit s) : cardAsString{Card::RANKS_AS_CHAR[r], Card::SUITS_AS_CHAR[s], '\0'}, rank(r), suit(s) {};

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

bool Card::operator==(const Card& card) const {
    return this->rank == card.getRank() && this->suit == card.getSuit();
}

bool Card::operator!=(const Card& card) const {
    return !(*this == card);
}