#pragma once
#include<CLI11/CLI11.hpp>
class CLIEntry{
    private:
     CLI::App app;
    public:
    CLIEntry(int argc, char** argv);
    
};