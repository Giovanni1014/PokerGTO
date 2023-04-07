#ifndef COMPARER_H
#define COMPARER_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include "Card.h"
#include "PrivateCard.h"

class Comparer {
    private:
        size_t hashFunction(const PrivateCard& privateCard);
        std::unordered_map<PrivateCard, int, PrivateCardHasher> khunMap;

    public:
        enum Result {
            WIN,
            LOSS,
            TIE
        };

        Comparer();
        Comparer(std::string filename);
        Result compare(PrivateCard privateCard1, PrivateCard privateCard2);
};

struct PrivateCardHasher {
    size_t operator()(const PrivateCard& privateCard) const {
        return privateCard.getCard().getRank() * 4 + privateCard.getCard().getSuit();
    }
};

#endif // COMPARER_H

