#include "mancala/UserPlayer.hpp"

#include "mancala/View.hpp"
#include "mancala/Player.hpp"

namespace mancala {

void UserPlayer::make_move() {
    unsigned int move = view.prompt_move(id());
    board().sow(id(), move);
}

}
