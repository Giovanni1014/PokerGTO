/**
 * @file GameState.h
 * @brief contains the GameState class, see brief below.
 */

#ifndef KHUNSOLVER_INCLUDE_GAMESTATE_H_
#define KHUNSOLVER_INCLUDE_GAMESTATE_H_

#include <util/Deck.h>
#include <util/Street.h>


/** 
 * @class GameState
 * @brief holds all game state logic, similar to Rule in TexasSolver
 * 
 * See TexasSolver's implemenetation at:
 * https://github.com/bupticybee/TexasSolver/blob/master/include/tools/Rule.h
 */
class GameState
{
  public:
    Deck deck;

    Street street; //the current street (preflop, flop, turn, river)

    float oop_mip; //the out of position player's money in pot
    float ip_mip; //the in position player's money in pot
    float effective_stack; //the smallest stack size between two players

    GameState(
      Deck deck,
      Street street,
      float oop_mip,
      float ip_mip,
      float effective_stack
    );
};

#endif //KHUNSOLVER_INCLUDE_GAMESTATE_H_