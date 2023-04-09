#include "nodes/ShowdownNode.h"

ShowdownNode::ShowdownNode() {}

ShowdownNode::ShowdownNode(float pot, shared_ptr<GameTreeNode> parent): GameTreeNode(parent), pot(pot) {}

vector<float> ShowdownNode::utility(const Player player, const vector<float>& reachProbs) {
    // TODO implement
    //this->trainable...
    return vector<float>{};
}

const GameTreeNode::GameTreeNodeType ShowdownNode::getType() {
    return SHOWDOWN;
}

const float ShowdownNode::getPot() const {
    return this->pot;
}
