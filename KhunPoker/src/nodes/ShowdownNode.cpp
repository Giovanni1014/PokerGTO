#include "nodes/ShowdownNode.h"

ShowdownNode::ShowdownNode() {

}

ShowdownNode::ShowdownNode(float pot, shared_ptr<GameTreeNode> parent) {
    this.pot = pot;
    this.parent = parent;
}

vector<float> ShowdownNode::utility(const Player player, const vector<float>& reach_probs) override {
    // TODO implement
    this.trainable...
}

GameTreeNodeType ShowdownNode::getType() override {
    return SHOWDOWN;
}

float ShowdownNode::getPot() const {
    return this.pot;
}