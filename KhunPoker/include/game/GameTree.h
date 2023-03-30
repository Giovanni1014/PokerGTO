/**
 * @file GameTree.h
 * @brief contains the GameTree class, see brief below.
 */

#ifndef KHUNSOLVER_INCLUDE_GAMETREE_H_
#define KHUNSOLVER_INCLUDE_GAMETREE_H_

#include <string>

#include <nodes/GameTreeNode.h>
#include <nodes/ActionNode.h>
#include <nodes/ChanceNode.h>
#include <nodes/TerminalNode.h>
#include <game/GameState.h>
#include <game/Deck.h>



/** 
 * @class GameTree
 * @brief the Monte Carlo tree containing all possible nodes
 * 
 * See TexasSolver's implemenetation at:
 * https://github.com/bupticybee/TexasSolver/blob/console/include/GameTree.h
 */
class GameTree
{
  public:
    std::shared_ptr<GameTreeNode> root = nullptr;
    GameState state;

    GameTree(
      Node deck
    );
    GameTree(
      GameState state
    );

    std::shared_ptr<GameTreeNode> build(
      std::shared_ptr<ActionNode> node,
      GameState state
    );
    std::shared_ptr<GameTreeNode> build(
      std::shared_ptr<ChanceNode> node,
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