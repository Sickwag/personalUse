#pragma once
#include <boost/json.hpp>
#include <filesystem>
#include <regex>
#include <string>
#include <tabulate/table.hpp>
#include <unordered_map>
#include <unordered_set>
#include "arg_parse.h"
#include "config.h"

namespace tab = tabulate;
namespace fs = std::filesystem;

enum class Language {
    C_FAMILY,
    PYTHON,
    JAVASCRIPT,
    JAVA,
    UNKNOWN
};

struct CodeStats {
    std::string file_path;
    int total_lines = 0;
    int code_lines = 0;
    int comment_lines = 0;
    int blank_lines = 0;
    int mixed_lines = 0;

    boost::json::object to_json_object();
    void add_to_terminal_row(tab::Table& parent);
    void add_to_terminal_col(tab::Table& parent);
    std::string to_csv_row(bool);

    std::string CodeStats_to_string(const std::string& delimiter, bool include_filename);
    CodeStats& operator+=(const CodeStats& other) {
        this->blank_lines += other.blank_lines;
        this->code_lines += other.code_lines;
        this->comment_lines += other.comment_lines;
        this->mixed_lines += other.mixed_lines;
        this->total_lines += other.total_lines;
        return *this;
    }
    // void process_mode(Output_type& type);
};

class Counter {
   private:
    struct LanguagePatterns {
        std::regex single_line_comment;
        std::regex multi_line_comment_start;
        std::regex multi_line_comment_end;
        std::regex string_pattern;
        std::unordered_set<std::string> extensions;
    };
    std::unordered_map<Language, LanguagePatterns> patterns_;
    std::vector<CodeStats> count_result_;

    const Config& cfg_;
    const ParsedArgs& args_;

    Language detect_language(const std::string& file_path) const;
    Language detect_language(const fs::path& file_path) const;
    Language try_detect_by_content(const std::string& file_path) const;
    Language try_detect_by_content(const fs::path& file_path) const;
    void analyze_single_file(const std::string& file_path);
    void analyze_single_file(const fs::path& file_path);
    void analyze_directory(const std::string& directory_path);

    void process_line(std::string& line, Language lang, bool& in_multi_line_comment, std::string& current_delimiter, CodeStats& stats) const;
    std::string remove_strings(const std::string& line, const std::regex& string_pattern) const;
    bool has_non_whitespace(const std::string& s) const;
    std::string trim_right(const std::string& s) const;

   public:
    Counter(const Config& cfg_, const ParsedArgs& args_);
    void start();
    std::vector<CodeStats>& get_count_result();
};
