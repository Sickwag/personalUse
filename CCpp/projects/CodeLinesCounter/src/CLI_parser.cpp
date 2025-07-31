#include "CLI_parser.h"
#include <CLI11/CLI11.hpp>
#include <vector>
#include "counter.h"
#include "filter.h"

CLI_parser::CLI_parser(int argc, char** argv, Filter& f) : argc(argc), argv(argv), filter(f) {
    app.description("CodeLines counter");
    app.add_option("-l, --language", input_language)
        ->description("the language of your project directory you wanna parse, use \",\" to separate.")
        ->required()
        ->take_all()
        ->ignore_case()
        ->check([this](const std::string& val) -> std::string {
            if (!filter.language_.contains(val)) {
                std::string allowed;
                for (const auto& [key, _] : filter.language_) {
                    if (!allowed.empty())
                        allowed += ", ";
                    allowed += key;
                }
                return "value " + val + " is invalid(allowed: " + allowed + ")";
            }
            return "";
        }, "is_allowed_language?");
    app.add_option("-f, --filepath", input_filepath)
        ->description("input the file or directory you wanna count.")
        ->required()
        ->take_all()
        ->check([](const std::string& val) -> std::string {
            if (!fs::exists(val))
                return std::string("your -f, --filepath is not exist.");
            return std::string();
        }, "is_exist_file_or_directory?");
    app.add_flag("--include-doc", include_doc, "decide count doc files or not(" + CLI::detail::join(filter.file_type_["data"], ", ") + ")")
        ->default_val(false)
        ->ignore_case();
    app.add_flag("--include-data", include_data, "count data files or not(" + CLI::detail::join(filter.file_type_["data"], ", ") + ")")
        ->default_val(false)
        ->ignore_case();
    app.add_flag("--include-config", include_config, "count config files or not(" + CLI::detail::join(filter.file_type_["config"], ", ") + ")")
        ->default_val(false)
        ->ignore_case();
    app.add_flag("--short-path", short_path, "show sorter path str in path column whether or not.")
        ->default_val(true)
        ->ignore_case();
}

int CLI_parser::start() {
    CLI11_PARSE(app, argc, argv);
    filter.input_language_ = input_language;
    if(include_doc){
        for(const auto& type : filter.file_type_["doc"]){
            filter.input_file_type_.emplace_back(type);
        }
    }
    if(include_data){
        for(const auto& type : filter.file_type_["data"]){
            filter.input_file_type_.emplace_back(type);
        }
    }
    if(include_config){
        for(const auto& type : filter.file_type_["config"]){
            filter.input_file_type_.emplace_back(type);
        }
    }
    for(const auto& path : input_filepath){
        Counter counter(path, filter);
        display(counter.get_result(path));
    }
    return 1;
}

void CLI_parser::display(const std::pair<fs::path, std::vector<FileInfo>>& result) const {
    const auto& [dir_name, res] = result;
    std::cout << std::left << fs::path(dir_name).generic_string() << '\n';
    
    const int name_width = 20;
    const int path_width = 80; // 增加路径列宽
    const int num_width = 10;
    
    std::cout << std::setw(name_width) << std::left << "name" 
              << std::setw(path_width) << std::left << "path" 
              << std::setw(num_width) << std::left << "words" 
              << std::setw(num_width) << std::left << "lines" << std::endl;
    
    std::string separate_line(name_width + path_width + num_width * 2, '-');
    std::cout << separate_line << std::endl;
    
    size_t words_sum = 0, lines_sum = 0;
    for(const auto& item : res){
        std::cout << std::setw(name_width) << std::left << item.file_name_ 
                  << std::setw(path_width) << std::left << (short_path ? "."+item.file_path_.substr(dir_name.string().length()) : item.file_path_)
                  << std::setw(num_width) << std::left << item.words_ 
                  << std::setw(num_width) << std::left << item.lines_ << std::endl;
        words_sum += item.words_;
        lines_sum += item.lines_;
    }
    
    std::cout << std::setw(name_width) << std::left << "sum: " 
              << std::setw(path_width) << std::left << " " 
              << std::setw(num_width) << std::left << words_sum 
              << std::setw(num_width) << std::left << lines_sum << std::endl;
}
