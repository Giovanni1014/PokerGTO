#ifndef GAMESETTING_H
#define GAMESETTING_H

#include <vector>

/**
 * @struct GameSetting
 * @brief
 *
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
