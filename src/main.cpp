#include "cli.h"

#include <functional>

int main(int argc, const char** argv) {
    std::function<void(void)> command = cli::parseArgs(argc, argv);
    command();

    return 0;
}

