#include "Board.hpp"

#include <vector>
#include <stdexcept>
#include <iostream>

#include "GameOutcome.hpp"

namespace mancala {

Board::Board() 
 : stores{0, 0} {
    for (unsigned int i = 0; i < 2; ++i) {
        for (unsigned int j = 0; j < Board::PITS; ++j) {
            pits[i][j] = 3;
        }
    }
}


Board::Board(unsigned int stores[2], unsigned int pits[2][PITS]) { 
    for (unsigned int i = 0; i < 2; ++i) {
        this->stores[i] = stores[i];

        for (unsigned int j = 0; j < Board::PITS; ++j) {
            this->pits[i][j] = pits[i][j];
        }
    }
}


unsigned int Board::store(unsigned int player) {    
    if (player < 0 || player > 1) {
        throw std::out_of_range("attempted to access out-of-range player");
    }

    return stores[player];
}


unsigned int Board::pit(unsigned int player, unsigned int pit) { 
    if (player < 0 || player > 1) {
        throw std::out_of_range("attempted to access out-of-range player");
    }
    else if (pit < 0 || pit > Board::PITS - 1) {
        throw std::out_of_range("attempted to access out-of-range pit");
    }

    return pits[player][pit];
}


// Sows the pit for the given player
void Board::sow(unsigned int player, unsigned int pit) {
    if (player < 0 || player > 1) {
        throw std::out_of_range("attempted to access out-of-range player");
    }
    else if (pit < 0 || pit > Board::PITS - 1) {
        throw std::out_of_range("attempted to access out-of-range pit");
    }

    unsigned int& pieces = pits[player][pit];
    
    unsigned int row = player;
    int col = pit - 1;

    while (pieces > 0) {
        if (col < -1) {
            row = row > 0 ? row - 1 : 1;
            col = Board::PITS - 1;
        }

        if (col >= 0) {
            ++(pits[row][col]);
        }
        else {
            ++(stores[row]);
        }

        --pieces;
        --col;
    }
}


// Returns a vector of legal moves the given player can make
std::vector<unsigned int> Board::legal_moves(unsigned int player) {
    if (player < 0 || player > 1) {
        throw std::out_of_range("attempted to access out-of-range player");
    }
    
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

// tests:
    // p1 win
    // p2 win
    // draw


// Returns the outcome of the game at the current state
mancala::GameOutcome Board::game_over() {
    bool board_empty = true;

    for (unsigned int i = 0; i < 2; ++i) {
        for (unsigned int j = 0; j < Board::PITS; ++j) {
            if (pits[i][j] != 0) {
                board_empty = false;
            }
        }
    }

    if (board_empty) {
        if (stores[0] > stores[1]) {
            return GameOutcome::P1_WIN;
        }
        else if (stores[0] < stores[1]) {
            return GameOutcome::P2_WIN;
        }
        else {
            return GameOutcome::DRAW;
        }
    }
    else {
        return GameOutcome::CONTINUING;
    }
}

}
