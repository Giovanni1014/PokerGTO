#ifndef GAMETREE_H
#define GAMETREE_H

#include <memory>
#include <vector>

#include "GameState.h"
#include "ActionNode.h"
#include "ChanceNode.h"
#include "TerminalNode.h"
#include "ShowdownNode.h"
#include "GameTreeNode.h"
#include "GameAction.h"

#include "GameSetting.h"

/**
 * @class GameTree
 *
 * See TexasSolver's implementation at:
 * https://github.com/bupticybee/TexasSolver/blob/console/include/GameTree.h
 */
class GameTree {
public:
    std::shared_ptr<GameTreeNode> root;
    // std::shared_ptr<GameState> gameState;
    const GameSetting gameSetting;

    GameTree(GameSetting gameSetting);

private:
    void build(GameState gameState);
    void buildSubtree(std::shared_ptr<GameTreeNode> node); //perhaps do overloads based on type

    std::vector<GameAction> generateLegalActions(const GameState& gameState);
    std::shared_ptr<std::vector<GameState>> generateChildrenStates(const GameState& gameState,
        vector<GameAction>& actions);
public:
    std::vector<int> generateBetAmounts(const GameState& gameState, float current_player_commit, float other_player_commit);
};

#endif //GAMETREE_H
