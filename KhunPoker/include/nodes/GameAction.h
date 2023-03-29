#ifndef GAMEACTION_H
#define GAMEACTION_H

#include <string>
#include <vector>
#include "nodes/GameTreeNode.h"

class GameAction
{
public:
    enum PokerAction
    {
        BEGIN,
        ROUNDBEGIN,
        BET,
        RAISE,
        CHECK,
        FOLD,
        CALL
    };

    GameAction();
    GameAction(PokerAction action, double amount);

    PokerAction getAction() const;
    double getAmount() const;

    std::string toString() const;

private:
    const PokerAction action;
    const double amount{};
};

#endif // GAMEACTION_H
