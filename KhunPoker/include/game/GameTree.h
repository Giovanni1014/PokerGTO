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
  private:
    std::string json_tree; //? do we want to use json for this like TexasSolver does
    std::shared_ptr<GameTreeNode> root = nullptr;

  public:
    GameTree( //? do we want ability to load GameTree from json
      const std::string& json_tree,
      Deck deck
    );
    GameTree(
      Deck deck,
      int current_round
    );

    std::shared_ptr<GameTreeNode> build(
      std::shared_ptr<ActionNode> node,
      Deck deck
    );
    std::shared_ptr<GameTreeNode> build(
      std::shared_ptr<ChanceNode> node,
      Deck deck
    );

    std::shared_ptr<GameTreeNode> getRootNode();
    std::string getJsonTree(); //TODO: if we're using json, figure out whether to use nlohmann::json or something else (see TexasSolver)
};

#endif //KHUNSOLVER_INCLUDE_GAMETREE_H_