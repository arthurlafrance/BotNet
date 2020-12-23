#ifndef MANCALA_PLAYER_HEADER
#define MANCALA_PLAYER_HEADER

#include "mancala/Game.hpp"
#include "mancala/Move.hpp"

namespace mancala {

class Game;

class Player {
public:
    virtual ~Player() { }
    virtual mancala::Move make_move(unsigned int player, mancala::Game& game) = 0;
};

}

#endif
