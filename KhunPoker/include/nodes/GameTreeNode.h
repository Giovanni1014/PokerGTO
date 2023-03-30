#ifndef GAMETREENODE_H
#define GAMETREENODE_H

#include <string>
#include <vector>
#include "Player.h"

using std::shared_ptr, std::vector;

class GameTreeNode
{
public:
    // enum GameTreeNodeType
    // {
    //     ACTION,
    //     SHOWDOWN,
    //     TERMINAL,
    //     CHANCE
    // };

    GameTreeNode();
    GameTreeNode(double pot, shared_ptr<GameTreeNode> parent);

    // int depth{};
    // int subtree_size{};

    shared_ptr<GameTreeNode> getParent() const;
    // void setParent(shared_ptr<GameTreeNode> parent);
    double getPot() const;

    virtual vector<float> utility(Player player, vector<float> reach_probs); // * size is number of hands

    // void printHistory();
    // static void printNodeHistory(GameTreeNode *node);
    // virtual GameTreeNodeType getType() = 0;

private:
    const double pot{};
    const shared_ptr<GameTreeNode> parent;
};

#endif // GAMETREENODE_H
