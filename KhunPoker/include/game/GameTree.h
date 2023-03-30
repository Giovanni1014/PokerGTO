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


    /**
     * @fn build()
     * @brief the goal after build() is to have the entire GameTree initiated. All weights will be 1/3 for Kuhn
    */
    std::shared_ptr<GameTreeNode> build(
      std::shared_ptr<ActionNode> node,
      GameState state
    );
    std::shared_ptr<GameTreeNode> build(
      std::shared_ptr<TerminalNode> node,
      GameState state
    );
    std::shared_ptr<GameTreeNode> build(
      std::shared_ptr<ShowdownNode> node,
      GameState state
    );

    std::shared_ptr<ActionNode> generateNode(
      std::shared_ptr<ActionNode> node,
      GameState state
    );
    std::shared_ptr<TerminalNode> generateNode(
      std::shared_ptr<TerminalNode> node,
      GameState state
    );

    int updateDepth(
      std::shared_ptr<ActionNode> node,
      int depth
    );
};

#endif //KHUNSOLVER_INCLUDE_GAMETREE_H_