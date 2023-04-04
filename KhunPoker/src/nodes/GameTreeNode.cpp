#include "GameTreeNode.h"

GameTreeNode::GameTreeNode() {}

GameTreeNode::~GameTreeNode() {}

GameTreeNode::GameTreeNode(shared_ptr<GameTreeNode> parent): parent(parent) {

}

vector<float> GameTreeNode::utility(const Player player, const vector<float>& reach_probs) {
    return vector<float>{};
}

shared_ptr<GameTreeNode> GameTreeNode::getParent() const {
    return this->parent;
}
