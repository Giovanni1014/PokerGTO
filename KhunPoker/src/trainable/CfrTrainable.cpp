#include "CfrTrainable.h"

CfrTrainable::CfrTrainable() {

}

const vector<float> CfrTrainable::getStrategy() {

}

void CfrTrainable::updateRegrets(const array<vector<float>, 2>& reachProbs) {
    // * calls getUtility of this actionNode
}

void CfrTrainable::updateStrategy(const array<vector<float>, 2>& reachProbs) {
    // 1. call updateStrategy of ChildrenTrainables
    // in updateRegrets
        // 2. calculate the utility (temporary) by weighting children's utilities
        // 3. use that and the children's utilities, and OUR reachprob (reachProbs[player]) to calculate newest regret
        // 4. update cumulativeRegrets with newest regret and OUR reachprob
    // back in this function
        // 5. use cumulativeRegrets to update strategy

}

Trainable::TrainableType CfrTrainable::getType() {
    return Trainable::CFR_TRAINABLE;
}
