#pragma once
#include <filesystem>
#include <filesystem>
#include <functional>
#include <string>
#include <utility>
#include <vector>
#include "filter.h"

namespace fs = std::filesystem;

struct FileInfo {
    std::string file_path_;
    std::string file_name_;
    size_t words_;
    size_t lines_;
};

class Counter {
   private:
    Filter& filter_;
    fs::path target_directory_;                 // single folder or file
    std::vector<FileInfo> filepath_lists_;      // single folder of file
    bool yes_or_no() const noexcept;
    size_t words_count(const fs::path& file_path);
    size_t lines_count(const fs::path& file_path);

   public:
    Counter(const std::string& target_directory, Filter& filter);
    ~Counter();
    std::pair<fs::path, std::vector<FileInfo>> get_result(const fs::path& file_path);
};

