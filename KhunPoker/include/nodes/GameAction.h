#ifndef GAMEACTION_H
#define GAMEACTION_H

#include <string>
#include <vector>
#include "nodes/GameTreeNode.h"

struct GameAction {
    enum PokerAction {
        INIT_BET,
        RAISE,
        CHECK,
        FOLD,
        CALL
    };

    const PokerAction action;
    const float amount;

    GameAction(PokerAction action, float amount): action(action), amount(amount) {}
};

#endif // GAMEACTION_H
