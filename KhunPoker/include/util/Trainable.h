#ifndef TRAINABLE_H
#define TRAINABLE_H

#include <vector>
using namespace std;

class Trainable {
    private:
        vector<double> regrets;


    public:
        Trainable();

        void updateRegrets(const vector<double> &regrets, int iteration_number, const vector<double> &reach_probabilities);
};

#endif