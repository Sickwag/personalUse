#include <string>
#include <iostream>
#include <fstream>
#include <vector>


int main(){
    std::string path = "E:\\temp.txt ";
    std::ifstream f(path);
    std::string line;
    std::vector<std::string> after_change;
    while(std::getline(f,line)){
        after_change.emplace_back("## " + line);
    }
    std::ofstream out_file(path);
    for(const auto& line : after_change){
        out_file << line << "\n";
    }
    f.close();
    out_file.close();
    return 0;
}