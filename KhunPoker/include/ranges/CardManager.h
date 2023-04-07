#ifndef CARD_MANAGER_H
#define CARD_MANAGER_H

#include "Comparer.h"

using std::shared_ptr;

/**
 * @file CardManager.h
 * @brief 
 */
class CardManager {
    private: 
        shared_ptr<Comparer> comparer;
        
    public: 
        CardManager::CardManager();
};

#endif // CARD_MANAGER_H