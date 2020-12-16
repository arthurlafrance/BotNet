#ifndef CLI_HEADER
#define CLI_HEADER

#include <string>
#include <functional>

namespace cli {
    std::function<void(void)> parse_args(int argc, const char** argv);
}

#endif
