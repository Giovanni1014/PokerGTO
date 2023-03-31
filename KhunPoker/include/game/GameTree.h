/**
 * @file GameTree.h
 * @brief contains the GameTree class, see brief below.
 */

#ifndef KHUNSOLVER_INCLUDE_GAMETREE_H_
#define KHUNSOLVER_INCLUDE_GAMETREE_H_

#include <string>

#include <game/GameState.h>
#include <nodes/ActionNode.h>
#include <nodes/ChanceNode.h>
#include <nodes/TerminalNode.h>
#include <nodes/ShowdownNode.h>
#include <nodes/GameTreeNode.h>
#include <util/Action.h>





/** 
 * @class GameTree
 * @brief the GameTree
 * 
 * See TexasSolver's implemenetation at:
 * https://github.com/bupticybee/TexasSolver/blob/console/include/GameTree.h
 */
class GameTree
{
  public:
    std::shared_ptr<GameTreeNode> root = nullptr;
    GameState gameState;

    GameTree(GameState gameState);
    
    void build(GameState& gameState); //initiates root

    std::vector<Action> get_legal_actions(GameState& state);

    shared_ptr<GameTreeNode> buildSubtree(); //recursively build tree
};

#endif //KHUNSOLVER_INCLUDE_GAMETREE_H_