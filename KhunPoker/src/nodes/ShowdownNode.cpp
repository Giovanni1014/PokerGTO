#include "ShowdownNode.h"
#include "Math.h"

vector<float> ShowdownNode::utility(const Player player, const vector<float>& reach_probs, const vector<float>& opp_reach_probs) {
    const int n = reach_probs.size();
    const float pot = getPot();
    vector<float> finalUtil(n, 0.0f);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            finalUtil[i] = Math::signum(i - j) * pot;
        }
    }
    return finalUtil;
}
