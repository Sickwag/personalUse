#include "utils.h"
#include "config.h"
#include <boost/json.hpp>
#include <boost/algorithm/string.hpp>
#include <string_view>
#include <chrono>
#include <string>
namespace json = boost::json;

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
std::string get_exec_path() {
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    return std::string(path);
}
#elif defined(__linux__)
#include <limits.h>
#include <unistd.h>
std::string get_exec_path() {
    char path[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", path, PATH_MAX);
    if (count != -1) {
        path[count] = '\0';
        return std::string(path);
    } else {
        throw std::runtime_error("Error getting executable path");
    }
}
#else
#error "Unsupported platform"
#endif

inline std::string get_current_time_str() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    return ctime(&now_c);
}

inline std::vector<std::regex> transfor_glob_to_reg(const std::vector<std::string>& globs) {
    std::vector<std::regex> result;
    for(const auto& glob : globs){
        result.emplace_back(glob_to_regex(glob));
    }
    return result;
}

std::string glob_to_regex(const std::string& glob) {
    static const std::unordered_map<char, std::string> replacements = {
        {'*', ".*"}, {'?', "."}, {'.', "\\."}, {'\\', "\\\\"}, {'+', "\\+"}, {'^', "\\^"}, {'$', "\\$"}, {'(', "\\("}, {')', "\\)"}, {'|', "\\|"}, {'{', "\\{"}, {'}', "\\}"}, {'[', "\\["}, {']', "\\]"}};
    std::string result;
    result.reserve(glob.size() * 2);
    for (char c : glob) {
        if (auto it = replacements.find(c); it != replacements.end()) {
            result += it->second;
        } else {
            result += c;
        }
    }
    return "^" + result + "$";
}

