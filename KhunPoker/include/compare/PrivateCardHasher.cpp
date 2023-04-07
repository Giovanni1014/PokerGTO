#include "PrivateCard.h"
#include "Card.h"

struct PrivateCardHasher {
    size_t operator()(const PrivateCard& privateCard) const {
        return privateCard.getCard().getRank() * 4 + privateCard.getCard().getSuit();
    }
};