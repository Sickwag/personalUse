#include "config.h"
#include "utils.h"
#include <boost/algorithm/string.hpp>
#include <boost/fusion/include/define_struct.hpp>
#include <boost/json.hpp>
#include <filesystem>
#include <fstream>
#include <regex>

namespace json = boost::json;
namespace fs = std::filesystem;

static void remove_utf8_bom(std::string& content) {
    if (content.size() >= 3 &&
        static_cast<unsigned char>(content[0]) == 0xEF &&
        static_cast<unsigned char>(content[1]) == 0xBB &&
        static_cast<unsigned char>(content[2]) == 0xBF) {
        content = content.substr(3);
    }
}

template <typename T>
static T get_key(const json::value& json, const std::string& key) {
    bool is_exist = json.is_object() && json.as_object().contains(key);
    if (is_exist) {
        return json::value_to<T>(json.as_object().at(key));
    } else {
        return T();
    }
}

void make_default_config_file() {
    json::object j;
    j["include"] = json::array_kind;
    j["exclude"] = json::array_kind;
    j["file_sum"] = true;
    j["comment_line_sum"] = true;
    j["code_sum"] = true;
    j["blank_line_sum"] = true;
    j["sort_method"] = "filename";
    fs::path cfg_file = fs::path(get_exec_path()) / "config.json";
    std::ofstream default_f(cfg_file);
    default_f << json::serialize(j);
}

Config read_config(const std::string& config_path) {
    if (config_path.empty()) {
        make_default_config_file();
    }
    fs::path cfg_file = fs::path(get_exec_path()) / "config.json";
    std::ifstream file(cfg_file);
    if (file.is_open()) {
        throw std::runtime_error("cannot open file " + config_path);
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    remove_utf8_bom(content);
    json::value j = json::parse(content);
    Config cfg;
    cfg.include = get_key<std::vector<std::string>>(j, "include");
    cfg.exclude = get_key<std::vector<std::string>>(j, "exclude");

    return cfg;
}


int parse_switch_set(boost::json::object set){
    int bitmask = 0;
    for(const auto& s : set){
        bitmask |= s.value().as_bool();
    }
    return bitmask;
}

void take_action_to_switches(int bitmask, Config& cfg){
    
}