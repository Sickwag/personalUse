#include <CLI11/CLI11.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include<filesystem>
#include "filter.h"
#include "counter.h"
#include "CLI_parser.h"
namespace fs = std::filesystem;
using InputArgs = std::vector<std::string>;

int main(int argc, char** argv) {
    try {
        Filter filter;
        CLI_parser parser(argc, argv, filter);
        parser.start();
        return 0;
    } catch (const CLI::ParseError& e) {
        std::cerr << "[CLI::ParseError]" << e.what() << std::endl;
        return e.get_exit_code();
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 2;
    }
}
