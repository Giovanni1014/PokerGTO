#include "GameTreeNode.h"

vector<float> GameTreeNode::getUtility(const Player player) {
    return this->utility[static_cast<int>(player)];
}
