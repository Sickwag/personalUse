#pragma once
#include <string>

inline std::string get_exec_path();
inline std::string get_current_time_str();
inline std::vector<std::regex> transfor_glob_to_reg(const std::vector<std::string>& globs);


template <typename EnumT>
struct EnumMapping;

template <>
struct EnumMapping<Output_type> {
    static constexpr std::array<std::pair<std::string_view, Output_type>, 3> values = {{{"CSV", Output_type::CSV},
                                                                                        {"JSON", Output_type::JSON},
                                                                                        {"TERMINAL", Output_type::TERMINAL}}};
};

template <>
struct EnumMapping<Sort_method> {
    static constexpr std::array<std::pair<std::string_view, Sort_method>, 6> values = {{{"FILEPATH", Sort_method::FILEPATH},
                                                                                        {"TOTAL_SUM", Sort_method::TOTAL_SUM},
                                                                                        {"CODE_SUM", Sort_method::CODE_SUM},
                                                                                        {"COMMENT_SUM", Sort_method::COMMENT_SUM},
                                                                                        {"BLANK_SUM", Sort_method::BLANK_SUM},
                                                                                        {"MIXED_SUM", Sort_method::MIXED_SUM}}};
};

template <>
struct EnumMapping<Display_column> {
    static constexpr std::array<std::pair<std::string_view, Display_column>, 4> values = {{{"TOTAL", Display_column::TOTAL},
                                                                                           {"CODE", Display_column::CODE},
                                                                                           {"COMMENT", Display_column::COMMENT},
                                                                                           {"BLANK", Display_column::BLANK}}};
};

template <typename EnumT>
int generate_bitmask(const json::object& section_obj) {
    int bitmask = 0;

    for (const auto& mapping : EnumMapping<EnumT>::values) {
        if (auto it = section_obj.find(mapping.first);
            it != section_obj.end() &&
            it->value().is_bool() &&
            it->value().as_bool()) {
            bitmask |= static_cast<int>(mapping.second);
        }
    }

    return bitmask;
}

template <typename EnumT>
std::string_view enum_to_str(EnumT e) {
    for (const auto& mapping : EnumMapping<EnumT>::values) {
        if (mapping.second == e) {
            std::string res = mapp.first;
            boost::to_lower(res);
            return res;
        }
    }
    return "";
}