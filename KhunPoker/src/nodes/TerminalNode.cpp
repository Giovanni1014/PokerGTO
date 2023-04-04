#include "TerminalNode.h"

TerminalNode::TerminalNode() {

}

TerminalNode::TerminalNode(Player winner, float pot, shared_ptr<GameTreeNode> parent): GameTreeNode(parent), winner(winner), pot(pot) {

}

vector<float> TerminalNode::utility(const Player player, const vector<float>& reach_probs) {
    // ! don't need reach_probs here
    // * edit: we need the size of it
    if (player == this->winner) {
        return vector<float>(reach_probs.size(), this->pot);
    }
    else {
        return vector<float>(reach_probs.size(), -this->pot);
    }
}

const GameTreeNode::GameTreeNodeType TerminalNode::getType() {
    return TERMINAL;
}

const float TerminalNode::getPot() const {
    return this->pot;
}
