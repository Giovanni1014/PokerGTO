#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include "GameTreeNode.h"
#include "Player.h"

using std::vector;

class TerminalNode : public GameTreeNode {
public:
    TerminalNode();

    TerminalNode(Player winner, float pot, shared_ptr<GameTreeNode> parent);

    vector<float> utility(const Player player, const vector<float>& reach_probs, const vector<float>& opp_reach_probs) override;

    const GameTreeNodeType getType() override;

    const float getPot() const;

private:
    const float pot{};
    const Player winner{};
};

#endif // TERMINALNODE_H
