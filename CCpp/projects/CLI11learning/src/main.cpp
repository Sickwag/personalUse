#include<iostream>
#include "CLI11.hpp"

int main(int argc, char** argv){
    CLI::App app("just test CLI 11 usage");
    // String option
    std::string filename;
    app.add_option("-f,--file", filename, "The input file");

    // Integer option
    int count = 1;
    app.add_option("-n,--count", count, "Number of iterations")->check(CLI::PositiveNumber);

    // Float option
    double value = 0.0;
    app.add_option("-v,--value", value, "A floating point value");

    // Vector option (can take multiple values)
    std::vector<std::string> files;
    app.add_option("-i,--input", files, "Input files")->expected(1, -1);

    int debug_level = 0;
    app.add_flag("-d, --debug", debug_level, "Debug level(can be repeated).");
    CLI11_PARSE(app, argc, argv);
    std::cout << filename << count << value;
    for(const auto& it : files){
        std::cout << it << " ";
    }
    auto utils = app.get_subcommands([](const CLI::App* sub) {
        return sub->get_group() == "Utilities";
    });
}