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



using std::vector, std::shared_ptr,
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
    std::cout << "[J, Q, K]";
    printStrategy(gameTree.root, solver);
}

void printStrategy(shared_ptr<GameTreeNode> node, const shared_ptr<Solver> solver, int depth = 0) {
    if (node->getType() == GameTreeNode::GameTreeNodeType::ACTION) 
        //grab strategy and evs
        vector<vector<vector<float>>> strategy = solver->getStrategy(node, {}); //? what should the cards vector be
        vector<vector<vector<float>>> evs = solver->getEvs(node, {}); //? what should the cards vector be

        //print the context
        std::cout << "Strategy for node [" << depth << "] (" << node->getPlayer() << "): \n";
        depth++;

        //TODO: print the strategy/evs, depends on how its formatted

        //recurse
        for (shared_ptr<GameTreeNode> child : node->getChildrens()) {
            printStrategy(child, solver);
        }
    }
}