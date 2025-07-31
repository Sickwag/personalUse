#pragma once
#include <filesystem>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace fs = std::filesystem;
using InputList = std::vector<std::string>;
class Filter {
   private:
   
   public:
   Filter();
   ~Filter();
   bool empty() const noexcept;
   InputList input_file_type_, input_language_;
   std::unordered_set<std::string> suffix_;
   std::unordered_map<std::string, std::vector<std::string>> file_type_, language_;
   std::unordered_map<std::string, std::function<void()>> methods_;
   // std::vector<std::function<bool(InputList&, const fs::path&)>> validators_;

   // Filter& suffix(InputList& suffixes);
   // Filter& language(InputList& languages);
   // Filter& file_type(InputList& file_types);

   // Filter& add_file_type(const std::string& file_type_name, InputList& file_types);
   // Filter& add_language(const std::string& language_name, InputList& languages);

   // 新增：判断文件是否满足所有过滤规则
   bool render(const std::string& path_str);
   bool render(const fs::directory_entry& entry);
   bool render(const fs::path& entry);
};
