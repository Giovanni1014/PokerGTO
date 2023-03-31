#include "nodes/GameTreeNode.h"

GameTreeNode::GameTreeNode() {

}

GameTreeNode::GameTreeNode(shared_ptr<GameTreeNode> parent) {
    this.parent = parent;
}

shared_ptr<GameTreeNode> GameTreeNode::getParent() const {
    return this.parent;
}