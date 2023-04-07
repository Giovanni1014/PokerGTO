#include "ActionNode.h"

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