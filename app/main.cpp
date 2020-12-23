#include <functional>

#include "app/cli.hpp"

#include "mancala/SimpleTextView.hpp"
#include "mancala/Game.hpp"
#include "mancala/UserPlayer.hpp"

int main(int argc, const char** argv) {
//    std::function<void(void)> command = cli::parse_args(argc, argv);
//    command();

    // TODO: dealloc args

    mancala::SimpleTextView view;

    mancala::UserPlayer p1;
    mancala::UserPlayer p2;

    mancala::Game g(p1, p2, view);
    g.start();

    return 0;
}

