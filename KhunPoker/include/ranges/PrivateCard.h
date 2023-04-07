#ifndef PRIVATE_CARD_H
#define PRIVATE_CARD_H

#include <string>
#include "Card.h"

/**
 * @file PrivateCard.h
 * @brief Holds the player's private card representation of one card.
 */
class PrivateCard {
    private:
        const Card card; 
    public:
        PrivateCard(Card card);
        const Card getCard() const;
};

#endif //PRIVATE_CARD_H