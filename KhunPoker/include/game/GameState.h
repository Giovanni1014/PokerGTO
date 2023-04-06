#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <util/Deck.h>
#include <util/Player.h>
#include <util/Street.h>

/**
 * @struct GameState
 * @brief holds all game state logic, similar to Rule in TexasSolver
 *
 * See TexasSolver's implemenetation at:
 * https://github.com/bupticybee/TexasSolver/blob/master/include/tools/Rule.h
*/
struct GameState {
    Deck deck;
    Street street; //the current street (preflop, flop, turn, river)
    Player player_turn; //IP or OP
    float initial_effective_stack; //the smallest stack size between two players
    float ip_commit; //the in position player's money in pot
    float oop_commit; //the out of position player's money in pot

  GameState(
    const Deck& deck,
    Street& street,
    float oop_commit,
    float ip_commit,
    float initial_effective_stack,
    float allin_threshold,
    Player player_turn
  );
};

#endif //GAMESTATE_H