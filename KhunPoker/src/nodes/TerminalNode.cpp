#include "nodes/TerminalNode.h"

TerminalNode::TerminalNode() {

}

TerminalNode::TerminalNode(Player winner, float pot, shared_ptr<GameTreeNode> parent) {
    this.winner = winner;
    this.pot = pot;
    this.parent = parent;
}

vector<float> TerminalNode::utility(const Player player, const vector<float>& reach_probs) override {
    // ! don't need reach_probs here
    if (player == this.winner) {
        return this.pot;
    } else {
        return -this.pot;
    }
}

GameTreeNodeType TerminalNode::getType() override {
    return TERMINAL;
}

float TerminalNode::getPot() const {
    return this.pot;
}