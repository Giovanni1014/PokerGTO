#include "TerminalNode.h"

vector<float> TerminalNode::utility(const Player player, const vector<float>& reach_probs, const vector<float>& opp_reach_probs) {
    const int n = reach_probs.size();
    const float pot = getPot();
    return vector<float>(n, player == winner ? pot : 0.0f);
}