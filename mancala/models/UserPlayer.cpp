#include "mancala/UserPlayer.hpp"

#include "mancala/View.hpp"
#include "mancala/Player.hpp"
#include "mancala/Move.hpp"

namespace mancala {

mancala::Move UserPlayer::make_move() {
    unsigned int move = view.prompt(id());

    if (move > 0) {
        if (board().sow(id(), move)) {
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
