#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <stdexcept>

namespace fs = std::filesystem;

// 自定义异常类
class DirectoryCreatorException : public std::runtime_error {
public:
    explicit DirectoryCreatorException(const std::string& message)
        : std::runtime_error(message) {}
};

// 工具函数命名空间
namespace utils {
    // 去除字符串两端的空白字符
    std::string trim(const std::string& str) {
        const std::string WHITESPACE = " \t\n\r\f\v";
        size_t first = str.find_first_not_of(WHITESPACE);
        if (std::string::npos == first) {
            return str;
        }
        size_t last = str.find_last_not_of(WHITESPACE);
        return str.substr(first, (last - first + 1));
    }

    // 显示使用方法
    void print_usage(const std::string& program_name) {
        std::cout << "Usage: " << program_name << " <input_structure_file> <output_directory>\n";
        std::cout << "Example: " << program_name << " structure.txt output_dir\n";
    }
}

// 文件结构解析类
class StructureParser {
public:
    // 解析行，提取名称和层级
    static std::pair<int, std::string> parse_line(const std::string& line) {
        // 1. 移除注释
        std::string clean_line = line;
        size_t comment_pos = clean_line.find("//");
        if (comment_pos != std::string::npos) {
            clean_line = clean_line.substr(0, comment_pos);
        }

        if (utils::trim(clean_line).empty()) {
            return {-1, ""};
        }

        // 2. 提取名称 and find branch position
        size_t branch_pos = clean_line.find("├");
        if (branch_pos == std::string::npos) {
            branch_pos = clean_line.find("└");
        }

        std::string name;
        int level;

        if (branch_pos == std::string::npos) {
            // 根元素
            level = 0;
            name = utils::trim(clean_line);
        } else {
            // 非根元素，层级基于分支符号的缩进位置
            level = (branch_pos / 4) + 1;

            size_t name_start_pos = clean_line.find_last_of("─");
            name = utils::trim(clean_line.substr(name_start_pos + 1));
        }

        return {level, name};
    }
};

// 目录创建器类
class DirectoryCreator {
public:
    DirectoryCreator(const std::string& input_file, const std::string& output_dir)
        : input_file_(input_file), output_dir_(output_dir) {}

    void create_structure() {
        validate_paths();
        std::vector<std::string> path_components;
        std::string line;
        std::ifstream file(input_file_);

        while (std::getline(file, line)) {
            process_line(line, path_components);
        }

        std::cout << "Directory structure created successfully in: " << output_dir_ << std::endl;
    }

private:
    std::string input_file_;
    std::string output_dir_;

    void validate_paths() {
        if (!fs::exists(input_file_)) {
            throw DirectoryCreatorException("Input file does not exist: " + input_file_);
        }

        try {
            if (!fs::exists(output_dir_)) {
                fs::create_directories(output_dir_);
            }
        } catch (const fs::filesystem_error& e) {
            throw DirectoryCreatorException("Failed to create output directory: " + std::string(e.what()));
        }
    }

    void process_line(const std::string& line, std::vector<std::string>& path_components) {
        auto [level, name] = StructureParser::parse_line(line);

        if (name.empty()) {
            return;
        }

        adjust_path_components(level, path_components);
        fs::path current_path = build_current_path(path_components);
        bool is_dir = check_if_directory(name);
        
        if (is_dir) {
            name.pop_back();
        }

        create_filesystem_entry(current_path / name, is_dir, path_components, name);
    }

    void adjust_path_components(int level, std::vector<std::string>& path_components) {
        if (level < static_cast<int>(path_components.size())) {
            path_components.resize(level);
        }
        if (level == 0) {
            path_components.clear();
        }
    }

    fs::path build_current_path(const std::vector<std::string>& path_components) {
        fs::path current_path(output_dir_);
        for (const auto& component : path_components) {
            current_path /= component;
        }
        return current_path;
    }

    bool check_if_directory(std::string& name) {
        return name.back() == '/';
    }

    void create_filesystem_entry(const fs::path& new_path, bool is_dir, 
                               std::vector<std::string>& path_components, 
                               const std::string& name) {
        try {
            if (is_dir) {
                fs::create_directories(new_path);
                path_components.push_back(name);
            } else {
                ensure_parent_directory_exists(new_path);
                create_empty_file(new_path);
            }
            std::cout << "Created: " << new_path << std::endl;
        } catch (const fs::filesystem_error& e) {
            std::cerr << "Warning: Failed to create " << new_path << ": " << e.what() << std::endl;
        }
    }

    void ensure_parent_directory_exists(const fs::path& path) {
        if (!path.parent_path().empty() && !fs::exists(path.parent_path())) {
            fs::create_directories(path.parent_path());
        }
    }

    void create_empty_file(const fs::path& path) {
        std::ofstream outfile(path);
        if (!outfile) {
            throw DirectoryCreatorException("Failed to create file: " + path.string());
        }
    }
};


// 硬编码版本只需修改main函数，其他部分与版本1相同
int main() {
    try {
        // 硬编码输入文件和输出目录
        const std::string input_file = "D:\\Code Files\\vscode\\CCpp\\projects\\DirectoryFromText\\structure.txt";
        const std::string output_dir = "D:\\output_structure";

        DirectoryCreator creator(input_file, output_dir);
        creator.create_structure();
        return 0;

    } catch (const DirectoryCreatorException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }
}
