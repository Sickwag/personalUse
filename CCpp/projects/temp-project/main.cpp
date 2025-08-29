#include "main.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

CodeAnalyzer::CodeAnalyzer() {
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
        {"python", "py"}
    };
    patterns_[Language::JAVA] = patterns_[Language::C_FAMILY];
    patterns_[Language::JAVASCRIPT] = patterns_[Language::C_FAMILY];
}

Language CodeAnalyzer::detect_language(const std::string& filename) const {
    fs::path p(filename);
    for(const auto& pattern : patterns_){
        if(pattern.second.extensions.contains(p.filename().extension().string())){
            return pattern.first;
        }
    }
    return Language::UNKNOWN;
}

Language CodeAnalyzer::try_detect_by_content(const std::string& filename) const {
    std::ifstream file(filename);
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

CodeStats CodeAnalyzer::analyze_file(const std::string& filename) const {
    Language lang = detect_language(filename);
    if (lang == Language::UNKNOWN) {
        lang = try_detect_by_content(filename);
        if (lang == Language::UNKNOWN) {
            throw std::runtime_error("cannot identify the type of" + filename);
            // TODO add ignore and explain reason
        }
    }
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("cannot open this file " + filename);
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
    return stats;
}

void CodeAnalyzer::process_line(std::string& line, Language lang, bool& in_multi_line_comment, std::string& current_delimiter, CodeStats& stats) const {
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

std::string CodeAnalyzer::remove_strings(const std::string& line, const std::regex& string_pattern) const {
    return std::regex_replace(line, string_pattern, "\"\"");
}

bool CodeAnalyzer::has_non_whitespace(const std::string& s) const {
    return std::any_of(s.begin(), s.end(), [](unsigned char c) {
        return !std::isspace(c);
    });
}

std::string CodeAnalyzer::trim_right(const std::string& s) const {
    size_t end = s.find_last_not_of(" \t\r\n");
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}