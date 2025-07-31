#pragma once
#include <CLI11/CLI11.hpp>
#include <filesystem>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "counter.h"
#include "filter.h"
namespace fs = std::filesystem;
using InputArgs = std::vector<std::string>;

class CLI_parser {
   private:
    CLI::App app;
    Filter& filter;
    InputArgs input_language, input_filepath;
    bool include_doc = false;
    bool include_data = false;
    bool include_config = false;
    bool short_path = false;
    int& argc;
    char** argv;

   public:
    CLI_parser(int argc, char** argv, Filter& f);
    int start();
    void display(const std::pair<fs::path, std::vector<FileInfo>>& result) const;
};