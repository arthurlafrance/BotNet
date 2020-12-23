#ifndef MANCALA_GAME_HEADER
#define MANCALA_GAME_HEADER

#include "mancala/Board.hpp"
#include "mancala/Player.hpp"
#include "mancala/View.hpp"

namespace mancala {

class Player;

class Game {
public:
    Game(mancala::Player& player1, mancala::Player& player2, mancala::View& view);
    
    Game(const Game& game) = delete;
    Game& operator=(const Game& game) = delete;

    mancala::Board& board();
    const mancala::Board& board() const;

    mancala::View& view();
    const mancala::View& view() const;

    void start();

private:
    mancala::Board _board;

    mancala::Player& player1;
    mancala::Player& player2;
    int current_player;
    
    mancala::View& _view;
};


inline Game::Game(mancala::Player& player1, mancala::Player& player2, mancala::View& view)
 : current_player(1), player1(player1), player2(player2), _view(view) { }


inline mancala::Board& Game::board() {
    return _board;
}


inline const mancala::Board& Game::board() const {
    return _board;
}


inline mancala::View& Game::view() {
    return _view;
}


inline const mancala::View& Game::view() const {
    return _view;
}

}

#endif
