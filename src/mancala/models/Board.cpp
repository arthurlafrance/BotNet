#include "Board.hpp"

#include <vector>
#include "GameOutcome.hpp"

namespace mancala {

// Sows the pit for the given player
void Board::sow(unsigned int player, unsigned int pit) {
    // TODO: bounds check
    unsigned int pieces = pits[player][pit];
    
    unsigned int row = player;
    unsigned int col = pit - 1;

    while (pieces > 0) {
        if (col < 0) {
            row = row > 0 ? row - 1 : Board::PLAYERS - 1;
            col = Board::PITS - 1;
        }

        ++(pits[row][col]);
        --pieces;
    }
}


// Returns a vector of legal moves the given player can make
std::vector<unsigned int> Board::legal_moves(unsigned int player) {
    // TODO: bounds check
    unsigned int (&row)[Board::PITS] = pits[player];

    std::vector<unsigned int> moves;

    for (unsigned int i = 0; i < Board::PITS; ++i) {
        unsigned int pit = row[i];

        if (pit != 0) {
            moves.push_back(i);
        }
    }

    return moves;
}


// Returns the outcome of the game at the current state
mancala::GameOutcome Board::game_over() {
    return mancala::GameOutcome::CONTINUING;
}

}
