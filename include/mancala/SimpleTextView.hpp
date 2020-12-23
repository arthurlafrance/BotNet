#ifndef MANCALA_SIMPLETEXTVIEW_HEADER
#define MANCALA_SIMPLETEXTVIEW_HEADER

#include "mancala/View.hpp"

#include "mancala/Board.hpp"
#include "mancala/GameOutcome.hpp"

namespace mancala {

class SimpleTextView : public mancala::View {
public:
    virtual ~SimpleTextView() { }

    virtual void refresh(const Board& board, unsigned int current_player);
    virtual unsigned int prompt(unsigned int player);
    virtual void game_over(mancala::GameOutcome outcome);
};

}

#endif
