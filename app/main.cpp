#include <functional>

#include "app/cli.hpp"

#include "mancala/SimpleTextView.hpp"
#include "mancala/Game.hpp"

int main(int argc, const char** argv) {
//    std::function<void(void)> command = cli::parse_args(argc, argv);
//    command();

    // TODO: dealloc args

    mancala::SimpleTextView view;
    mancala::Game g(view);
    g.start();

    return 0;
}

