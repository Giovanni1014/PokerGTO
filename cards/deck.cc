#include "deck.h"

const int DEFAULT_CAPACITY = 52;

using namespace std;

Deck::Deck()
{
    // initialize the deck with 52 cards and shuffle it
    reset();
}

void Deck::shuffle()
{
    // shuffle the deck 7 times
    for (int i = 0; i < 7; i++)
    {
        shuffleOnce();
    }
    
}

void Deck::shuffleOnce()
{
    // shuffle the deck once
    vector<Card> temp;
    int size = cards.size();
    for (int i = 0; i < size; i++)
    {
        int index = rand() % cards.size();
        temp.push_back(cards[index]);
        cards.erase(cards.begin() + index);
    }
    cards = temp;
}

Card Deck::deal()
{
    // deal a card
    Card card = cards[0];
    cards.erase(cards.begin());
    return card;
}

void Deck::reset()
{
    // reset the deck
    cards.clear();
    for (int s = 1; s < 5; s++)
    {
        for (int r = 1; r < 14; r++)
        {
            cards.push_back(Card((Rank)r, (Suit)s));
        }
    }
    shuffle();
}


