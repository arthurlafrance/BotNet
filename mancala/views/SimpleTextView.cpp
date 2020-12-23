#include "mancala/SimpleTextView.hpp"

#include <iostream>

#include "mancala/Board.hpp"
#include "mancala/GameOutcome.hpp"

namespace mancala {

void SimpleTextView::refresh(const mancala::Board& board, unsigned int current_player) {
    std::cout << "Current board:" << std::endl << std::endl;
    std::cout << board << std::endl;
    std::cout << "Player " << current_player << " makes next move" << std::endl << std::endl;
}


unsigned int SimpleTextView::prompt(unsigned int player) {
    std::cout << "[Player " << player << "] choose a pit to sow: ";
    
    unsigned int pit;
    std::cin >> pit;

    // TODO: input validation

    return pit;
}


void SimpleTextView::game_over(mancala::GameOutcome outcome) {
    switch (outcome) {
    case mancala::GameOutcome::P1_WIN:
        std::cout << "Player 1 won the game!" << std::endl;
        break;
    case mancala::GameOutcome::P2_WIN:
        std::cout << "Player 2 won the game!" << std::endl;
        break;
    case mancala::GameOutcome::DRAW:
        std::cout << "It's a draw; no one won the game!" << std::endl;
        break;
    case mancala::GameOutcome::CONTINUING:
        break;
    }
}

}
