#pragma once
#include <regex>
#include <string>
#include <unordered_map>
#include <unordered_set>
enum class Language {
    C_FAMILY,
    PYTHON,
    JAVASCRIPT,
    JAVA,
    UNKNOWN
};
struct CodeStats {
    int total_lines = 0;
    int code_lines = 0;
    int comment_lines = 0;
    int blank_lines = 0;
    int mixed_lines = 0;
    
};
class CodeAnalyzer {
   private:
    struct LanguagePatterns {
        std::regex single_line_comment;
        std::regex multi_line_comment_start;
        std::regex multi_line_comment_end;
        std::regex string_pattern;
        std::unordered_set<std::string> extensions;
    };
    std::unordered_map<Language, LanguagePatterns> patterns_;
    Language detect_language(const std::string& filename) const;
    Language try_detect_by_content(const std::string& filename) const;

    void process_line(std::string& line, Language lang, bool& in_multi_line_comment, std::string& current_delimiter, CodeStats& stats) const;
    std::string remove_strings(const std::string& line, const std::regex& string_pattern) const;
    bool has_non_whitespace(const std::string& s) const;
    std::string trim_right(const std::string& s) const;
   public:
    CodeAnalyzer();
    CodeStats analyze_file(const std::string& filename) const;
};
