#include "filter.h"
#include <algorithm>
#include <functional>
#include <ranges>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

// Default constructor
// filter.cpp
Filter::Filter() : file_type_({{"data", {"json", "csv", "log"}},
                               {"doc", {"md", "txt", "README"}},
                               {"config", {"ini", "cfg"}}}),
                   suffix_({}),
                   language_({
                       {"c", {"c", "h", "util"}},
                       {"cpp", {"cpp", "h", "util", "hpp"}},
                       {"c++", {"cpp", "hpp", "util"}},
                       {"java", {"java", "class"}},
                   }),
                   methods_({{"language", [this]() {
                                  for (const auto& input_lang : input_language_) {
                                      if (language_.contains(input_lang)) {
                                          suffix_.insert(language_[input_lang].begin(), language_[input_lang].end());
                                      }
                                  }
                              }},
                             {"file_type", [this]() {
                                  for (const auto& ft : input_file_type_) {
                                      if (file_type_.contains(ft)) {
                                          suffix_.insert(file_type_[ft].begin(), file_type_[ft].end());
                                      }
                                  }
                              }}}) {}

Filter::~Filter() {
    input_file_type_.clear();
    input_language_.clear();
    suffix_.clear();
    language_.clear();
    file_type_.clear();
    methods_.clear();
}
bool Filter::empty() const noexcept {
    return input_file_type_.empty() && input_language_.empty();
}

bool Filter::render(const std::string& filepath_str) {
    fs::path path(filepath_str);
    if (suffix_.empty()) {
        for (auto& [name, method] : methods_) {
            method();
        }
    }
    std::string ext = path.extension().string();
    if (!ext.empty()) {
        ext = ext.substr(1);
    } else {
        ext = path.filename().string();
    }
    return suffix_.contains(ext);
}

bool Filter::render(const fs::directory_entry& entry) {
    return render(entry.path().string());
}

bool Filter::render(const fs::path& path) {
    return render(path.string());
}
