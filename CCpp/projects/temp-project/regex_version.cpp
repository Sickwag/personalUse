#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <unordered_map>

// 语言类型枚举
enum class Language {
    C_FAMILY,
    PYTHON,
    JAVASCRIPT,
    JAVA,
    UNKNOWN
};

// 统计结果
struct CodeStats {
    int total_lines = 0;
    int code_lines = 0;
    int comment_lines = 0;
    int blank_lines = 0;
    int mixed_lines = 0;

    void print() const {
        std::cout << "总行数: " << total_lines << "\n"
                  << "代码行: " << code_lines << "\n"
                  << "注释行: " << comment_lines << "\n"
                  << "空白行: " << blank_lines << "\n"
                  << "混合行: " << mixed_lines << "\n";
    }
};

class SimpleCodeAnalyzer {
   private:
    // 语言特定的正则表达式模式
    struct LanguagePatterns {
        std::regex single_line_comment;
        std::regex multi_line_comment_start;
        std::regex multi_line_comment_end;
        std::regex string_pattern;
    };

    std::unordered_map<Language, LanguagePatterns> patterns_;

   public:
    SimpleCodeAnalyzer() {
        initialize_patterns();
    }

    CodeStats analyze_file(const std::string& filename) {
        Language lang = detect_language(filename);
        if (lang == Language::UNKNOWN) {
            throw std::runtime_error("不支持的文件类型");
        }

        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("无法打开文件");
        }

        CodeStats stats;
        std::string line;
        bool in_multi_line_comment = false;

        while (std::getline(file, line)) {
            stats.total_lines++;
            process_line(line, lang, in_multi_line_comment, stats);
        }

        return stats;
    }

   private:
    void initialize_patterns() {
        // C++ 模式
        patterns_[Language::C_FAMILY] = {
            std::regex(R"(//)"),                                  // 单行注释
            std::regex(R"(/\*)"),                                 // 多行注释开始
            std::regex(R"(\*/)"),                                 // 多行注释结束
            std::regex(R"("(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*')")  // 字符串
        };

        // Python 模式
        patterns_[Language::PYTHON] = {
            std::regex(R"(#)"),                                   // 单行注释
            std::regex(R"(""")"),                                 // 多行注释开始
            std::regex(R"(""")"),                                 // 多行注释结束
            std::regex(R"("(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*')")  // 字符串
        };

        // Java/JavaScript 模式
        patterns_[Language::JAVA] = patterns_[Language::C_FAMILY];
        patterns_[Language::JAVASCRIPT] = patterns_[Language::C_FAMILY];
    }

    Language detect_language(const std::string& filename) {
        if (filename.ends_with(".cpp") || filename.ends_with(".h") ||
            filename.ends_with(".hpp") || filename.ends_with(".c")) {
            return Language::C_FAMILY;
        } else if (filename.ends_with(".py")) {
            return Language::PYTHON;
        } else if (filename.ends_with(".java")) {
            return Language::JAVA;
        } else if (filename.ends_with(".js") || filename.ends_with(".ts")) {
            return Language::JAVASCRIPT;
        }
        return Language::UNKNOWN;
    }

    void process_line(std::string& line, Language lang, bool& in_multi_line_comment, CodeStats& stats) {
        // 去除行尾空白
        line = std::regex_replace(line, std::regex("\\s+$"), "");

        if (line.empty()) {
            stats.blank_lines++;
            return;
        }

        const auto& patterns = patterns_[lang];

        if (in_multi_line_comment) {
            stats.comment_lines++;
            // 检查多行注释是否结束
            if (std::regex_search(line, patterns.multi_line_comment_end)) {
                in_multi_line_comment = false;
            }
            return;
        }

        // 检查多行注释开始
        if (std::regex_search(line, patterns.multi_line_comment_start)) {
            stats.comment_lines++;
            in_multi_line_comment = true;
            return;
        }

        // 移除字符串内容，避免字符串内的注释符号被误识别
        std::string line_without_strings = remove_strings(line, patterns.string_pattern);

        // 查找第一个注释符号位置
        std::smatch match;
        if (std::regex_search(line_without_strings, match, patterns.single_line_comment)) {
            size_t comment_pos = match.position();

            // 检查注释符号前是否有非空白内容
            std::string before_comment = line_without_strings.substr(0, comment_pos);
            bool has_code_before = std::any_of(before_comment.begin(), before_comment.end(),
                                               [](unsigned char c) { return !std::isspace(c); });

            if (has_code_before) {
                stats.mixed_lines++;
            } else {
                stats.comment_lines++;
            }
        } else {
            // 没有注释，纯代码行
            stats.code_lines++;
        }
    }

    std::string remove_strings(const std::string& line, const std::regex& string_pattern) {
        return std::regex_replace(line, string_pattern, "\"\"");
    }
};

// 使用示例
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "用法: " << argv[0] << " <文件名>" << std::endl;
        return 1;
    }

    SimpleCodeAnalyzer analyzer;
    try {
        CodeStats stats = analyzer.analyze_file(argv[1]);
        std::cout << "文件分析结果:\n";
        stats.print();
    } catch (const std::exception& e) {
        std::cerr << "错误: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}