#ifndef SHOWDOWNNODE_H
#define SHOWDOWNNODE_H

#include "GameTreeNode.h"
#include "Player.h"

using std::vector;

class ShowdownNode: public GameTreeNode {
public:
    ShowdownNode();
    ShowdownNode(float pot, shared_ptr<GameTreeNode> parent);

    vector<float> utility(const Player player, const vector<float>& reach_probs) override;

    const GameTreeNodeType getType() override;

    const float getPot() const;

private:
    const float pot{};
};

#endif // SHOWDOWNNODE_H
