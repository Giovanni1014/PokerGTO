#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include "GameTreeNode.h"

using std::vector;

class TerminalNode : public GameTreeNode
{
public:
    TerminalNode();
    TerminalNode(vector<double> payoffs, int winner, double pot, shared_ptr<GameTreeNode> parent);
    vector<double> get_payoffs();

    // private:
    // GameTreeNodeType getType() override;

private:
    vector<double> payoffs;
    int winner{};
};

#endif // TERMINALNODE_H
