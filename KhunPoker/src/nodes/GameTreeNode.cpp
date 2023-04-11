#include "GameTreeNode.h"

GameTreeNode::GameTreeNode() {}

GameTreeNode::~GameTreeNode() {}

GameTreeNode::GameTreeNode(shared_ptr<GameTreeNode> parent) : parent(parent) {}

vector<float> GameTreeNode::getUtility(const Player player) {
    return this->utility[static_cast<int>(player)];
}

shared_ptr<GameTreeNode> GameTreeNode::getParent() const {
    return this->parent;
}
