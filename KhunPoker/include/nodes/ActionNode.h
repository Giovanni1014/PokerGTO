#ifndef ACTIONNODE_H
#define ACTIONNODE_H

#include <trainable/Trainable.h>
#include "GameTreeNode.h"
#include "GameAction.h"

using std::vector;

class ActionNode : public GameTreeNode
{
public:
    ActionNode(vector<GameAction> actions, vector<shared_ptr<GameTreeNode>> childrens, int player, double pot, shared_ptr<GameTreeNode> parent);

    vector<float> utility(int player, vector<float> reach_probs) override;

    vector<GameAction> &getActions() const;
    // void setActions(const vector<GameActions> &actions);

    vector<shared_ptr<GameTreeNode>> &getChildrens() const;
    // void setChildrens(const vector<shared_ptr<GameTreeNode>> &childrens);

    shared_ptr<Trainable> getTrainable() const; // ! removed indexing
    // void setTrainable(vector<shared_ptr<Trainable>> trainable, vector<PrivateCards> *player_privates);

    int getPlayer() const;

    // vector<PrivateCards> *player_privates;

private:
    // GameTreeNodeType getType() override;
    const vector<GameAction> actions;
    const vector<shared_ptr<GameTreeNode>> childrens;
    const shared_ptr<Trainable> trainable; // ! removed vector
    const int player;                      // ! Player Enum?
};

#endif // ACTIONNODE_H
