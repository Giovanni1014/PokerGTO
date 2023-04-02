#include "util/Trainable.h"

Trainable::Trainable() {}

Trainable::Trainable(shared_ptr<ActionNode> action_node)
{
    this->action_node = action_node;
    this->action_number = action_node.
}