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


using std::vector, std::shared_ptr, std::make_shared;

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

    //create and build gameTree
    GameTree gameTree();


}
