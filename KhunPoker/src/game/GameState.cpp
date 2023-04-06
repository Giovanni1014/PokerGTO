#include "util/Street.h"
#include "util/Player.h"

/**
 * @struct GameState
 * @brief holds all game state logic, similar to Rule in TexasSolver
 *
 * See TexasSolver's implemenetation at:
 * https://github.com/bupticybee/TexasSolver/blob/master/include/tools/Rule.h
*/
struct GameState {
    Street street; //the current street (INGAME, TERMINAL) not (preflop, flop, turn, river)
    int oop_commit; //the out of position player's money in pot
    int ip_commit; //the in position player's money in pot
    Player player_turn; //IP or OP
    int bet_count;

    GameState(
        Street street,
        int oop_commit,
        int ip_commit,
        Player player_turn,
        int bet_count
    ) :
        street(street),
        oop_commit(oop_commit),
        ip_commit(ip_commit),
        player_turn(player_turn),
        bet_count(bet_count) {
    }
};
