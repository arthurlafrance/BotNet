#ifndef MANCALA_PLAYER_HEADER
#define MANCALA_PLAYER_HEADER

#include "mancala/Board.hpp"
#include "mancala/Move.hpp"

namespace mancala {

class Player {
public:
    Player(unsigned int id, mancala::Board& board);

    virtual ~Player() { }

    unsigned int id() const;

    const mancala::Board& board() const;
    mancala::Board& board();

    virtual mancala::Move make_move() = 0;

private:
    mancala::Board& _board;
    unsigned int _id;
};


inline Player::Player(unsigned int id, mancala::Board& board)
 : _id(id), _board(board) { }


inline unsigned int Player::id() const {
    return _id;
}


inline const mancala::Board& Player::board() const {
    return _board;
}


inline mancala::Board& Player::board() {
    return _board;
}

}

#endif
