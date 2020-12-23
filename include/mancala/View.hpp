#ifndef MANCALA_VIEW_HEADER
#define MANCALA_VIEW_HEADER

#include "mancala/GameOutcome.hpp"
#include "mancala/Board.hpp"

namespace mancala {

class View {
public:
    View() { }
    virtual ~View() { }

    virtual void refresh(const mancala::Board& board, unsigned int current_player) = 0; 
    virtual unsigned int prompt(unsigned int player) = 0;
    virtual void game_over(mancala::GameOutcome outcome) = 0;
};

}

#endif
