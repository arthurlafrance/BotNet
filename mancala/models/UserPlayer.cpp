#include "mancala/UserPlayer.hpp"

#include "mancala/View.hpp"
#include "mancala/Player.hpp"
#include "mancala/Move.hpp"

namespace mancala {

mancala::Move UserPlayer::make_move(unsigned int player, mancala::Game& game) {
    unsigned int move = game.view().prompt(player);

    if (move > 0) {
        if (game.board().sow(player, move)) {
            return mancala::Move::TURN_CONTINUING;
        }
        else {
            return mancala::Move::TURN_DONE;
        }
    }
    else {
        return mancala::Move::QUIT;
    }
}

}
