#include "ActionNode.h"

ActionNode::ActionNode(vector<GameAction>& actions, vector<shared_ptr<GameTreeNode>>& childrens,
    Player player, shared_ptr<GameTreeNode> parent) : GameTreeNode(parent), actions(actions), childrens(childrens), trainable(std::make_shared<Trainable>()), player(player) {
}

vector<float> ActionNode::utility(const Player player, const vector<float>& reach_probs, const vector<float>& opp_reach_probs) {
    const int n = reach_probs.size();
    vector<float> finalUtil(n, 0.0f);
    for (int i = 0; i < children.size(); i++) {
        vector<float> curr = (children[i].get())->utility(player, reach_probs, opp_reach_probs);
        for (int j = 0; j < curr.size(); j++) {
            finalUtil[j] += curr[j] * getTrainable().get()->getCurrentStrategy()[j];
        }
    }
    return finalUtil;
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
