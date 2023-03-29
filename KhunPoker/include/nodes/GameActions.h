#ifndef GAMEACTIONS_H
#define GAMEACTIONS_H

#include <string>
#include <vector>
#include "nodes/GameTreeNode.h"

class GameActions
{
public:
    enum PokerActions
    {
        BEGIN,
        ROUNDBEGIN,
        BET,
        RAISE,
        CHECK,
        FOLD,
        CALL
    };

    GameActions();
    GameActions(PokerActions action, double amount);

    PokerActions getAction() const;
    double getAmount() const;

    std::string toString() const;

private:
    const PokerActions action;
    const double amount{};
};

#endif // GAMEACTIONS_H
