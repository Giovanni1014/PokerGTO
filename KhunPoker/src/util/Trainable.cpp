#include "util/Trainable.h"

Trainable::Trainable() {}

Trainable::Trainable(shared_ptr<ActionNode> action_node)
{
    this->action_node = action_node;
    this->action_number = action_node.
}

const vector<float> CfrPlusTrainable::getAverageStrategy()
{
    return this->getcurrentStrategy();
}

const vector<float> CfrPlusTrainable::getcurrentStrategy()
{
    if (this->r_plus_sum.empty())
    {
        fill(retval.begin(), retval.end(), 1.0 / this->action_number);
    }
    else
    {
        for (int action_id = 0; action_id < action_number; action_id++)
        {
            for (int private_id = 0; private_id < this->card_number; private_id++)
            {
                int index = action_id * this->card_number + private_id;
                if (this->r_plus_sum[private_id] != 0)
                {
                    retval[index] = this->r_plus[index] / this->r_plus_sum[private_id];
                }
                else
                {
                    retval[index] = 1.0 / this->action_number;
                }
                if (this->r_plus[index] != this->r_plus[index])
                    throw runtime_error("nan found");
            }
        }
    }
    return retval;
}

void CfrPlusTrainable::updateRegrets(const vector<float> &regrets, int iteration_number, const vector<float> &reach_probs)
{
    this->regrets = regrets;
    if (regrets.size() != this->action_number * this->card_number)
        throw runtime_error("length not match");

    // Arrays.fill(this.r_plus_sum,0);
    fill(r_plus_sum.begin(), r_plus_sum.end(), 0);
    fill(cum_r_plus_sum.begin(), cum_r_plus_sum.end(), 0);
    for (int action_id = 0; action_id < action_number; action_id++)
    {
        for (int private_id = 0; private_id < this->card_number; private_id++)
        {
            int index = action_id * this->card_number + private_id;
            float one_reg = regrets[index];

            // 更新 R+
            this->r_plus[index] = max((float)0.0, one_reg + this->r_plus[index]);
            this->r_plus_sum[private_id] += this->r_plus[index];

            // 更新累计策略
            this->cum_r_plus[index] += this->r_plus[index] * iteration_number;
            this->cum_r_plus_sum[private_id] += this->cum_r_plus[index];
        }
    }
}

