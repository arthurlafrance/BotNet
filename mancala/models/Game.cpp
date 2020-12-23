#include "mancala/Game.hpp"

namespace mancala {

void Game::start() {
    // main loop:
    while (true) {
        view.refresh(board, current_player);

        mancala::Move move;

        if (current_player == 1) {
            move = player1->make_move();

            if (move == mancala::Move::TURN_DONE) {
                current_player = 2;
            }
        }
        else {
            move = player2->make_move();
            
            if (move == mancala::Move::TURN_DONE) {
                current_player = 1;
            }
        }

        if (move == mancala::Move::QUIT) {
            break;
        }
    }
}

}
