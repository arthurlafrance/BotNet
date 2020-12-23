#include "mancala/Game.hpp"

#include "mancala/GameOutcome.hpp"

namespace mancala {

void Game::start() {
    // main loop:
    while (true) {
        view().refresh(board(), current_player);

        mancala::Move move;

        if (current_player == 1) {
            move = player1.make_move(current_player, *this);

            if (move == mancala::Move::TURN_DONE) {
                current_player = 2;
            }
        }
        else {
            move = player2.make_move(current_player, *this);
            
            if (move == mancala::Move::TURN_DONE) {
                current_player = 1;
            }
        }

        if (move == mancala::Move::QUIT) {
            break;
        }

        mancala::GameOutcome outcome = board().game_over();

        if (outcome != mancala::GameOutcome::CONTINUING) {
            view().game_over(outcome);
            break;
        }
    }
}

}
