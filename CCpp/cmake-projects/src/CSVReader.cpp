#include<variant>
#include "CSVReader.h"
#include <stdexcept>
#include<ranges>

CSVTools::CSVTools(const std::string& filename, char delimiter) : filename_(filename), delimiter_(delimiter), is_loaded(false) {
    file_.open(filename_);
    if (!file_.is_open()) {
        throw std::runtime_error("cannot open this file: " + filename_);
    }
    else {
        std::string header;
        if (std::getline(file_, header)) {
            header_ = parseLine(header);
            for (int i = 0; i < header_.size(); i++) {
                column_map_[header_[i]] = i;
            }
            num_columns_ = header_.size();
            readAll();
        }
        else {
            throw std::runtime_error("\"" + filename_ + "\" is empty.");
        }
    }
}

CSVTools::~CSVTools() {
    std::lock_guard<std::mutex> lock(mtx_);
    this->file_.close();
    data_.clear();
    header_.clear();
    column_map_.clear();
}

std::vector<std::vector<std::string>> CSVTools::readAll() {
    std::string line;
    while (std::getline(file_, line)) {
        auto row = parseLine(line);
        if (!row.empty()) {
            data_.push_back(row);
        }
    }
    file_.clear();
    file_.seekg(std::ios::beg);

    return data_;
}

bool CSVTools::getRow(std::vector<std::string>& row) {
    std::lock_guard<std::mutex> lock(mtx_);
    std::string line;
    if (std::getline(file_, line)) {
        row = parseLine(line);
        return true;
    }
    return false;
}

const std::vector<std::string> CSVTools::getHeader() const {
    return header_;
}

const std::vector<std::string> CSVTools::getColumn(const std::string col_name) const {
    auto target_col_index = getColumnIndex(col_name);
    if (target_col_index) {
        return data_ | std::views::transform([target_col_index](const auto& row) { return row.at(target_col_index); }) | std::ranges::to<std::vector>();
    }
}

size_t CSVTools::getNumColumns() const {
    return num_columns_;
}

std::string CSVTools::getCell(size_t row, size_t col) const {
    std::lock_guard<std::mutex> lock(mtx_);
    if (row >= data_.size() || col >= data_[row].size()) {
        throw std::out_of_range("Row or column index out of range");
    }
    return data_[row][col];
}

std::string CSVTools::getCell(size_t row, const std::string& column_name) const {
    auto index = column_map_.find(column_name);
    if (index == column_map_.end()) {
        throw std::invalid_argument(column_name + " not found.");
    }
    return getCell(row, index->second);
}

bool CSVTools::hasHeader() const {
    return !header_.empty();
}

size_t CSVTools::getColumnIndex(const std::string& col_name) const {
    auto target = column_map_.find(col_name);
    if (target == column_map_.end()) {
        throw std::invalid_argument(col_name + "not found");
    }
    else {
        return target->second;
    }
    return target->second;
}

void CSVTools::changeCell(size_t row, size_t col, const std::string& content) {
    if (row >= data_.size() || col >= data_[row].size()) {
        throw std::out_of_range("Invalid row or column index");
    }
    data_[row][col] = content;
}


std::vector<std::string> CSVTools::parseLine(const std::string& line) {
    std::lock_guard<std::mutex> lock(mtx_);
    std::vector<std::string> result;
    std::istringstream ss(line);
    std::string cell;

    while (std::getline(ss, cell, delimiter_)) {
        result.push_back(cell);
    }

    // 处理最后一个字段是空的情况，例如 "a,b,c,"
    if (line.size() > 0 && line.back() == delimiter_) {
        result.push_back("");
    }

    return result;
}