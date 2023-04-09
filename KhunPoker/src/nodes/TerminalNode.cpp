#include "TerminalNode.h"

TerminalNode::TerminalNode() {}

TerminalNode::TerminalNode(Player winner, float pot, shared_ptr<GameTreeNode> parent) : GameTreeNode(parent), winner(winner), pot(pot) {}

vector<float> TerminalNode::utility(const Player player, const vector<float>& reach_probs, const vector<float>& opp_reach_probs) {
    const int n = reach_probs.size();
    const float pot = getPot();
    return vector<float>(n, player == winner ? pot : 0.0f);
}

const GameTreeNode::GameTreeNodeType TerminalNode::getType() {
    return TERMINAL;
}

const float TerminalNode::getPot() const {
    return this->pot;
}
