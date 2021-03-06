#include "cli.hpp"

#include <functional>

int main(int argc, const char** argv) {
    std::function<void(void)> command = cli::parse_args(argc, argv);
    command();

    return 0;
}

