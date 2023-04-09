#ifndef GAMESETTING_H
#define GAMESETTING_H

#include <vector>

/**
 * @struct GameSetting
 * 
 * @param betCntLimit max amount of bets
 * @param bet_sizes possible bet sizes
 * @param initial_stick initial max effective stack
 * @param additional_pot_amount amount of dead money in preflop
 * @param allin_threshold when to go all in as opposed to bet x% of stack
 * @param canAllIn whether all in is possible
*/
struct GameSetting {
    int betCntLimit;
    std::vector<float> bet_sizes; // ! have to be increasing
    int initial_stack; // effective stack
    int additional_pot_amount;
    float allin_threshold;
    bool canAllIn;

    GameSetting(int betCntLimit,
        std::vector<float>& bet_sizes,
        int initial_stack,
        int additional_pot_amount,
        float allin_threshold,
        bool canAllIn) :
        betCntLimit(betCntLimit),
        bet_sizes(bet_sizes),
        initial_stack(initial_stack),
        additional_pot_amount(additional_pot_amount),
        allin_threshold(allin_threshold),
        canAllIn(canAllIn) {
    }
};

#endif //GAMESETTING_H
