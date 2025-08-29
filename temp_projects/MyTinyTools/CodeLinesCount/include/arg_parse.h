#pragma once

struct ParsedArgs {
    std::vector<std::string> file_list;
    std::vector<std::string> directory_list;
    std::string output_path;
    std::string config_file_path;

    const std::vector<std::string>& files() const { return file_list; }
    const std::vector<std::string>& directories() const { return directory_list; }
    const std::string& output() const { return output_path; }
    const std::string& config() const { return config_file_path; }

    ParsedArgs& operator=(const ParsedArgs&) = delete;
};

ParsedArgs arg_parse(int argc, char** argv);