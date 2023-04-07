#include "util/Trainable.h"

Trainable::Trainable() {}

Trainable::Trainable(shared_ptr<ActionNode> action_node)
{
    this->action_node = action_node;
    this->action_number = action_node->getChildrens().size();
}

const vector<float> Trainable::getAverageStrategy()
{
    return this->getCurrentStrategy();
}

const vector<float> Trainable::getCurrentStrategy()
{
    if (this->regrets_positive_sum.empty())
    {
        fill(return_value.begin(), return_value.end(), 1.0 / this->action_number);
    }
    else
    {
        for (int action_id = 0; action_id < action_number; action_id++)
        {
            for (int private_id = 0; private_id < this->card_number; private_id++)
            {
                int index = action_id * this->card_number + private_id;
                if (this->regrets_positive_sum[private_id] != 0)
                {
                    return_value[index] = this->regrets_positive[index] / this->regrets_positive_sum[private_id];
                }
                else
                {
                    return_value[index] = 1.0 / this->action_number;
                }
                if (this->regrets_positive[index] != this->regrets_positive[index])
                    throw std::runtime_error("nan found");
            }
        }
    }
    return return_value;
}

void Trainable::updateRegrets(const vector<double> &regrets, int iteration_number, const vector<double> &reach_probabilities)
{
    this->regrets = regrets;
    if (regrets.size() != this->action_number * this->card_number)
    {
        throw std::runtime_error("length not match");
    }
    fill(regrets_positive_sum.begin(), regrets_positive_sum.end(), 0);
    fill(cumulative_regrets_positive_sum.begin(), cumulative_regrets_positive_sum.end(), 0);
    for (int action_id = 0; action_id < action_number; action_id++)
    {
        for (int private_id = 0; private_id < this->card_number; private_id++)
        {
            int index = action_id * this->card_number + private_id;
            float one_reg = regrets[index];

            this->regrets_positive[index] = std::max((float)0.0, one_reg + this->regrets_positive[index]);
            this->regrets_positive[private_id] += this->regrets_positive[index];

            this->cumulative_regrets_positive[index] += this->regrets_positive[index] * iteration_number;
            this->cumulative_regrets_positive_sum[private_id] += this->cumulative_regrets_positive[index];
        }
    }
}
