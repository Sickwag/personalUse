#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;
void cpp_remove_all_comments() {
    string inputPath = "D:\\Code Files\\vscode\\Drafts\\inputFile.md";
    string outputPath = "D:\\Code Files\\vscode\\Drafts\\outputFile.md";
    
    
    ifstream inputFile(inputPath, ios::in);
    ofstream outputFile(outputPath, ios::out);
    
    if (!inputFile.is_open()) {
        cerr << "无法打开输入文件: " << inputPath << endl;
        return;
    }
    
    if (!outputFile.is_open()) {
        cerr << "无法打开输出文件: " << outputPath << endl;
        return;
    }
    
    
    regex commentsRegex(R"(/\*[\s\S]*?\*/|
    
    string line;
    while (getline(inputFile, line)) {
        
        string result = regex_replace(line, commentsRegex, "");
        
        
        
        
        
        
        
        
        
        outputFile << result << endl;
    }
    
    
    inputFile.close();
    outputFile.close();
    
    cout << "注释已成功删除，结果已保存到 " << outputPath << endl;
}
int main() {
    cpp_remove_all_comments();
    return 0;
}
