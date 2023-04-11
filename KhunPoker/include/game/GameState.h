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
  Street street; //the current street (INGAME, TERMINAL) not (preflop, flop, turn, river)
  int oopCommit; //the out of position player's money in pot
  int ipCommit; //the in position player's money in pot
  Player playerTurn; //IP or OP
  int betCount;

  GameState(
    Street street,
    int oopCommit,
    int ipCommit,
    Player playerTurn,
    int betCount
  ) :
    street(street),
    oopCommit(oopCommit),
    ipCommit(ipCommit),
    playerTurn(playerTurn),
    betCount(betCount) {
  }
};

#endif //GAMESTATE_H
