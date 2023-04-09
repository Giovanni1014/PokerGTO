#include "CfrTrainable.h"

CfrTrainable::CfrTrainable() {

}

CfrTrainable::CfrTrainable(shared_ptr<ActionNode> actionNode) {
    this->actionNode = actionNode;
}

const vector<float> CfrTrainable::getStrategy() {
    return this->strategy;
}

void CfrTrainable::updateRegrets(const array<vector<float>, 2>& reachProbs) {

    // 0. calculate the children's reachprobs with our current reachProbs
    // 1. use the calculated children's reachprobs to call updateStrategy of ChildrenTrainables
    // in updateRegrets
        // 2. calculate the utility (temporary) by weighting children's utilities
        // 3. use that and the children's utilities, and OUR reachprob (reachProbs[player]) to calculate newest regret
        // 4. update cumulativeRegrets with newest regret and OUR reachprob
    // back in this function
        // 5. use cumulativeRegrets to update strategy
        // 6. call updateUtility of this node

    // * calls getUtility of this actionNode

    // needs to be looped for to find the utility of always choosing a node for each node
    vector<float> firstProb(reachProbs[0].size());
    fill(firstProb.begin(), firstProb.end(), 0);
    firstProb[0] = 1;
    vector<float> getUtilA = actionNode->getUtility(IP);

    vector<float> getUtil = actionNode->utility(IP, reachProbs[0], reachProbs[1]);

    vector<float> regret(reachProbs[0].size());

    // subtract the utility of always choosing a node from avg utility to find regret
    for (int i = 0; i < reachProbs[0].size(); i++) {
        regret.push_back(getUtilA[i] - getUtil[i]);
    }

    // if regret is negative, set it to 0
    for (int i = 0; i < reachProbs[0].size(); i++) {
        if (regret[i] < 0) {
            regret[i] = 0;
        }
    }

    // adds regret to cumulativeRegret
    std::transform(cumulativeRegrets.begin(), cumulativeRegrets.end(),
        regret.begin(), cumulativeRegrets.begin(), std::plus<int>());
}

void CfrTrainable::updateStrategy(const array<vector<float>, 2>& reachProbs) {
    // 0. calculate the children's reachprobs with our current reachProbs

    vector<float> childrenReachProbs(cumulativeRegrets.size());
    childrenReachProbs.assign(cumulativeRegrets.begin(), cumulativeRegrets.end());

    for (int i = 0; i < childrenReachProbs.size(); i++) {
        childrenReachProbs[i] *= reachProbs[0][i];
    }

    float childrenReachSum = std::accumulate(childrenReachProbs.begin(), childrenReachProbs.end(), 0.0);

    for (int i = 0; i < childrenReachProbs.size(); i++) {
        childrenReachProbs[i] /= childrenReachSum;
    }

    // 1. use the calculated children's reachprobs to call updateStrategy of ChildrenTrainables
    for (int i = 0; i < (*actionNode).getChildren().size(); i++) {
        shared_ptr<GameTreeNode> gameNode = (*actionNode).getChildren().at(0);
        if (typeid(*gameNode) == typeid(ActionNode)) {
            ActionNode* aNode = dynamic_cast<GameTreeNode*>(gameNode);
        }
    }
    // in updateRegrets
        // 2. calculate the utility (temporary) by weighting children's utilities
        // 3. use that and the children's utilities, and OUR reachprob (reachProbs[player]) to calculate newest regret
        // 4. update cumulativeRegrets with newest regret and OUR reachprob
    // back in this function
        // 5. use cumulativeRegrets to update strategy

    // adds cumulativeRegrets to strategy
    std::transform(strategy.begin(), strategy.end(),
        cumulativeRegrets.begin(), strategy.begin(), std::plus<int>());
}

Trainable::TrainableType CfrTrainable::getType() {
    return Trainable::CFR_TRAINABLE;
}
