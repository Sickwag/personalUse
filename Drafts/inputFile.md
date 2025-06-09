#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

// 函数用于删除文件中的所有注释
void cpp_remove_all_comments() {
    string inputPath = "D:\\Code Files\\vscode\\Drafts\\inputFile.md";
    string outputPath = "D:\\Code Files\\vscode\\Drafts\\outputFile.md";
    
    // 打开输入文件和输出文件
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
    
    // 定义正则表达式，匹配多行注释和单行注释
    regex commentsRegex(R"(/\*[\s\S]*?\*/|//.*)");
    
    string line;
    while (getline(inputFile, line)) {
        // 使用 regex_replace 进行替换，将匹配的注释替换为空字符串
        string result = regex_replace(line, commentsRegex, "");
        
        // 如果需要保留空行，可以直接写入结果
        // 如果不希望保留空行，可以添加条件判断
        // 例如：
        // if (!result.empty()) {
        //     outputFile << result << endl;
        // }
        
        // 这里假设保留空行
        outputFile << result << endl;
    }
    
    // 关闭文件
    inputFile.close();
    outputFile.close();
    
    cout << "注释已成功删除，结果已保存到 " << outputPath << endl;
}

int main() {
    cpp_remove_all_comments();
    return 0;
}