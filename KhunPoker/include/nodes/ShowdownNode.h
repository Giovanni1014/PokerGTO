#ifndef SHOWDOWNNODE_H
#define SHOWDOWNNODE_H

#include "GameTreeNode.h"

using std::vector;

class ShowdownNode : public GameTreeNode
{
public:
    // enum ShowDownResult
    // {
    //     NOTTIE,
    //     TIE
    // };
    // GameTreeNodeType getType() override;
    // ShowdownNode(vector<double> tie_payoffs, vector<vector<double>> player_payoffs, double pot, shared_ptr<GameTreeNode> parent);
    ShowdownNode(double pot, shared_ptr<GameTreeNode> parent);

    vector<float> utility(vector<float> reach_probs) override;
    // vector<double> get_payoffs(ShowDownResult result, int winner);
    // double get_payoffs(ShowDownResult result, int winner, int player);

    // private:
    //     vector<double> tie_payoffs;
    //     vector<vector<double>> player_payoffs;
};

#endif // SHOWDOWNNODE_H