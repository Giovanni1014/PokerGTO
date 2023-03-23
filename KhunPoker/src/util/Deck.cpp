#include "Deck.h"

/**
 * @file Deck.cpp
 * @brief Deck represents the container that holds multiple cards. 
 */
Deck::Deck(const DeckType deckType) {
    switch (deckType) {
        case DeckType::KHUN:
            this->addKhunDeck();
            break;
        case DeckType::STANDARD:    
        default:
            this->addStandardDeck();
            break;
    }
}

Deck::Deck() {
    this->addStandardDeck();
}

void Deck::addKhunDeck() {
    for (int i = Rank::JACK; i <= Rank::KING; i++) {
        this->cards.push_back(Card((Rank) i, Suit::SPADES));
    }
}

void Deck::addStandardDeck() {
    for (int i = Rank::ACE; i <= Rank::KING; i++) {
        for (int j = Suit::CLUBS; j <= Suit::SPADES; j++) {
            this->cards.push_back(Card((Rank) i, (Suit) j));
        }
    }
}

// Fisher-Yates shuffle
void Deck::shuffle() {
    srand(time(NULL));
    for (int i = this->cards.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        std::swap(this->cards[i], this->cards[j]);
    }
    this->currCard = 0;
}

Card Deck::deal() {
    if (currCard == this->cards.size()) this->shuffle();
    return this->cards[currCard++];
}

std::vector<Card> Deck::getCards() const {
    return this->cards;
}
