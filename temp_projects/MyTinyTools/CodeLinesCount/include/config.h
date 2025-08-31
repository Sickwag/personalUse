#pragma once
#include <boost/json.hpp>
#include <regex>
#include <string>
#include <vector>

namespace json = boost::json;

constexpr static int OUTPUT = 3;
enum class Output_type {
    CSV = 1 << 0,
    JSON = 1 << 1,
    TERMINAL = 1 << 2,
};

constexpr static int SORT = 6;
enum class Sort_method {
    FILEPATH = 1 << 3,
    TOTAL_SUM = 1 << 4,
    CODE_SUM = 1 << 5,
    COMMENT_SUM = 1 << 6,
    BLANK_SUM = 1 << 7,
    MIXED_SUM = 1 << 8,
};

constexpr static int DISPLAY = 4;
enum class Display_column {
    TOTAL = 1 << 9,
    CODE = 1 << 10,
    COMMENT = 1 << 11,
    BLANK = 1 << 12,
};

constexpr int OUTPUT_MASK = (1 << OUTPUT) - 1;             // (1 << 3) - 1 = 8 - 1 = 7 (0b111) 最终0b000000000000111 (位 0-2)
constexpr int SORT_MASK = ((1 << SORT) - 1) << OUTPUT;     // (1 << 6) - 1 = 64 - 1 = 63 (0b111111)需要左移 最终// 0b000111111111000 (位 3-8)
constexpr int DISPLAY_MASK = ((1 << DISPLAY) - 1) << (OUTPUT+SORT);// (1 << 4) - 1 = 16 - 1 = 15 (0b1111)需要左移 最终// 0b111100000000000 (位 9-12)

struct Config {
    // 2+4 configuration
    // std::string include, exclude;
    std::vector<std::regex> include, exclude; // TOTEST: have not test include and exclude glob
    int display;
    int output_type;
    int sort_method;
};

Config read_config(const std::string& config_path);
