#ifndef SHOWDOWNNODE_H
#define SHOWDOWNNODE_H

#include "GameTreeNode.h"
#include "Player.h"

using std::vector;

class ShowdownNode : public GameTreeNode {
    public:
        // enum ShowDownResult
        // {
        //     NOTTIE,
        //     TIE
        // };
        // GameTreeNodeType getType() override;
        // ShowdownNode(vector<double> tie_payoffs, vector<vector<double>> player_payoffs, double pot, shared_ptr<GameTreeNode> parent);
        ShowdownNode(float pot, shared_ptr<GameTreeNode> parent);

        vector<float> utility(Player player, vector<float> reach_probs) override;
        // vector<double> get_payoffs(ShowDownResult result, int winner);
        // double get_payoffs(ShowDownResult result, int winner, int player);

        float getPot() const;

        // private:
        //     vector<double> tie_payoffs;
        //     vector<vector<double>> player_payoffs;
    private:
        const float pot{};
};

#endif // SHOWDOWNNODE_H
