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
    // 2. 

}

Trainable::TrainableType CfrTrainable::getType() {
    return Trainable::CFR_TRAINABLE;
}
