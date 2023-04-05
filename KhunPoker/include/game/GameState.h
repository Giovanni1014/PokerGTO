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
  // Deck deck;
  // Street street; //the current street (preflop, flop, turn, river)
  Player player_turn; //IP or OP
  float allin_threshold;
  // float initial_effective_stack; //the smallest stack size between two players
  int ip_commit; //the in position player's money in pot
  int oop_commit; //the out of position player's money in pot
  // int pot;
  int bet_count;

  GameState(
    // const Deck& deck,
    // Street& street,
    int oop_commit,
    int ip_commit,
    // int pot,

    float allin_threshold,
    Player player_turn,
    int bet_count

  ) : //deck(deck),
    // street(street),
    oop_commit(oop_commit),
    ip_commit(ip_commit),
    // pot(pot),
    allin_threshold(allin_threshold),
    player_turn(player_turn),
    bet_count(bet_count) {
  }
};

#endif //GAMESTATE_H
