#pragma once
#include <boost/algorithm/string.hpp>
#include <boost/json.hpp>
#include <regex>
#include <string>
#include <vector>
#include "config.h"

namespace json = boost::json;

std::string get_exec_path();
std::string get_current_time_str();
std::vector<std::regex> transfor_glob_to_reg(const std::vector<std::string>& globs);
std::string glob_to_regex(const std::string& glob);

template <typename EnumT>
struct EnumMapping;

template <>
struct EnumMapping<Output_type> {
    static constexpr std::array<std::pair<const char*, Output_type>, 3> values = {{{"csv", Output_type::CSV},
                                                                                   {"json", Output_type::JSON},
                                                                                   {"TERMINAL", Output_type::TERMINAL}}};
};

template <>
struct EnumMapping<Sort_method> {
    static constexpr std::array<std::pair<const char*, Sort_method>, 6> values = {{{"filepath", Sort_method::FILEPATH},
                                                                                   {"total_sum", Sort_method::TOTAL_SUM},
                                                                                   {"code_sum", Sort_method::CODE_SUM},
                                                                                   {"comment_sum", Sort_method::COMMENT_SUM},
                                                                                   {"mixed_sum", Sort_method::MIXED_SUM},
                                                                                   {"blank_sum", Sort_method::BLANK_SUM}}};
};

template <>
struct EnumMapping<Display_column> {
    static constexpr std::array<std::pair<const char*, Display_column>, 5> values = {{{"total", Display_column::TOTAL},
                                                                                      {"code", Display_column::CODE},
                                                                                      {"comment", Display_column::COMMENT},
                                                                                      {"blank", Display_column::BLANK},
                                                                                      {"mixed", Display_column::MIXED}}};
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

template <typename EnumT, typename Elem_Type = std::string> // TODO: unused
std::vector<Elem_Type> bitmask_to_container(int bitmask) {
    std::vector<Elem_Type> res;
    for (const auto& mapping : EnumMapping<EnumT>::values) {
        if (bitmask & static_cast<int>(mapping.second)) {
            res.emplace_back(mapping.first);
        }
    }
    return res;
}