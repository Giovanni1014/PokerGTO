#ifndef GAMETREENODE_H
#define GAMETREENODE_H

#include <string>
#include <vector>
#include "Player.h"

using std::shared_ptr, std::vector;

class GameTreeNode
{
public:
    enum GameTreeNodeType
    {
        ACTION,
        SHOWDOWN,
        TERMINAL,
        // CHANCE ! needed for NLTH
    };

    GameTreeNode();
    GameTreeNode(float pot, shared_ptr<GameTreeNode> parent);

    // int depth{};
    // int subtree_size{};

    shared_ptr<GameTreeNode> getParent() const;
    // void setParent(shared_ptr<GameTreeNode> parent);
    float getPot() const;

    virtual vector<float> utility(const Player player, const vector<float> &reach_probs);

    virtual const GameTreeNodeType getType() = 0;

private:
    const float pot{};
    const shared_ptr<GameTreeNode> parent;
};

#endif // GAMETREENODE_H
