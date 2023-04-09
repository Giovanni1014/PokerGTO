#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
#include "Deck.h"

#include "ActionNode.h"
#include "ShowdownNode.h"
#include "TerminalNode.h"
#include "Player.h"
#include "Street.h"

#include "GameTree.h"
#include "GameSetting.h"
#include "Solver.h"

using std::vector;

/**
 * @file Main.cpp
 * @brief Sample program to demonstrate shuffling of cards.
 *
 * @return int
 */
int main() {
    std::ios_base::sync_with_stdio(false); //? what is this

    //create gameSetting
    vector<float> betSizes = {1.0, 2.0};
    GameSetting gameSetting(1, betSizes, 0, 0, (double)0.5, true);

    //create initial game state
    GameState gameState(
        Street::INGAME,
        0,
        0,
        Player::OOP,
        0
    );

    //create and build gameTree
    shared_ptr<GameTree> gameTree = std::make_shared<GameTree>(gameSetting);
    gameTree->build(gameState);

    //cfr
    train(100000, gameTree, true);
}

void train(int iterations, std::shared_ptr<GameTree>& gameTree, bool print = false) {
    const int PRINT_STEP = 5000;
    for (int i = 0; i < (iterations / PRINT_STEP); i++) {
        for (int j = 0; j < PRINT_STEP; j++) {
            gameTree->root->getTrainables()->updateStrategy();
            if (print) {
                std::cout << gameTree->toString() << "\n";
            }
        }
    }
}