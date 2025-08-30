#include "arg_parse.h"
#include <CLI/App.hpp>
#include <string>
#include <vector>
#include "utils.h"

ParsedArgs arg_parse(int argc, char** argv) {
    CLI::App app{"CodeLinesCount - A tool to count code lines"};
    ParsedArgs args;
    app.add_option("-f, --file", args.file_list, "the file(s) you wanna count (require)")
        ->check(CLI::ExistingFile);

    app.add_option("-d, --directory", args.directory_list, "the file(s) in directory(s) you wanna count")
        ->check(CLI::ExistingDirectory);

    app.add_option("-o, --output", args.output_path, "the result output path")
        ->default_str(get_exec_path());

    args.config_file_path = "";
    app.add_option("-c, --config", args.config_file_path, "config file path (json file)");

    app.parse_complete_callback([&args]() {
        if (args.file_list.empty() && args.directory_list.empty()) {
            throw CLI::ValidationError("at least one of -d and -f argument have to be no empty");
        }
    });

    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError& e) {
        std::exit(app.exit(e));
    }
    return args;
}
