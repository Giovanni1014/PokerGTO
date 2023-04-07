#include "PrivateCard.h"

PrivateCard::PrivateCard(Card card) : card(card) {}

const Card PrivateCard::getCard() const {
    return this->card;
}

bool PrivateCard::operator==(const PrivateCard& other) const {
    return this->card.getRank() == other.card.getRank() && this->card.getSuit() == other.card.getSuit();
}