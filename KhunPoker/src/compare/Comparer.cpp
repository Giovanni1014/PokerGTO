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
// JS 0
// QS 1
// KS 2


Comparer::Comparer() : Comparer("khun_list.txt") {}

Comparer::Comparer(std::string filename) {
    this->khunMap = std::unordered_map<PrivateCard, int, PrivateCardHasher>();

    // file doesnt work right now, so hardcoded
    std::vector<string> cards = {"JS", "QS", "KS"};
    std::vector<int> values = {0, 1, 2};

    std::ifstream file(filename);
    for (int i = 0; i < 3; i++) {
        string card;
        int value;
        file >> card >> value;
        // std::cout << card << " | " << value << "\n"; 
        // Card card1(card);
        // PrivateCard privateCard(card1);
        // khunMap[privateCard] = value;

        Card card1(cards[i]);
        PrivateCard privateCard(card1);
        khunMap[privateCard] = values[i];
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