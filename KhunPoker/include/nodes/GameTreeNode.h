#ifndef GAMETREENODE_H
#define GAMETREENODE_H

#include <string>
#include <vector>
#include "Player.h"

using std::shared_ptr, std::vector;

class GameTreeNode {
public:
    enum GameTreeNodeType {
        ACTION,
        SHOWDOWN,
        TERMINAL,
        // CHANCE ! needed for NLTH 
    };

    GameTreeNode();

    GameTreeNode(float pot, shared_ptr<GameTreeNode> parent);

    shared_ptr<GameTreeNode> getParent() const;

    float getPot() const;

    // virtual vector<float> utility(const Player player, const vector<float>& reach_probs, const vector<float>& opp_reach_probs);

    // * does not recursively calculate, it calls getUtility of children and use those to calculate utility.
    virtual void updateUtility(const Player player, const vector<float>& oppoReachProbs) = 0;

    vector<float> getUtility(const Player player);

    virtual const GameTreeNodeType getType() = 0;

private:
    vector<float> utility[2]; // * dim: (number of players) * (number of private hands)
    const float pot{};
    const shared_ptr<GameTreeNode> parent;
};

#endif // GAMETREENODE_H
