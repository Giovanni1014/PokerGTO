# include <iostream>
# include "deck.cc"


int main()
{
    // deal out a deck of cards
    Deck deck;
    for (int i = 0; i < 52; i++)
    {
        std::cout << deck.deal().toString() << std::endl;
        // std::cout << i << std::endl;

        
    }
    // return 0;
}