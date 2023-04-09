#include "GameTree.h"
#include "GameAction.h"

#include "Player.h"
#include "Street.h"

#include <algorithm>
#include <cmath>

using std::vector;

GameTree::GameTree(GameSetting gameSetting) : gameSetting(gameSetting) {
}

vector<GameAction> GameTree::generateLegalActions(const GameState& gameState) {
    vector<GameAction> legalActions;
    if (gameState.street == Street::TERMINAL) {
        return legalActions;
    }
    Player currentPlayer = gameState.playerTurn;

    // Get the current pot size and the amount of chips each player has committed
    float currentPlayerCommit = (currentPlayer == Player::OOP) ? gameState.oopCommit : gameState.ipCommit;
    float otherPlayerCommit = (currentPlayer == Player::OOP) ? gameState.ipCommit : gameState.oopCommit;

    // Determine if checking is a legal move.
    //Folding is a legal move whenever checking is not.
    if (currentPlayerCommit == otherPlayerCommit) {
        legalActions.push_back(GameAction(GameAction::CHECK, -1.0));
    } else {
        legalActions.push_back(GameAction(GameAction::FOLD, -1.0));
        legalActions.push_back(GameAction(GameAction::CALL, otherPlayerCommit - currentPlayerCommit));
    }

    // Betting is always a legal move, (betting == calling)

    // if (allin)
    vector<int> betAmounts = generateBetAmounts(gameState);
    for (int betAmount : betAmounts) {
        legalActions.push_back(GameAction(GameAction::RAISE, betAmount));
    }

    return legalActions;
}

std::shared_ptr<vector<GameState>> GameTree::generateChildrenStates(const GameState& gameState,
    vector<GameAction>& actions) {

    vector<GameState> childrenStates;

    for (GameAction action : actions) {
        switch (action.type) {
            case GameAction::RAISE:
                int newOopCommit = gameState.oopCommit;
                int newOpCommit = gameState.ipCommit;
                if (gameState.playerTurn == Player::OOP) {
                    newOopCommit += action.amount;
                } else {
                    newOpCommit += action.amount;
                }
                childrenStates.push_back(GameState(
                    Street::INGAME,
                    newOopCommit,
                    newOpCommit,
                    (Player)(1 - gameState.playerTurn),
                    gameState.betCount + 1
                ));
                break;
            case GameAction::CHECK:
                Street street = gameState.playerTurn == Player::OOP ? Street::INGAME : Street::TERMINAL;
                childrenStates.push_back(GameState(
                    street,
                    gameState.oopCommit,
                    gameState.ipCommit,
                    (Player)(1 - gameState.playerTurn),
                    gameState.betCount
                ));
                break;
            case GameAction::FOLD:
                childrenStates.push_back(GameState(
                    Street::TERMINAL,
                    gameState.oopCommit,
                    gameState.ipCommit,
                    (Player)(1 - gameState.playerTurn),
                    gameState.betCount
                ));
                break;
            case GameAction::CALL:
                int newOopCommit = gameState.oopCommit;
                int newOpCommit = gameState.ipCommit;
                if (gameState.playerTurn == Player::OOP) {
                    newOopCommit += action.amount;
                } else {
                    newOpCommit += action.amount;
                }
                childrenStates.push_back(GameState(
                    Street::TERMINAL,
                    newOopCommit,
                    newOpCommit,
                    (Player)(1 - gameState.playerTurn),
                    0
                ));
                break;
        }
    }
    return std::make_shared<vector<GameState>>(std::move(childrenStates));

}

std::vector<int> GameTree::generateBetAmounts(const GameState& gameState) {
    vector<int> betAmounts;
    int player_commit = gameState.playerTurn == Player::IP ? gameState.ipCommit : gameState.oopCommit;
    int oppo_commit = gameState.playerTurn != Player::IP ? gameState.ipCommit : gameState.oopCommit;
    int called_pot_size = 2 * oppo_commit;
    int call_amount = oppo_commit - player_commit;
    bool have_allined = false;
    if (gameState.betCount < this->gameSetting.betCntLimit) {
        for (float betSize : this->gameSetting.betSizes) {
            int betAmount = std::round(betSize * called_pot_size / 100) + call_amount;
            // ! need to check if the bet is greater than min bet
            if (betAmount > call_amount) { // * is not a call
                if (betAmount < this->gameSetting.initialStack - player_commit) {
                    betAmounts.push_back(betAmount);
                } else if (betAmount == this->gameSetting.initialStack - player_commit) {
                    betAmounts.push_back(betAmount);
                    have_allined = true;
                }
            }
        }
    }
    if (this->gameSetting.canAllIn && !have_allined) {
        betAmounts.push_back(gameSetting.initialStack - player_commit);
    }
    return betAmounts;
}