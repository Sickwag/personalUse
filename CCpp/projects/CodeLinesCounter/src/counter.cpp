#include "counter.h"
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>

bool Counter::yes_or_no() const noexcept {
    std::string input;
    std::getline(std::cin, input);
    auto l = input.find_first_not_of(" \t\r\n");
    auto r = input.find_last_not_of(" \t\r\n");
    if (l == std::string::npos)
        input.clear();
    else
        input = input.substr(l, r - l + 1);
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input == "yes" || input == "y";
}

Counter::Counter(const std::string& target_directory, Filter& filter)
    : target_directory_(target_directory), filter_(filter) {
    if (filter.empty()) {
        std::cout << "You have not set any filter criteria. The program will count all text files. Do you want to continue?(y/n)" << '\n';
        if(!yes_or_no()) {
            std::exit(0);
        }
    }
    if (fs::is_regular_file(target_directory_)) {
        // If the target is a file, process it directly
        // std::cout << "your directory point to a file.\n" << std::endl; // This message might be redundant
        if(filter.render(target_directory_)){
            FileInfo fi = {
                target_directory_.generic_string(),
                target_directory_.filename().string(),
                words_count(target_directory_),
                lines_count(target_directory_)
            };
            filepath_lists_.emplace_back(fi);
        }
    } else if (!fs::exists(target_directory)) {
        std::cout << "your directory does not exist.\n" << std::endl;
        return;
    } else if (fs::is_directory(target_directory_)) {
        for (const auto& entry : fs::recursive_directory_iterator(target_directory_)) {
            if (filter.render(entry) && fs::is_regular_file(entry.path())) {
                FileInfo fi = {
                    entry.path().generic_string(),
                    entry.path().filename().string(),
                    words_count(entry.path()),
                    lines_count(entry.path())
                };
                filepath_lists_.emplace_back(fi);
            }
        }
    }
    std::cout << "processed " << filepath_lists_.size() << "file(s).\n";
}

Counter::~Counter() {
    filepath_lists_.clear();
    target_directory_.clear();
}

size_t Counter::words_count(const fs::path& file_path) {
    // base on spaceblank memory cost low
    // size_t word_total = 0;
    // std::fstream f(it.file_path_);
    // size_t word_total = 0;
    // std::string word;
    // while(f >> word){
    //     word_total++;
    // }
    // f.close();
    // return word_total;

    // base on regex, needs load all text in memory once but fast
    std::fstream f(file_path);
    if (!f.is_open()) {
        std::cerr << "Cannot open file: " << file_path << std::endl;
        return 0;
    }
    std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    f.close();
    std::regex re(R"(\b[a-zA-Z_]\w*\b)");
    auto wordsBegin = std::sregex_iterator(content.begin(), content.end(), re);
    auto wordEnd = std::sregex_iterator();
    return std::distance(wordsBegin, wordEnd);
}

size_t Counter::lines_count(const fs::path& file_path) {
    std::fstream f(file_path);
    if (!f.is_open()) {
        std::cerr << "Cannot open file: " << file_path << std::endl;
        return 0;
    }
    size_t line_count = 0;
    std::string line;
    while(std::getline(f,line)){
        line_count++;
    }
    f.close();
    return line_count;
}

std::pair<fs::path, std::vector<FileInfo>> Counter::get_result(const fs::path& file_path) {
    return std::pair<fs::path, std::vector<FileInfo>>(this->target_directory_, this->filepath_lists_);
}
