#ifndef TRAINABLE_H
#define TRAINABLE_H

#include <vector>
using namespace std;

class Trainable {
    private:
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
        
        const vector<float> getAverageStrategy();
        const vector<float> getCurrentStrategy();
        void updateRegrets(const vector<double> &regrets, int iteration_number, const vector<double> &reach_probabilities);
};

#endif