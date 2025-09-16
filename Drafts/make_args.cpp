#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

void process_file(const std::string& path,
                  const std::string& pattern,
                  const std::string& repl) {
    std::ifstream in(path, std::ios::binary);
    std::ostringstream oss;
    oss << in.rdbuf();
    std::string content = oss.str();
    in.close();

    std::regex re(pattern);
    std::string out_str = std::regex_replace(content, re, repl);
    std::ofstream out(path, std::ios::binary);
    out_str.pop_back();
    out << out_str;
}

int main() {
    const std::string path = "D:/Code Files/vscode/Drafts/args.md";
    const std::string pattern = R"(\d+)";  // 匹配数字
    const std::string replace = "\"$&\",";       // 变成 "数字",
    process_file(path, pattern, replace);
    return 0;
}
