#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
#include "Deck.h"
#include "Comparer.h"
#include "PrivateCard.h"
#include <vector>

/**
 * @file Main.cpp
 * @brief Sample program to demonstrate shuffling of cards.
 * 
 * @return int 
 */
int main() {
    // std::ios_base::sync_with_stdio(false);

    // Deck d(DeckType::STANDARD);
    // int count = 0;
    // for (const Card& c : d.getCards()) {
    //     std::cout << c.toString() << " ";
    //     count++;
    // }
    // std::cout << "\n";
    // std::cout << count << "\n";

    // d.shuffle();
    // count = 0;

    // for (const Card& c : d.getCards()) {
    //     std::cout << c.toString() << " ";
    //     count++;
    // }
    // std::cout << "\n";

    // for (int i = 0; i < 52; i++) {
    //     std::cout << d.deal().toString() << " ";
    // }
    // std::cout << "\n";
    // std::cout << count << "\n";

    // for (int i = 0; i < 52; i++) {
    //     std::cout << d.deal().toString() << " ";
    // }
    // std::cout << "\n";

    // Deck kd(DeckType::KHUN);
    // count = 0;
    // for (const Card& c : kd.getCards()) {
    //     std::cout << c.toString() << " ";
    //     count++;
    // }
    // std::cout << "\n";
    // std::cout << count << "\n";

    // kd.shuffle();
    // count = 0;

    // for (const Card& c : kd.getCards()) {
    //     std::cout << c.toString() << " ";
    //     count++;
    // }
    // std::cout << "\n";
    // std::cout << count << "\n";

    // test comparer
    Comparer comparer;
    std::vector<std::string> cards = {"JS", "QS", "KS"};
    std::vector<PrivateCard> privateCards1;
    std::vector<PrivateCard> privateCards2;

    for (int i = 0; i < 3; i++) {
        privateCards1.push_back(PrivateCard(Card(cards[i])));
    }

    privateCards2.push_back(PrivateCard(Card(Rank::JACK, Suit::SPADES)));
    privateCards2.push_back(PrivateCard(Card(Rank::QUEEN, Suit::SPADES)));
    privateCards2.push_back(PrivateCard(Card(Rank::KING, Suit::SPADES)));


    for (int i = 0; i < 3; i++) {
        // should print 2 2 2 (for ties)
        std::cout << comparer.compare(privateCards1[i], privateCards2[i]);
    }

    std::cout << "\n";

    
    for (int i = 0; i < 3; i++) {
        // should print 0 0 2 (for win, win, tie)
        std::cout << comparer.compare(privateCards1[2], privateCards1[i]) ;
    }




    return 0;
}