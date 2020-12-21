#ifndef MANCALA_VIEW_HEADER
#define MANCALA_VIEW_HEADER

#include "mancala/GameOutcome.hpp"
#include "mancala/Board.hpp"

namespace mancala {

class View {
public:
    virtual void refresh(const mancala::Board& board, unsigned int current_player); 
    virtual unsigned int prompt_move(unsigned int player);
    virtual void game_over(mancala::GameOutcome outcome);
};

}

#endif
