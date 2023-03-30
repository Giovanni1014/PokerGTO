#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include "GameTreeNode.h"
#include "Player.h"

using std::vector;

class TerminalNode : public GameTreeNode {
    public:
        TerminalNode();
        TerminalNode(Player winner, float pot, shared_ptr<GameTreeNode> parent);

        vector<float> utility(const Player player, const vector<float>& reach_probs) override;
        // TerminalNode(vector<double> payoffs, int winner, double pot, shared_ptr<GameTreeNode> parent);
        // vector<double> get_payoffs();

        const GameTreeNodeType getType() override;

    private:
        // vector<double> payoffs;
        const Player winner{}; 
};

#endif // TERMINALNODE_H
