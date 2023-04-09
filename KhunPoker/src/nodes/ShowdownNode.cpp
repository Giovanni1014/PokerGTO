#include "ShowdownNode.h"
#include "Math.h"

ShowdownNode::ShowdownNode() {}

ShowdownNode::ShowdownNode(float pot, shared_ptr<GameTreeNode> parent) : GameTreeNode(parent), pot(pot) {}

vector<float> ShowdownNode::utility(const Player player, const vector<float>& reach_probs, const vector<float>& opp_reach_probs) {
    const int n = reach_probs.size();
    const float pot = getPot();
    vector<float> finalUtil(n, 0.0f);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            finalUtil[i] = Math::signum(i - j) * reach_probs[i] * (opp_reach_probs[j] / (1 - opp_reach_probs[i])) * pot;
        }
    }
    return finalUtil;
}

const GameTreeNode::GameTreeNodeType ShowdownNode::getType() {
    return SHOWDOWN;
}

const float ShowdownNode::getPot() const {
    return this->pot;
}
