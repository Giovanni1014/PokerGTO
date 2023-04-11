#ifndef GAMESETTING_H
#define GAMESETTING_H

#include <vector>

/**
 * @struct GameSetting
 * 
 * @param betCntLimit max amount of bets
 * @param betSizes possible bet sizes
 * @param initialStack initial max effective stack
 * @param additionalPotAmount amount of dead money in preflop
 * @param allInThreshold when to go all in as opposed to bet x% of stack
 * @param canAllIn whether all in is possible
*/
struct GameSetting {
    int betCntLimit;
    std::vector<float> betSizes; // ! have to be increasing
    int initialStack; // effective stack
    int additionalPotAmount;
    float allInThreshold;
    bool canAllIn;

    GameSetting(int betCntLimit,
        std::vector<float>& betSizes,
        int initialStack,
        int additionalPotAmount,
        float allInThreshold,
        bool canAllIn) :
        betCntLimit(betCntLimit),
        betSizes(betSizes),
        initialStack(initialStack),
        additionalPotAmount(additionalPotAmount),
        allInThreshold(allInThreshold),
        canAllIn(canAllIn) {
    }
};

#endif //GAMESETTING_H
