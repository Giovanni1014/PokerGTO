#ifndef GAMEACTION_H
#define GAMEACTION_H

#include <string>
#include <vector>
#include "nodes/GameTreeNode.h"

class GameAction {
    public:
        enum PokerAction {
            INIT_BET,
            RAISE,
            CHECK,
            FOLD,
            CALL
        };

        GameAction();

        GameAction(PokerAction action, float amount);

        const PokerAction getAction() const;

        const float getAmount() const;

        std::string toString() const;

    private:
        const PokerAction action;
        const float amount{};
};

#endif // GAMEACTION_H
