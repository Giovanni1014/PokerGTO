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



using std::vector, std::shared_ptr, std::unique_ptr,
std::make_unique, std::make_shared;

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
    GameTree gameTree(gameSetting);
    gameTree.build(gameState); //TODO: make this function exist

    //create solver, then train
    shared_ptr<Solver> solver = make_shared<Solver>(gameTree);
    solver->train();

    //print the strategy
    printStrategy(gameTree.root, solver);
}

void printStrategy(shared_ptr<GameTreeNode> node, const shared_ptr<Solver> solver, int depth = 0) {
  if (auto actionNode = std::dynamic_pointer_cast<ActionNode>(node)) {
    auto strategy = solver->get_strategy(actionNode, {});
    for (int i = 0; i < strategy.size(); ++i) {
      for (int j = 0; j < strategy[i].size(); ++j) {
        std::cout << "Action " << j << " Probability " << strategy[i][j][0] << "\n";
        printStrategy(actionNode->getChildrens()[j], solver);
      }
    }
  }
}