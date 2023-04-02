#include "GameTree.h"
#include "Action.h"

std::vector<Action> GameTree::calculateLegalMoves(const GameState& gameState) {
    std::vector<Action> legal_moves;
    Player current_player = gameState.player_turn;

    // Get the current pot size and the amount of chips each player has committed
    float current_player_commit = (current_player == Player::OOP) ? gameState.oop_commit : gameState.ip_commit;
    float other_player_commit = (current_player == Player::OOP) ? gameState.ip_commit : gameState.oop_commit;

    // Determine if checking is a legal move.
    //Folding is a legal move whenever checking is not.
    if (current_player_commit == other_player_commit) {
        legal_moves.push_back(Action::CHECK);
    } else {
        legal_moves.push_back(Action::FOLD);
    }

    // Betting is always a legal move, (betting == calling)
    legal_moves.push_back(Action::BET);

    return legal_moves;
}
