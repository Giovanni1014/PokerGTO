#include "Comparer.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "Card.h"
#include "Suit.h"
#include "Rank.h"

using std::string;

// contents of file
// Js,0
// Qs,1
// Ks,2

size_t Comparer::hashFunction(const PrivateCard& privateCard) {
    return privateCard.getCard().getRank() * 4 + privateCard.getCard().getSuit();
}


Comparer::Comparer() : Comparer("KhunPoker/files/khun_list.txt") {}

Comparer::Comparer(std::string filename) {
    this->khunMap = std::unordered_map<PrivateCard, int, PrivateCardHasher>();


    std::ifstream file("KhunPoker/files/khun_list.txt");
    for (int i = 0; i < 3; i++) {
        string card;
        int value;
        file >> card >> value;
        Card card1(card);
        PrivateCard privateCard(card1);
        khunMap[card1] = value;
    }

}


Comparer::Result Comparer::compare(PrivateCard privateCard1, PrivateCard privateCard2) {
    int rank1 = khunMap[privateCard1];
    int rank2 = khunMap[privateCard2];
    if (rank1 > rank2) {
        return Result::WIN;
    } else if (rank1 < rank2) {
        return Result::LOSS;
    } else {
        return Result::TIE;
    }
}