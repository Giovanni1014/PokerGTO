#ifndef SHOWDOWNNODE_H
#define SHOWDOWNNODE_H

#include "GameTreeNode.h"
#include "Player.h"

using std::vector;

class ShowdownNode: public GameTreeNode {
    public:
        ShowdownNode(float pot, shared_ptr<GameTreeNode> parent);

        vector<float> utility(const Player player, const vector<float>& reach_probs, const vector<float>& opp_reach_probs) override;
};

#endif // SHOWDOWNNODE_H
