/**
 * @file GameTree.h
 * @brief contains the GameTree class, see brief below.
 */

#ifndef KHUNSOLVER_INCLUDE_GAMETREE_H_
#define KHUNSOLVER_INCLUDE_GAMETREE_H_

#include <string>

#include <nodes/GameTreeNode.h>
#include <game/Deck.h>


/** 
 * @class GameTree
 * @brief 
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
      std::shared_ptr<GameTreeNode> node,
      Deck deck
    )
};

#endif //KHUNSOLVER_INCLUDE_GAMETREE_H_