#ifndef GAMETREE_H
#define GAMETREE_H

#include <memory>
#include <vector>

#include <game/GameState.h>
#include <nodes/ActionNode.h>
#include <nodes/ChanceNode.h>
#include <nodes/TerminalNode.h>
#include <nodes/ShowdownNode.h>
#include <nodes/GameTreeNode.h>
#include <util/Action.h>

/** 
 * @class GameTree
 * 
 * See TexasSolver's implementation at:
 * https://github.com/bupticybee/TexasSolver/blob/console/include/GameTree.h
 */
class GameTree {
    public:
        std::shared_ptr<GameTreeNode> root;
        std::shared_ptr<GameState> gameState;

        GameTree(GameState gameState);

    private:
        void build(GameState gameState);
        void buildSubtree(std::shared_ptr<GameTreeNode> node); //perhaps do overloads based on type

        std::vector<Action> calculateLegalMoves(const GameState& gameState);
};

#endif //GAMETREE_H