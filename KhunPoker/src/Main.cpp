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

using std::vector, std::shared_ptr, std::make_shared;

/**
 * @file Main.cpp
 * @brief Sample program to demonstrate shuffling of cards.
 *
 * @return int
 */
int main() {
    std::ios_base::sync_with_stdio(false);

    Deck d(DeckType::STANDARD);
    int count = 0;
    for (const Card& c : d.getCards()) {
        std::cout << c.toString() << " ";
        count++;
    }
    std::cout << "\n";
    std::cout << count << "\n";

    d.shuffle();
    count = 0;

    for (const Card& c : d.getCards()) {
        std::cout << c.toString() << " ";
        count++;
    }
    std::cout << "\n";

    for (int i = 0; i < 52; i++) {
        std::cout << d.deal().toString() << " ";
    }
    std::cout << "\n";
    std::cout << count << "\n";

    for (int i = 0; i < 52; i++) {
        std::cout << d.deal().toString() << " ";
    }
    std::cout << "\n";

    Deck kd(DeckType::KHUN);
    count = 0;
    for (const Card& c : kd.getCards()) {
        std::cout << c.toString() << " ";
        count++;
    }
    std::cout << "\n";
    std::cout << count << "\n";

    kd.shuffle();
    count = 0;

    for (const Card& c : kd.getCards()) {
        std::cout << c.toString() << " ";
        count++;
    }
    std::cout << "\n";
    std::cout << count << "\n";

    vector<GameAction> actions;
    actions.emplace_back(GameAction::RAISE, 10.0);
    actions.emplace_back(GameAction::CHECK, -1.0);
    actions.emplace_back(GameAction::FOLD, -1.0);

    std::cout << "----------------\n";

    vector<shared_ptr<GameTreeNode>> childrens;

    shared_ptr<ActionNode> node = make_shared<ActionNode>(actions, childrens, Player::OOP, nullptr);

    childrens = {
        make_shared<ShowdownNode>(5.0, node),
        make_shared<TerminalNode>(Player::IP, 12.0, node)
    };

    node->setChildrens(childrens);

    for (auto x : node->getChildrens()) {
        std::cout << x->getType() << " ";
    }
    std::cout << "\n----------------\n";

    vector<float> betSizes = { 30, 50, 100 };
    GameSetting gameSetting(5, betSizes, 100, 0, 0.8, true);
    GameTree gameTree = GameTree(gameSetting);

    GameState gameState(Street::INGAME, 3, 5, Player::OOP, 1);
    vector<int> ret = gameTree.generateBetAmounts(gameState);
    for (auto bet : ret) {
        std::cout << bet << " ";
    } std::cout << "\n";

    std::cout << "\n----------------\n";

    vector<GameAction> legalActions = gameTree.generateLegalActions(gameState);
    for (auto action : legalActions) {
        std::cout << action.type << " " << action.amount << "\n";
    }

    std::cout << "----------------\n";

    return 0;
}
