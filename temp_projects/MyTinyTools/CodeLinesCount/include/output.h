#pragma once
#include "config.h"
#include "count.h"

class Ouputer {
    Config& cfg_;
    std::vector<CodeStats>& count_result_;

   public:
    Ouputer(Config& cfg, std::vector<CodeStats>& count_result);
    void json();
    void csv();
    void terminal();
};