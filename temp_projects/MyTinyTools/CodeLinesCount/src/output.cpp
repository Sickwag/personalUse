#include "output.h"
#include <algorithm>
#include <boost/algorithm/string/join.hpp>
#include <boost/json.hpp>
#include <fstream>
#include <tabulate/color.hpp>
#include <tabulate/font_align.hpp>
#include <tabulate/table.hpp>
#include "config.h"
#include "utils.h"

namespace json = boost::json;

Outputer::Outputer(Config& cfg, std::vector<CodeStats>& count_result, ParsedArgs& args) : cfg_(cfg), count_result_(count_result), args_(args), sum_({"", 0, 0, 0, 0, 0}) {
    for (auto& item : count_result_) {
        sum_ += item;
    }
    switch (cfg_.sort_method) {
        case (static_cast<int>(Sort_method::FILEPATH)):
            std::sort(count_result_.begin(), count_result_.end(), [](auto& lhs, auto& rhs) { return lhs.file_path < rhs.file_path; });
            break;
        case (static_cast<int>(Sort_method::BLANK_SUM)):
            std::sort(count_result_.begin(), count_result_.end(), [](auto& lhs, auto& rhs) { return lhs.blank_lines < rhs.blank_lines; });
            break;
        case (static_cast<int>(Sort_method::COMMENT_SUM)):
            std::sort(count_result_.begin(), count_result_.end(), [](auto& lhs, auto& rhs) { return lhs.comment_lines < rhs.comment_lines; });
            break;
        case (static_cast<int>(Sort_method::MIXED_SUM)):
            std::sort(count_result_.begin(), count_result_.end(), [](auto& lhs, auto& rhs) { return lhs.mixed_lines < rhs.mixed_lines; });
            break;
        case (static_cast<int>(Sort_method::TOTAL_SUM)):
            std::sort(count_result_.begin(), count_result_.end(), [](auto& lhs, auto& rhs) { return lhs.total_lines < rhs.total_lines; });
            break;
        default: {
            std::cerr << "wrong config item in \"sort type\" \n";
        }
    }
}

void Outputer::to_json() {
    // unfortunately, prettify json file by indents is not support in boost.json
    json::object root;
    json::array workspace;
    root["count_time"] = get_current_time_str();
    for (const auto& f : args_.file_list) {
        workspace.push_back(json::string(f));
    }
    for (const auto& d : args_.directory_list) {
        workspace.push_back(json::string(d + "\\"));
    }
    root["final_sum"] = std::move(sum_.to_json_object());
    root["workspace"] = std::move(workspace);
    json::array file_list;
    for (auto& item : count_result_) {
        file_list.push_back(item.to_json_object());
    }
    root["file_list"] = std::move(file_list);
    std::ofstream output_json(fs::path(args_.output_path) / "line-count-result.json");
    output_json << json::serialize(root);
    output_json.close();
}

void Outputer::to_csv() {
    auto make_csv_row = [](CodeStats& record, bool include_filename) -> std::string {
        return record.CodeStats_to_string(",", include_filename) + "\n";
    };
    std::ofstream output_csv(fs::path(args_.output_path) / "line-count-result.csv");
    output_csv << std::string("=", 50);
    output_csv << get_current_time_str() << "\n";
    for (const auto& f : args_.file_list) {
        output_csv << f << "\n";
    }
    for (const auto& d : args_.directory_list) {
        output_csv << d << "\\\n";
    }
    output_csv << std::string("-", 50);
    output_csv << boost::algorithm::join(bitmask_to_container<Display_column>(cfg_.display), ",") << "\n";
    for (auto& record : count_result_) {
        output_csv << make_csv_row(record, true);
    }
    output_csv << "\n\n"
               << "total count," << make_csv_row(sum_, false) << "\n\n";  // csv header
    output_csv.close();
}

void Outputer::to_terminal() {
    // lib tabulate cannot output merged cells, but it works satisfactory
    tab::Table sum_table;
    sum_table.format().font_align(tab::FontAlign::left);
    sum_table.add_row({"sum", ""}).format().font_style({tab::FontStyle::bold});
    sum_table[0].format().font_align(tab::FontAlign::center);
    sum_.add_to_terminal_col(sum_table);

    std::cout << sum_table << "\n\n\n";

    tab::Table details;
    details.format().font_align(tab::FontAlign::left);

    details.add_row({"details", "", "", "", "", ""}).format().font_style({tab::FontStyle::bold});
    details[0].format().font_align(tab::FontAlign::center);
    details.add_row({"file path", "total", "code", "comment", "mixed", "blank"});
    for (auto& item : count_result_) {
        item.add_to_terminal_row(details);
    }

    std::cout << details << "\n\n\n";
}

void Outputer::start() {
    if (cfg_.output_type & static_cast<int>(Output_type::JSON)) {
        this->to_json();
    }
    if (cfg_.output_type & static_cast<int>(Output_type::CSV)) {
        this->to_csv();
    }
    if (cfg_.output_type & static_cast<int>(Output_type::TERMINAL)) {
        this->to_terminal();
    }
    std::cout << "done." << std::endl;
}
