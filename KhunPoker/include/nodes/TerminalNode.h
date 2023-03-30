#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include "GameTreeNode.h"
#include "Player.h"

using std::vector;

class TerminalNode : public GameTreeNode
{
public:
    TerminalNode();
    TerminalNode(int winner, double pot, shared_ptr<GameTreeNode> parent);

    vector<float> utility(Player player, vector<float> reach_probs) override;
    // TerminalNode(vector<double> payoffs, int winner, double pot, shared_ptr<GameTreeNode> parent);
    // vector<double> get_payoffs();

    // private:
    // GameTreeNodeType getType() override;

private:
    // vector<double> payoffs;
    const int winner{}; // ! player enum
};

#endif // TERMINALNODE_H
