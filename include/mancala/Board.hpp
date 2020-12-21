#ifndef MANCALA_BOARD_HEADER
#define MANCALA_BOARD_HEADER

#include <vector>
#include <iostream>

#include "mancala/GameOutcome.hpp"

namespace mancala {

class Board {
public:
    static constexpr unsigned int PITS = 6; // I'll assume there's only 2 players, but pits could vary
    
    // Constructs a new board object
    Board();

    // (For debugging) Construct a new board with the given initial state
    Board(unsigned int stores[2], unsigned int pits[2][PITS]);

    // Returns the number of pieces in the given store
    unsigned int store(unsigned int player) const;

    // Returns the number of pieces in the given pit
    unsigned int pit(unsigned int player, unsigned int pit) const;

    // Sows the pit for the given player
    void sow(unsigned int player, unsigned int pit);

    // Returns a vector of legal moves the given player can make
    std::vector<unsigned int> legal_moves(unsigned int player) const;
    
    // Returns the outcome of the game at the current state
    GameOutcome game_over() const;

    // Insert the board into the stream
    friend std::ostream& operator<<(std::ostream& stream, const Board& board);

private:
    unsigned int stores[2]; // 1 store per player
    unsigned int pits[2][PITS]; // 1 row of 6 pits for each player 
};

}
#endif // BOARD_HEADER
