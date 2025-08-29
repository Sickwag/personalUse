#include <format>
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <string_view>
#include <windows.h>

namespace fs = std::filesystem;

class ImageTools {
   private:
    std::map<std::string, std::size_t> image_list_;             // filename and size
    std::map<std::string, std::uintmax_t> classified_summary_;  // type and total_size
    std::string human_readable(uintmax_t bytes, int precision = 2,  bool use_si = true) {
        const uintmax_t base = use_si ? 1000u : 1024u;
        std::vector<std::string> suffixes;
        use_si ? suffixes = {"B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"} : suffixes = {"B", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB"};
        if(bytes < base)
            return std::to_string(bytes) + " " + suffixes[0];
        uintmax_t i = 0;
        long double value = static_cast<long double>(bytes);
        while(value>=base && suffixes.size() - 1){
            value /= base;
            i++;
        }
        return std::format("{:.{}f} {}", value, precision, suffixes[i]);
    }

   public:
    void classify_imgs(std::string_view target_folder) {
        if (fs::is_regular_file(target_folder)) {
            std::cout << "you should make sure target is a folder.\n";
            return;
        }
        for (const auto& entry : fs::recursive_directory_iterator(target_folder)) {
            auto ext = entry.path().extension().string();
            std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
            if (ext == ".jpg" || ext == ".jpeg" || ext == ".png" || ext == ".heic") {
                std::string filename = entry.path().filename().string();
                image_list_[filename] = entry.file_size();
                classified_summary_[entry.path().extension().string()] += entry.file_size();
            }
        }
        std::cout << "classified done.\n";
        std::cout << std::string('-', 50) << std::endl;
        for(const auto& item : image_list_){
            std::cout << std::setfill(' ') << std::setw(45) << std::left << item.first << std::setfill(' ') << std::setw(15) << std::right << human_readable(item.second) << std::endl;
        }
    }
};

int main(){
    SetConsoleOutputCP(CP_UTF8);
    std::string path = R"(E:\file_storage\常用图片)";
    ImageTools().classify_imgs(path);
    return 0;
}