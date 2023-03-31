/**
 * @file GameState.h
 * @brief contains the GameState struct, see brief below.
 */

#ifndef KHUNSOLVER_INCLUDE_GAMESTATE_H_
#define KHUNSOLVER_INCLUDE_GAMESTATE_H_

#include <util/Deck.h>
#include <util/Street.h>


/** 
 * @struct GameState
 * @brief holds all game state logic, similar to Rule in TexasSolver
 * 
 * See TexasSolver's implemenetation at:
 * https://github.com/bupticybee/TexasSolver/blob/master/include/tools/Rule.h
 */
struct GameState
{
  Deck deck;

  Street street; //the current street (preflop, flop, turn, river)

  float oop_commit; //the out of position player's money in pot
  float ip_commit; //the in position player's money in pot
  float effective_stack; //the smallest stack size between two players

  GameState(
    Deck deck,
    Street street,
    float oop_commit,
    float ip_commit,
    float initial_effective_stack,
    float allin_threshold,
    Player player_turn
    // float small_blind, (holdem only)
    // float big_blind
  );
};

#endif //KHUNSOLVER_INCLUDE_GAMESTATE_H_