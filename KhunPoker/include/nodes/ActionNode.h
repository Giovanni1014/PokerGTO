#ifndef ACTIONNODE_H
#define ACTIONNODE_H

#include <trainable/Trainable.h>
#include "GameTreeNode.h"
#include "GameAction.h"
#include "Player.h"

using std::vector;

class ActionNode : public GameTreeNode {
    public:
        ActionNode(vector<GameAction> actions, vector<shared_ptr<GameTreeNode>> childrens, Player player, float pot, shared_ptr<GameTreeNode> parent);

        vector<float> utility(const Player player, const vector<float>& reach_probs) override;

        vector<GameAction> &getActions() const;
        // void setActions(const vector<GameActions> &actions);

        vector<shared_ptr<GameTreeNode>> &getChildrens() const;
        // void setChildrens(const vector<shared_ptr<GameTreeNode>> &childrens);

        shared_ptr<Trainable> getTrainable() const; // ! removed indexing
        // void setTrainable(vector<shared_ptr<Trainable>> trainable, vector<PrivateCards> *player_privates);

        const Player getPlayer() const;

        // vector<PrivateCards> *player_privates;

        const GameTreeNodeType getType() override;

    private:
        const vector<GameAction> actions;
        const vector<shared_ptr<GameTreeNode>> childrens;
        const shared_ptr<Trainable> trainable; // ! removed vector
        const Player player;
};

#endif // ACTIONNODE_H
