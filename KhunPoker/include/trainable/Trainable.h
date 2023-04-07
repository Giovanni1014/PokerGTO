#ifndef TRAINABLE_H
#define TRAINABLE_H

#include <vector>

using namespace std;

class Trainable {
    public:
        enum TrainableType { };
        virtual const vector<float> getAverageStrategy() = 0;
        virtual const vector<float> getCurrentStrategy() = 0;
        virtual void updateRegrets(const vector<float>& regrets, int iteration_number, const vector<float>& reach_probs) = 0;
        virtual void copyStrategy(shared_ptr<Trainable> other_trainable) = 0;
        virtual TrainableType get_type() = 0;
};

#endif // TRAINABLE_H 