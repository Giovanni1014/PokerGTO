#ifndef SOLVER_H
#define SOLVER_H

#include "GameTree.h"
#include "ActionNode.h"
#include "Card.h"
#include <vector>

using std::vector, std::shared_ptr;

class Solver { 
    public: 
        enum MonteCarolAlg { 
            NONE,
            PUBLIC
        };
        Solver();
        Solver(shared_ptr<GameTree> tree);
        shared_ptr<GameTree> getTree();
        virtual void train() = 0;
        virtual void stop() = 0;
        // virtual json dumps(bool with_status, int depth) = 0;
        virtual vector<vector<vector<float>>> get_strategy(shared_ptr<ActionNode> node, vector<Card> cards) = 0;
        virtual vector<vector<vector<float>>> get_evs(shared_ptr<ActionNode> node, vector<Card> cards) = 0;
        shared_ptr<GameTree> tree;
};

#endif // SOLVER_H