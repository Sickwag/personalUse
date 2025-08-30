#include "output.h"
#include <utils.h>
#include <algorithm>
#include <boost/json.hpp>
#include <fstream>
#include <tabulate/color.hpp>
#include <tabulate/font_align.hpp>
#include <tabulate/table.hpp>

namespace json = boost::json;

Outputer::Outputer(Config& cfg, std::vector<CodeStats>& count_result, ParsedArgs& args) : cfg_(cfg), count_result_(count_result), args_(args), sum_({"", 0, 0, 0, 0, 0}) {
    for (auto& item : count_result_) {
        sum_ += item;
    }
    switch (cfg_.sort_method){
        case (static_cast<int>(Sort_method::FILEPATH)):
            std::sort(count_result_.begin(), count_result_.end(), [](auto& lhs, auto& rhs) { return lhs.file_path < rhs.file_path; });
        case (static_cast<int>(Sort_method::BLANK_SUM)):
            std::sort(count_result_.begin(), count_result_.end(), [](auto& lhs, auto& rhs) { return lhs.blank_lines < rhs.blank_lines; });
        case (static_cast<int>(Sort_method::COMMENT_SUM)):
            std::sort(count_result_.begin(), count_result_.end(), [](auto& lhs, auto& rhs) { return lhs.comment_lines < rhs.comment_lines; });
        case (static_cast<int>(Sort_method::MIXED_SUM)):
            std::sort(count_result_.begin(), count_result_.end(), [](auto& lhs, auto& rhs) { return lhs.mixed_lines < rhs.mixed_lines; });
        case (static_cast<int>(Sort_method::TOTAL_SUM)):
            std::sort(count_result_.begin(), count_result_.end(), [](auto& lhs, auto& rhs) { return lhs.total_lines < rhs.total_lines; });
    }

}

void Outputer::to_json() {
    json::object root, workspace;
    root["count_time"] = get_current_time_str();
    json::array workspace;
    for (const auto& f : args_.file_list) {
        workspace.insert(f);
    }
    for (const auto& d : args_.directory_list) {
        workspace.insert(d);
    }
    root["final_sum"] = std::move(sum_.to_json_object());
    root["workspace"] = std::move(workspace);
    json::array file_list;
    for (auto& item : count_result_) {
        file_list.push_back(item.to_json_object());
    }
    root["file_list"] = std::move(file_list);
    std::ofstream output_json(args_.output_path);
    output_json << json::serialize(root);
    output_json.close();
}

void Outputer::to_csv() {
    auto make_csv_row = [](CodeStats& record) -> std::string {
        return record.to_string(",") + "\n";
    };
    std::ofstream output_csv(args_.output_path);
    output_csv << make_csv_row(sum_);

    for (auto& record : count_result_) {
        output_csv << make_csv_row(record);
    }
    output_csv.close();
}

void Outputer::to_terminal() {
    tab::Table sum_table;
    sum_table.format().font_align(tab::FontAlign::left);
    sum_table.add_row({"sum"}).format().font_style({tab::FontStyle::bold});
    sum_.add_to_terminal_col(sum_table);

    std::cout << sum_table << "\n\n\n";

    tab::Table details;
    details.format().font_align(tab::FontAlign::left);
    details.add_row({"details"}).format().font_style({tab::FontStyle::bold});
    for (auto& item : count_result_) {
        item.add_to_terminal_row(details);
    }

    std::cout << details << "\n\n\n";
}

void Outputer::start() {
    if (cfg_.output_type & static_cast<int>(Output_type::JSON))
        this->to_json();
    if (cfg_.output_type & static_cast<int>(Output_type::CSV))
        this->to_csv();
    if (cfg_.output_type & static_cast<int>(Output_type::TERMINAL))
        this->to_terminal();
}