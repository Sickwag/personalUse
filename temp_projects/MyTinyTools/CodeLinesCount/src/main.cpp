#include "config.h"
#include "arg_parse.h"
#include "count.h"
#include "output.h"

int main(int argc, char** argv){
    try{
        ParsedArgs args = arg_parse(argc, argv);
        Config cfgs = read_config(args.config_file_path);
        Counter counter(cfgs, args);
        counter.start();
        Outputer out(cfgs,counter.get_count_result(),args);
        out.start();
    }catch(const std::exception& e){
        std::cerr << "exception found: " << e.what() << std::endl;
        return 1;
    }catch (...){
        std::cerr << "unknow error occurs.";
    }
}