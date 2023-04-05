#ifndef TRAINABLE_H
#define TRAINABLE_H

#include <vector>
#include "nodes/ActionNode.h"

using namespace std;

class Trainable {
    private:
        shared_ptr<ActionNode> action_node;
        // vector<PrivateCards> private_cards;
        int action_number;
        int card_number;
        vector<float> regrets_positive;
        vector<float> regrets_positive_sum;
        vector<float> cumulative_regrets_positive;
        vector<float> cumulative_regrets_positive_sum;
        vector<float> regrets;
        vector<float> return_value;

    public:
        Trainable();
        Trainable(shared_ptr<ActionNode> action_node);
        const vector<float> getAverageStrategy();
        const vector<float> getCurrentStrategy();
        void setEv(const vector<float> &evs) = 0; // only used for discountedCFR
        void copyStrategy(shared_ptr<Trainable> other_trainable) = 0;
        void updateRegrets(const vector<double> &regrets, int iteration_number, const vector<double> &reach_probabilities);
};

#endif