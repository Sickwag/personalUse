#include "config.h"
#include "arg_parse.h"
#include "count.h"
#include "output.h"

int main(int argc, char** argv){
    ParsedArgs args = arg_parse(argc, argv);
    Config cfgs = read_config(args.config_file_path);
    Counter counter(cfgs, args);
    counter.start();
    Outputer out(cfgs,counter.get_count_result(),args);
    out.start();
}