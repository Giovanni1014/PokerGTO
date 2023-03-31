#include "nodes/ActionNode.h"

ActionNode::ActionNode(vector<GameAction> actions, vector<shared_ptr<GameTreeNode>> childrens, Player player, shared_ptr<GameTreeNode> parent) : GameTreeNode(parent) {
    this.actions = actions;
    this.childrens = childrens;
    this.trainable = make_shared<Trainable>(); // ! to be fixed
    this.player = player;
}

vector<float> ActionNode::utility(const Player player, const vector<float>& reach_probs) override {
    // TODO implement
}

vector<GameAction>& ActionNode::getActions() const {
    return this.actions;
}

vector<shared_ptr<GameTreeNode>>& ActionNode::getChildrens() const {
    return this.childrens;
}

shared_ptr<Trainable> ActionNode::getTrainable() const {
    return this.trainable;
}

const Player ActionNode::getPlayer() const {
    return this.player;
}

GameTreeNodeType ActionNode::getType() override {
    return ACTION;
}