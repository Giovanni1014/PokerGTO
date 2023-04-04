#include "ActionNode.h"

ActionNode::ActionNode(vector<GameAction>& actions, vector<shared_ptr<GameTreeNode>>& childrens,
    Player player, shared_ptr<GameTreeNode> parent): GameTreeNode(parent), actions(actions), childrens(childrens), trainable(std::make_shared<Trainable>()), player(player) {
}

vector<float> ActionNode::utility(const Player player, const vector<float>& reach_probs) {
    // TODO implement
    return vector<float>{};
}

const vector<GameAction>& ActionNode::getActions() const {
    return this->actions;
}

const vector<shared_ptr<GameTreeNode>>& ActionNode::getChildrens() const {
    return this->childrens;
}

void ActionNode::setChildrens(vector<shared_ptr<GameTreeNode>>& childrens) {
    this->childrens = childrens;
}

const shared_ptr<Trainable> ActionNode::getTrainable() const {
    return this->trainable;
}

const Player ActionNode::getPlayer() const {
    return this->player;
}

const ActionNode::GameTreeNodeType ActionNode::getType() {
    return ACTION;
}
