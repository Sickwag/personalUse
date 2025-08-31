#include "config.h"
#include "utils.h"
#include <boost/algorithm/string.hpp>
#include <boost/fusion/include/define_struct.hpp>
#include <boost/json.hpp>
#include <filesystem>
#include <fstream>
#include <regex>
#include <unordered_map>

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
    j["exclude"] = json::array_kind;

    // 创建display对象
    json::object display_obj;
    display_obj["TOTAL"] = true;
    display_obj["CODE"] = true;
    display_obj["COMMENT"] = true;
    display_obj["BLANK"] = true;
    j["display"] = std::move(display_obj);

    // 创建output_type对象
    json::object output_obj;
    output_obj["terminal"] = true;
    output_obj["csv"] = false;
    output_obj["json"] = false;
    j["output_type"] = std::move(output_obj);

    // 创建sort_method对象
    json::object sort_obj;
    sort_obj["filepath"] = true;
    sort_obj["total_sum"] = false;
    sort_obj["code_sum"] = false;
    sort_obj["comment_sum"] = false;
    sort_obj["blank_sum"] = false;
    sort_obj["mixed_sum"] = false;
    j["sort_method"] = std::move(sort_obj);

    // 获取可执行文件所在目录
    fs::path exe_path = fs::path(get_exec_path());
    fs::path cfg_file = exe_path.parent_path() / "config.json";
    std::ofstream default_f(cfg_file);
    default_f << json::serialize(j);
}

Config read_config(const std::string& config_path) {
    fs::path cfg_file;
    if (config_path.empty()) {
        // 获取可执行文件所在目录
        fs::path exe_path = fs::path(get_exec_path());
        // 检查配置文件是否存在，如果不存在则创建默认配置
        cfg_file = exe_path.parent_path() / "config.json";
        if (!fs::exists(cfg_file)) {
            make_default_config_file(); // UNTEST
        }
    } else {
        cfg_file = std::move(fs::path(config_path));
    }

    std::ifstream file(cfg_file);
    if (!file.is_open()) {
        throw std::runtime_error("cannot open file " + cfg_file.string());
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    remove_utf8_bom(content);
    json::value j = json::parse(content);
    Config cfg;
    cfg.exclude = get_key<std::vector<std::string>>(j, "exclude");   // UNTEST regex func
    cfg.display = generate_bitmask<Display_column>(get_key<json::object>(j, "display"));   // UNSURE binary value is right?
    cfg.output_type = generate_bitmask<Output_type>(get_key<json::object>(j, "output_type"));
    cfg.sort_method = generate_bitmask<Sort_method>(get_key<json::object>(j, "sort_method"));
    return cfg;
}
