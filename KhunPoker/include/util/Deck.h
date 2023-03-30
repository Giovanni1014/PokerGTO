#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "DeckType.h"

/**
 * @file Deck.h
 * @brief Deck represents the container that holds multiple cards. 
 */
class Deck {
    private:
        static const int STANDARD_DECK_SIZE = 52; 
        static const int KHUN_DECK_SIZE = 3;
        
        std::vector<Card> cards;
        int currCard;
    public: 
        Deck(const DeckType deckType);
        Deck();
        void addKhunDeck();
        void addStandardDeck();
        void shuffle();
        Card deal(); 
        std::vector<Card> getCards() const;
};

#endif