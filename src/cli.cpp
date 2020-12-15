#include "cli.hpp"
#include "config.hpp"

#include <iostream>
#include <map>


const std::map<std::string, std::function<void()>> PROGRAMS;

namespace cli {
    std::function<void()> parse_args(int argc, const char** argv) {
        // NOTE: there has to be a better way to do this string comparison
        if (argc == 2 && (std::string{argv[1]} == "--version" || std::string{argv[1]} == "-v")) {
            return [] { std::cout << "BotNet " << VERSION << std::endl; };
        }
        else {
            return [] { std::cout << "error: invalid argument(s) provided" << std::endl; };
        }
    }
}
