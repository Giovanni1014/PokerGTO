#ifndef TRAINABLE_H
#define TRAINABLE_H

#include <vector>

using namespace std;

class Trainable {
public:
    enum TrainableType {
        CFR_TRAINABLE
    };

    virtual const vector<float> getStrategy() = 0;
    virtual void updateRegrets(const vector<float>& reachProbs) = 0;
    virtual void updateStrategy() = 0;
    virtual TrainableType getType() = 0;
};

#endif // TRAINABLE_H 
