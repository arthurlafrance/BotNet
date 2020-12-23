#ifndef MANCALA_GAME_HEADER
#define MANCALA_GAME_HEADER

#include "mancala/Board.hpp"
#include "mancala/Player.hpp"
#include "mancala/UserPlayer.hpp"
#include "mancala/View.hpp"
#include "mancala/GameOutcome.hpp"

namespace mancala {

class Game {
public:
    Game(mancala::View& view);
    
    Game(const Game& game) = delete;
    Game& operator=(const Game& game) = delete;

    ~Game();

    void start();

private:
    mancala::Board board;

    mancala::Player* player1;
    mancala::Player* player2;
    int current_player;
    
    mancala::View& view;
};

inline Game::Game(mancala::View& view)
 : current_player(1), player1(new mancala::UserPlayer(1, board, view)), player2(new mancala::UserPlayer(2, board, view)), view(view) { }

inline Game::~Game() {
    delete player1;
    delete player2;
}

}

#endif
