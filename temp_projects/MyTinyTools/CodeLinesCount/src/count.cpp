#include "count.h"
#include <algorithm>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <tabulate/table.hpp>

namespace fs = std::filesystem;
namespace tab = tabulate;

Counter::Counter(const Config& cfg, const ParsedArgs& args) : cfg_(cfg), args_(args) {
    patterns_[Language::C_FAMILY] = {
        std::regex(R"(//)"),
        std::regex(R"(/\*)"),
        std::regex(R"(\*/)"),
        std::regex(R"("(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*')"),
        {"cpp", "c", "cc", "cs", "h", "hpp", "c++"}};
    patterns_[Language::PYTHON] = {
        std::regex(R"(#)"),
        std::regex(R"("""|''')"),
        std::regex(R"("""|''')"),
        std::regex(R"("(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*')"),
        {"python", "py"}};
    patterns_[Language::JAVA] = patterns_[Language::C_FAMILY];
    patterns_[Language::JAVASCRIPT] = patterns_[Language::C_FAMILY];
}

void Counter::start() {
    for (const auto& f : args_.file_list) {
        analyze_single_file(f);
    }
    for (const auto& d : args_.directory_list) {
        analyze_directory(d);
    }
}

std::vector<CodeStats>& Counter::get_count_result() {
    return this->count_result_;
}

Language Counter::detect_language(const std::string& filename) const {
    fs::path p(filename);
    return detect_language(p);
}

Language Counter::detect_language(const fs::path& file_path) const {
    for (const auto& pattern : patterns_) {
        auto ext = file_path.filename().extension().string();
        if (!ext.empty() && pattern.second.extensions.contains(ext.substr(1))) {
            return pattern.first;
        }
    }
    return Language::UNKNOWN;
}
Language Counter::try_detect_by_content(const fs::path& file_path) const {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        // TODO: make an ignore with reason
    }
    std::string first_line;
    if (std::getline(file, first_line)) {
        if (first_line.starts_with("#!/usr/bin/env python") ||
            first_line.starts_with("#!/usr/bin/python")) {
            return Language::PYTHON;
        }
    }
    return Language::UNKNOWN;
}

Language Counter::try_detect_by_content(const std::string& filename) const {
    return try_detect_by_content(fs::path(filename));
}

void Counter::analyze_single_file(const std::string& file_path) {
    return analyze_single_file(fs::path(file_path));
}
void Counter::analyze_single_file(const fs::path& file_path) {
    if (!fs::is_regular_file(file_path))
        return;
    for (const auto& ex_reg : cfg_.exclude) {
        std::regex pattern = std::regex(ex_reg);
        if (std::regex_match(file_path.generic_string(), pattern)) {
            // TODO: add ignore reason
            return;
        }
    }
    if (!cfg_.exclude.empty()) {
        for (const auto& ex_reg : cfg_.exclude) {
            if (std::regex_search(file_path.generic_string(), std::regex(ex_reg))) {
                return;
            }
        }
    }
    Language lang = detect_language(file_path);
    if (lang == Language::UNKNOWN) {
        lang = try_detect_by_content(file_path);
        if (lang == Language::UNKNOWN) {
            std::cerr << "ignore unknow language in file: " << file_path << std::endl;
            return;
            // throw std::runtime_error("cannot identify the type of" + file_path.filename().string());
            // TODO add ignore and explain reason
        }
    }
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw std::runtime_error("cannot open this file " + file_path.filename().string());
        // TODO add ignore and explain reason
    }
    CodeStats stats;
    std::string line;
    bool in_multi_line_comment = false;
    std::string current_delimiter;
    while (std::getline(file, line)) {
        stats.total_lines++;
        process_line(line, lang, in_multi_line_comment, current_delimiter, stats);
    }
    stats.file_path = fs::path(file_path).generic_string();
    count_result_.push_back(stats);
}

void Counter::analyze_directory(const std::string& directory_path) {
    fs::path dir_path(directory_path);
    for (const auto& entry : fs::recursive_directory_iterator(dir_path)) {
        if (entry.is_regular_file()) {
            analyze_single_file(entry);
        }
    }
}

void Counter::process_line(std::string& line, Language lang, bool& in_multi_line_comment, std::string& current_delimiter, CodeStats& stats) const {
    line = trim_right(line);
    if (line.empty()) {
        stats.blank_lines++;
        return;
    }
    const auto& patterns = patterns_.at(lang);
    if (in_multi_line_comment) {
        stats.comment_lines++;
        if (line.find(current_delimiter) != std::string::npos) {
            in_multi_line_comment = false;
            current_delimiter.clear();
        }
        return;
    }
    std::string clean_line = remove_strings(line, patterns.string_pattern);
    std::smatch multi_match;
    if (std::regex_search(clean_line, multi_match, patterns.multi_line_comment_start)) {
        current_delimiter = multi_match.str();
        size_t start_pos = multi_match.position();
        size_t end_pos = clean_line.find(current_delimiter, start_pos + current_delimiter.length());
        if (end_pos != std::string::npos) {
            stats.comment_lines++;
        } else {
            stats.comment_lines++;
            in_multi_line_comment = true;
            std::string before_comment = clean_line.substr(0, start_pos);
            if (has_non_whitespace(before_comment)) {
                stats.mixed_lines++;
                stats.comment_lines--;
            }
        }
        return;
    }
    std::smatch single_match;
    if (std::regex_search(clean_line, single_match, patterns.single_line_comment)) {
        size_t comment_pos = single_match.position();
        std::string before_comment = clean_line.substr(0, comment_pos);
        if (has_non_whitespace(before_comment)) {
            stats.mixed_lines++;
        } else {
            stats.comment_lines++;
        }
    } else {
        stats.code_lines++;
    }
}

std::string Counter::remove_strings(const std::string& line, const std::regex& string_pattern) const {
    return std::regex_replace(line, string_pattern, "\"\"");
}

bool Counter::has_non_whitespace(const std::string& s) const {
    return std::any_of(s.begin(), s.end(), [](unsigned char c) {
        return !std::isspace(c);
    });
}

std::string Counter::trim_right(const std::string& s) const {
    size_t end = s.find_last_not_of(" \t\r\n");
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

boost::json::object CodeStats::to_json_object() {
    boost::json::object obj;
    obj["filepath"] = this->file_path;
    obj["total_lines"] = this->total_lines;
    obj["code_lines"] = this->code_lines;
    obj["comment_lines"] = this->comment_lines;
    obj["blank_lines"] = this->blank_lines;
    obj["mixed_lines"] = this->mixed_lines;
    return obj;
}

void CodeStats::add_to_terminal_row(tab::Table& table) {
    table.add_row({
        this->file_path,
        std::to_string(this->total_lines),
        std::to_string(this->code_lines),
        std::to_string(this->comment_lines),
        std::to_string(this->mixed_lines),
        std::to_string(this->blank_lines),
    });
}

void CodeStats::add_to_terminal_col(tab::Table& parent) {
    parent.add_row({"total_lines", std::to_string(this->total_lines)});
    parent.add_row({"code_lines", std::to_string(this->code_lines)});
    parent.add_row({"comment_lines", std::to_string(this->comment_lines)});
    parent.add_row({"mixed_lines", std::to_string(this->mixed_lines)});
    parent.add_row({"blank_lines", std::to_string(this->blank_lines)});
}

std::string CodeStats::to_csv_row() {
    return this->to_string(",");
}

std::string CodeStats::to_string(const std::string& delimiter = ", ") {
    return this->file_path + delimiter +
           std::to_string(this->total_lines) + delimiter +
           std::to_string(this->code_lines) + delimiter +
           std::to_string(this->comment_lines) + delimiter +
           std::to_string(this->mixed_lines) + delimiter +
           std::to_string(this->blank_lines);
}
