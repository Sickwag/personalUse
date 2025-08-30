#pragma once
#include "arg_parse.h"
#include "config.h"
#include "count.h"

class Outputer {
   private:
    Config& cfg_;
    std::vector<CodeStats>& count_result_;
    ParsedArgs& args_;
    CodeStats sum_;

   public:
    Outputer(Config& cfg, std::vector<CodeStats>& count_result, ParsedArgs& args);
    void to_json();
    void to_csv();
    void to_terminal();
    void start();
};