#include "output.h"
#include <boost/json.hpp>
#include <chrono>
#include <tabulate/table.hpp>

namespace json = boost::json;

Ouputer::Ouputer(Config& cfg, std::vector<CodeStats>& count_result) : cfg_(cfg), count_result_(count_result) {}

void Ouputer::json() {
    json::object root;
    json::array file_list;
    root["count_time"] = get_current_time_str();
    for (auto& item : count_result_) {
        file_list.push_back(item.to_json_object());
    }
    
}



std::string get_current_time_str() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    return ctime(&now_c);
}