#include "mancala/Board.hpp"

#include <vector>
#include <stdexcept>
#include <iostream>

#include "mancala/GameOutcome.hpp"

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


unsigned int Board::store(unsigned int player) const {    
    if (player < 0 || player > 1) {
        throw std::out_of_range("attempted to access out-of-range player");
    }

    return stores[player];
}


unsigned int Board::pit(unsigned int player, unsigned int pit) const { 
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
std::vector<unsigned int> Board::legal_moves(unsigned int player) const {
    if (player < 0 || player > 1) {
        throw std::out_of_range("attempted to access out-of-range player");
    }
    
    const unsigned int (&row)[Board::PITS] = pits[player];

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
mancala::GameOutcome Board::game_over() const {
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

std::ostream& operator<<(std::ostream& stream, const Board& board) {
    // print top border:

    // 1 dash for left border
    // 1 dash for left margin
    // 1 dash for store left margin
    // 5 dashes for store space
    // 1 dash for store right margin
    stream << "---------"; // hard-coded for efficiency benefits

    // for each pit: 1 dash left margin, 3 dashes pit space, 1 dash right margin
    for (unsigned int i = 0; i < Board::PITS; ++i) {
        stream << "-----";
    }

    // 1 dash for right store left margin
    // 5 dashes for right store space
    // 1 dash for right store right margin
    // 1 dash right margin
    // 1 dash right border
    stream << "---------" << std::endl; // newline at the end to wrap to next line

    // print top margin:

    // 1 pipe for left border
    // 1 space for left margin
    // 1 space for store left margin
    // 5 spaces for store space
    // 1 space for store right margin
    stream << "|        "; // hard-coded for efficiency benefits

    // for each pit: 1 space left margin, 3 spaces pit space, 1 space right margin
    for (unsigned int i = 0; i < Board::PITS; ++i) {
        stream << "     ";
    }

    // 1 space for right store left margin
    // 5 spaces for right store space
    // 1 space for right store right margin
    // 1 space right margin
    // 1 pipe right border
    stream << "        |" << std::endl; // newline at the end to wrap to next line

    // print top of stores, top row of pits in between:
    
    // 1 pipe for left border
    // 1 space for left margin
    // 1 space for store left margin
    // 1 forward slash for store left edge
    // 3 spaces for store inside
    // 1 backslash for store right edge
    // 1 space for store right margin
    stream << "|  /   \\ ";

    // for each pit: 1 space left margin, open paren, pit value, close paren, 1 space right margin
    for (unsigned int i = 0; i < Board::PITS; ++i) {
        stream << " (" << board.pit(0, i) << ") ";
    }

    // 1 space for store left margin
    // 1 forward slash for store left edge
    // 3 spaces for store inside
    // 1 backslash for store right edge
    // 1 space for store right margin
    // 1 space for right margin
    // 1 pipe for right border
    stream << " /   \\  |" << std::endl;

    // print middle of stores, spaces in between

    // 1 pipe for left border
    // 1 space for left margin
    // 1 space for store left margin
    // 1 pipe for store left edge
    // 1 space for store left padding
    // store value
    // 1 space for store right padding
    // 1 pipe for store right edge
    // 1 space for store right margin
    stream << "|  | " << board.store(0) << " | ";
    
    // for each pit: 1 space left margin, 3 spaces pit contents, 1 space right margin
    for (unsigned int i = 0; i < Board::PITS; ++i) {
        stream << "     ";
    }

    // 1 space for store left margin
    // 1 pipe for store left edge
    // 1 space for store left padding
    // store value
    // 1 space for store right padding
    // 1 pipe for store right edge
    // 1 space for store right margin
    // 1 space for right margin
    // 1 pipe for right border
    stream << " | " << board.store(1) << " |  |" << std::endl;
    
    // print bottom of stores, bottom row of pits in between
    
    // 1 pipe for left border
    // 1 space for left margin
    // 1 space for store left margin
    // 1 backslash for store left edge
    // 3 spaces for store inside
    // 1 forward slash for store right edge
    // 1 space for store right margin
    stream << "|  \\   / ";

    // for each pit: 1 space left margin, open paren, pit value, close paren, 1 space right margin
    for (int i = Board::PITS - 1; i >= 0; --i) {
        stream << " (" << board.pit(1, i) << ") ";
    }

    // 1 space for store left margin
    // 1 backslash for store left edge
    // 3 spaces for store inside
    // 1 forward slash for store right edge
    // 1 space for store right margin
    // 1 space for right margin
    // 1 pipe for right border
    stream << " \\   /  |" << std::endl;
    
    // print bottom margin

    // 1 pipe for left border
    // 1 space for left margin
    // 1 space for store left margin
    // 5 spaces for store space
    // 1 space for store right margin
    stream << "|        "; // hard-coded for efficiency benefits

    // for each pit: 1 space left margin, 3 spaces pit space, 1 space right margin
    for (unsigned int i = 0; i < Board::PITS; ++i) {
        stream << "     ";
    }

    // 1 space for right store left margin
    // 5 spaces for right store space
    // 1 space for right store right margin
    // 1 space right margin
    // 1 pipe right border
    stream << "        |" << std::endl; // newline at the end to wrap to next line
    
    // print bottom border
    
    // 1 dash for left border
    // 1 dash for left margin
    // 1 dash for store left margin
    // 5 dashes for store space
    // 1 dash for store right margin
    stream << "---------"; // hard-coded for efficiency benefits

    // for each pit: 1 dash left margin, 3 dashes pit space, 1 dash right margin
    for (unsigned int i = 0; i < Board::PITS; ++i) {
        stream << "-----";
    }

    // 1 dash for right store left margin
    // 5 dashes for right store space
    // 1 dash for right store right margin
    // 1 dash right margin
    // 1 dash right border
    stream << "---------" << std::endl; // newline at the end to wrap to next line

    return stream;
}

}
