#ifndef BEST_RESPONSE_H
#define BEST_RESPONSE_H

#include <vector>
#include "Deck.h"
#include "Player.h"
#include "GameTreeNode.h"

using std::vector;

class BestResponse {
public:
    BestResponse(
        // vector<vector<PrivateCards>>& private_combos,
        int player_number,
        // PrivateCardsManager& pcm,
        // RiverRangeManager& rrm,
        Deck& deck,
        bool debug,
        // int color_iso_offset[][4],
        // GameTreeNode::GameRound split_round,
        int nthreads = 1);

    float printExploitability(shared_ptr<GameTreeNode> root, int iterationCount, float initial_pot, uint64_t initialBoard);

    float getBestReponseEv(shared_ptr<GameTreeNode> node, Player player, vector<vector<float>> reach_probs, uint64_t initialBoard, int deal);

private:
    Deck& deck;
    // player -> preflop combos
    // vector<vector<PrivateCards>>& private_combos;
    vector<int> player_hands;
    Player player;
    // RiverRangeManager& rrm;
    // PrivateCardsManager& pcm;
    bool debug;
    vector<vector<float>> reach_probs;
    int nthreads;

    // vector<float> bestResponse(shared_ptr<GameTreeNode> node, int player, const vector<vector<float>>& reach_probs, uint64_t board,int deal);
    // vector<float> chanceBestReponse(shared_ptr<ChanceNode> node, int player, const vector<vector<float>>& reach_probs, uint64_t current_board,int deal);
    // vector<float> actionBestResponse(shared_ptr<ActionNode> node, int player, const vector<vector<float>>& reach_probs, uint64_t board,int deal);
    // vector<float> terminalBestReponse(shared_ptr<TerminalNode> node, int player, const vector<vector<float>>& reach_probs, uint64_t board,int deal);
    // vector<float> showdownBestResponse(shared_ptr<ShowdownNode> node, int player, const vector<vector<float>>& reach_probs,uint64_t board,int deal);
    // int color_iso_offset[52 * 52 * 2][4];
    // GameTreeNode::GameRound split_round;
};

#endif // BEST_RESPONSE_H
