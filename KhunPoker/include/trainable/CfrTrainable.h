#ifndef CFRTRAINABLE_H
#define CFRTRAINABLE_H


#include "ActionNode.h"
#include "Trainable.h"

#include <array>
#include <algorithm>
#include <numeric>
#include <vector>

using std::vector, std::shared_ptr, std::array;

class CfrTrainable : Trainable {
public:
    enum TrainableType {};

    CfrTrainable(shared_ptr<ActionNode> actionNode);

    CfrTrainable();

    const vector<float> getStrategy() override;

    void updateStrategy(const array<vector<float>, 2>& reachProbs) override;

    Trainable::TrainableType getType() override;
    
    std::string toString();

private:
    void updateRegrets(const array<vector<float>, 2>& reachProbs) override;

    shared_ptr<ActionNode> actionNode;
    const vector<shared_ptr<CfrTrainable>> childrenTrainables;
    vector<float> strategy; // * dim: (number of private hands) * (number of actions)
    vector<float> cumulativeRegrets; // * dim: (number of private hands) * (number of actions)
    int iterationCount;
};

#endif // CFRTRAINABLE_H 
