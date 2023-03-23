/**
 * @file GameState.h
 * @brief contains the GameState class, see brief below.
 */

#ifndef KHUNSOLVER_INCLUDE_GAMESTATE_H_
#define KHUNSOLVER_INCLUDE_GAMESTATE_H_

#include <game/Deck.h>

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
    float oop_mip;
    float ip_mip;
    
};

#endif //KHUNSOLVER_INCLUDE_GAMESTATE_H_