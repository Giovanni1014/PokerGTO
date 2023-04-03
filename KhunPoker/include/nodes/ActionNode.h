#ifndef ACTIONNODE_H
#define ACTIONNODE_H

#include "Trainable.h"
#include "GameTreeNode.h"
#include "GameAction.h"
#include "Player.h"

using std::vector;

class ActionNode: public GameTreeNode {
public:
    ActionNode(vector<GameAction> actions, vector<shared_ptr<GameTreeNode>> childrens, Player player, float pot, shared_ptr<GameTreeNode> parent);

    vector<float> utility(const Player player, const vector<float>& reach_probs) override;

    vector<GameAction>& getActions() const;

    vector<shared_ptr<GameTreeNode>>& getChildrens() const;

    shared_ptr<Trainable> getTrainable() const; // * removed indexing

    const Player getPlayer() const;

    const GameTreeNodeType getType() override;

private:
    const vector<GameAction> actions;
    const vector<shared_ptr<GameTreeNode>> childrens;
    const shared_ptr<Trainable> trainable; // * removed vector
    const Player player;
};

#endif // ACTIONNODE_H
