#ifndef MANCALA_USERPLAYER_HEADER
#define MANCALA_USERPLAYER_HEADER

#include "mancala/Player.hpp"
#include "mancala/View.hpp"

namespace mancala {

class UserPlayer : public mancala::Player {
public:
    UserPlayer(unsigned int id, mancala::Board& board, mancala::View& view);
    virtual void make_move();

private:
    mancala::View& view;
};

inline UserPlayer::UserPlayer(unsigned int id, mancala::Board& board, mancala::View& view)
 : mancala::Player(id, board), view(view) { }

}

#endif
