#ifndef CLI_HEADER
#define CLI_HEADER

#include <string>
#include <functional>

namespace cli {
    std::function<void(void)> parseArgs(int argc, const char** argv);
}

#endif
