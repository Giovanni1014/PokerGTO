#ifndef GAMEACTION_H
#define GAMEACTION_H

#include <string>
#include <vector>
#include "nodes/GameTreeNode.h"

struct GameAction {
    enum ActionType {
        INIT_BET,
        RAISE,
        CHECK,
        FOLD,
        CALL
    };

    const ActionType type;
    const float amount;

    GameAction(ActionType type, float amount) : type(type), amount(amount) {}
};

#endif // GAMEACTION_H
