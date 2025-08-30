#pragma once
#include <boost/algorithm/string.hpp>
#include <boost/json.hpp>
#include "config.h"
#include <regex>
#include <string>
#include <vector>

namespace json = boost::json;

std::string get_exec_path();
std::string get_current_time_str();
std::vector<std::regex> transfor_glob_to_reg(const std::vector<std::string>& globs);
std::string glob_to_regex(const std::string& glob);


template <typename EnumT>
struct EnumMapping;

template <>
struct EnumMapping<Output_type> {
    static constexpr std::array<std::pair<const char*, Output_type>, 3> values = {{{"CSV", Output_type::CSV},
                                                                                   {"JSON", Output_type::JSON},
                                                                                   {"TERMINAL", Output_type::TERMINAL}}};
};

template <>
struct EnumMapping<Sort_method> {
    static constexpr std::array<std::pair<const char*, Sort_method>, 6> values = {{{"FILEPATH", Sort_method::FILEPATH},
                                                                                   {"TOTAL_SUM", Sort_method::TOTAL_SUM},
                                                                                   {"CODE_SUM", Sort_method::CODE_SUM},
                                                                                   {"COMMENT_SUM", Sort_method::COMMENT_SUM},
                                                                                   {"BLANK_SUM", Sort_method::BLANK_SUM},
                                                                                   {"MIXED_SUM", Sort_method::MIXED_SUM}}};
};

template <>
struct EnumMapping<Display_column> {
    static constexpr std::array<std::pair<const char*, Display_column>, 4> values = {{{"TOTAL", Display_column::TOTAL},
                                                                                      {"CODE", Display_column::CODE},
                                                                                      {"COMMENT", Display_column::COMMENT},
                                                                                      {"BLANK", Display_column::BLANK}}};
};

template <typename EnumT>
int generate_bitmask(const json::object& section_obj) {
    int bitmask = 0;

    for (const auto& mapping : EnumMapping<EnumT>::values) {
        auto it = section_obj.find(mapping.first);
        if (it != section_obj.end() &&
            it->value().is_bool() &&
            it->value().as_bool()) {
            bitmask |= static_cast<int>(mapping.second);
        }
    }

    return bitmask;
}

template <typename EnumT>
const char* enum_to_str(EnumT e) {
    for (const auto& mapping : EnumMapping<EnumT>::values) {
        if (mapping.second == e) {
            return mapping.first;
        }
    }
    return "";
}
