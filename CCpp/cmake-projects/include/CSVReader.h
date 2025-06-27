#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <mutex>
#include <unordered_map>
#include <optional>
#include <sstream>
#include <stdexcept>

class CSVTools {
public:
    explicit CSVTools(const std::string& filename, char delimiter = ',');
    ~CSVTools();
    std::vector<std::vector<std::string>> readAll();
    bool getRow(std::vector<std::string>& row);
    const std::vector<std::string> getHeader() const;

    const std::vector<std::string> getColumn(const std::string col_name) const;
    size_t getNumColumns() const;
    std::string getCell(size_t row, size_t col) const;
    std::string getCell(size_t row, const std::string& column_name) const;
    bool hasHeader() const;
    size_t getColumnIndex(const std::string& col_name) const;
    void changeCell(size_t row, size_t col, const std::string& content);

private:
    std::string filename_;
    std::ifstream file_;
    std::vector<std::vector<std::string>> data_;
    std::vector<std::string> header_;
    std::unordered_map<std::string, size_t> column_map_;
    size_t num_columns_;
    mutable std::mutex mtx_;
    char delimiter_;
    bool is_loaded;

    // 解析一行 CSV
    std::vector<std::string> parseLine(const std::string& line);
};