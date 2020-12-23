#ifndef MANCALA_USERPLAYER_HEADER
#define MANCALA_USERPLAYER_HEADER

#include "mancala/Player.hpp"
#include "mancala/Game.hpp"
#include "mancala/Move.hpp"

namespace mancala {

class UserPlayer : public mancala::Player {
public:
    virtual mancala::Move make_move(unsigned int player, mancala::Game& game);
};

}

#endif
