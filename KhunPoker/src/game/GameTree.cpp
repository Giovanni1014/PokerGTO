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
    Player current_player = gameState.player_turn;

    // Get the current pot size and the amount of chips each player has committed
    float current_player_commit = (current_player == Player::OOP) ? gameState.oop_commit : gameState.ip_commit;
    float other_player_commit = (current_player == Player::OOP) ? gameState.ip_commit : gameState.oop_commit;

    // Determine if checking is a legal move.
    //Folding is a legal move whenever checking is not.
    if (current_player_commit == other_player_commit) {
        legalActions.push_back(GameAction(GameAction::CHECK, -1.0));
    } else {
        legalActions.push_back(GameAction(GameAction::FOLD, -1.0));
        legalActions.push_back(GameAction(GameAction::CALL, other_player_commit - current_player_commit));
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
        if (action.type == GameAction::RAISE) {
            int new_oop_commit = gameState.oop_commit;
            int new_ip_commit = gameState.ip_commit;
            if (gameState.player_turn == Player::OOP) {
                new_oop_commit += action.amount;
            } else {
                new_ip_commit += action.amount;
            }
            childrenStates.push_back(GameState(
                Street::INGAME,
                new_oop_commit,
                new_ip_commit,
                (Player)(1 - gameState.player_turn),
                gameState.bet_count + 1
            ));
        } else if (action.type == GameAction::CHECK) {
            Street street = gameState.player_turn == Player::OOP ? Street::INGAME : Street::TERMINAL;
            childrenStates.push_back(GameState(
                street,
                gameState.oop_commit,
                gameState.ip_commit,
                (Player)(1 - gameState.player_turn),
                gameState.bet_count
            ));
        } else if (action.type == GameAction::FOLD) {
            childrenStates.push_back(GameState(
                Street::TERMINAL,
                gameState.oop_commit,
                gameState.ip_commit,
                (Player)(1 - gameState.player_turn),
                gameState.bet_count
            ));
        } else if (action.type == GameAction::CALL) {
            int new_oop_commit = gameState.oop_commit;
            int new_ip_commit = gameState.ip_commit;
            if (gameState.player_turn == Player::OOP) {
                new_oop_commit += action.amount;
            } else {
                new_ip_commit += action.amount;
            }
            childrenStates.push_back(GameState(
                Street::TERMINAL,
                new_oop_commit,
                new_ip_commit,
                (Player)(1 - gameState.player_turn),
                0
            ));
        }
    }
    return std::make_shared<vector<GameState>>(std::move(childrenStates));

}

std::vector<int> GameTree::generateBetAmounts(const GameState& gameState) {
    vector<int> betAmounts;
    int player_commit = gameState.player_turn == Player::IP ? gameState.ip_commit : gameState.oop_commit;
    int oppo_commit = gameState.player_turn != Player::IP ? gameState.ip_commit : gameState.oop_commit;
    int called_pot_size = 2 * oppo_commit;
    int call_amount = oppo_commit - player_commit;
    bool have_allined = false;
    if (gameState.bet_count < this->gameSetting.betCntLimit) {
        for (float betSize : this->gameSetting.bet_sizes) {
            int betAmount = std::round(betSize * called_pot_size / 100) + call_amount;
            // ! need to check if the bet is greater than min bet
            if (betAmount > call_amount) { // * is not a call
                if (betAmount < this->gameSetting.initial_stack - player_commit) {
                    betAmounts.push_back(betAmount);
                } else if (betAmount == this->gameSetting.initial_stack - player_commit) {
                    betAmounts.push_back(betAmount);
                    have_allined = true;
                }
            }
        }
    }
    if (this->gameSetting.canAllIn && !have_allined) {
        betAmounts.push_back(gameSetting.initial_stack - player_commit);
    }
    return betAmounts;
}
