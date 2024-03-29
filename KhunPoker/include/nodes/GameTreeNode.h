#ifndef GAMETREENODE_H
#define GAMETREENODE_H

#include <string>
#include <vector>
#include "Player.h"

using std::shared_ptr, std::vector;

class GameTreeNode {
public:
    enum GameTreeNodeType {
        ACTION,
        SHOWDOWN,
        TERMINAL,
        // CHANCE ! needed for NLTH 
    };

    GameTreeNode();

    virtual ~GameTreeNode();

    GameTreeNode(shared_ptr<GameTreeNode> parent);

    shared_ptr<GameTreeNode> getParent() const;

    virtual vector<float> utility(const Player player, const vector<float>& reach_probs);


    virtual const GameTreeNodeType getType() = 0;

private:
    const shared_ptr<GameTreeNode> parent;
};

#endif // GAMETREENODE_H
