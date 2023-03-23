#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
#include "Deck.h"

/**
 * @file Main.cpp
 * @brief Sample program to demonstrate shuffling of cards.
 * 
 * @return int 
 */
int main() {
    std::ios_base::sync_with_stdio(false);

    Deck d(DeckType::STANDARD);
    int count = 0;
    for (const Card& c : d.getCards()) {
        std::cout << c.toString() << " ";
        count++;
    }
    std::cout << "\n";
    std::cout << count << "\n";

    d.shuffle();
    count = 0;

    for (const Card& c : d.getCards()) {
        std::cout << c.toString() << " ";
        count++;
    }
    std::cout << "\n";

    for (int i = 0; i < 52; i++) {
        std::cout << d.deal().toString() << " ";
    }
    std::cout << "\n";
    std::cout << count << "\n";

    for (int i = 0; i < 52; i++) {
        std::cout << d.deal().toString() << " ";
    }
    std::cout << "\n";

    Deck kd(DeckType::KHUN);
    count = 0;
    for (const Card& c : kd.getCards()) {
        std::cout << c.toString() << " ";
        count++;
    }
    std::cout << "\n";
    std::cout << count << "\n";

    kd.shuffle();
    count = 0;

    for (const Card& c : kd.getCards()) {
        std::cout << c.toString() << " ";
        count++;
    }
    std::cout << "\n";
    std::cout << count << "\n";

    return 0;
}