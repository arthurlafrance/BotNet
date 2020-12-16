#ifndef BOARD_HEADER
#define BOARD_HEADER

#include <vector>
#include "GameOutcome.hpp"

namespace mancala {

class Board {
public:
    // Sows the pit for the given player
    void sow(unsigned int player, unsigned int pit);

    // Returns a vector of legal moves the given player can make
    std::vector<unsigned int> legal_moves(unsigned int player);
    
    // Returns the outcome of the game at the current state
    GameOutcome game_over();

private:
    static constexpr unsigned int PLAYERS = 2;
    static constexpr unsigned int PITS = 6;

    unsigned int stores[PLAYERS]; // 1 store per player
    unsigned int pits[PLAYERS][PITS]; // 1 row of 6 pits for each player 
};

}
#endif // BOARD_HEADER
