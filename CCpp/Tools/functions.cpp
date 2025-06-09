#include "../algorithm/dataStruct.cpp" // ← 修改成 .h
#include <queue>
#include <string_view>
#include <ranges>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <bitset>
#include <filesystem>
#include <vector>
#include <regex>
#include <iomanip>
#ifndef byte
#define byte unsigned char  // 定义 byte 为 unsigned char
#endif
// #include <windows.h>
// #include "ClipboardTools.h"
using namespace std;
namespace fs = filesystem;

class OtherTools {
public:
    /**
     * @brief Get all primes between \p a and \p b using Euler's sieve.
     * @param a The lower bound (inclusive).
     * @param b The upper bound (inclusive).
     * @return A vector of primes in the range [a, b].
     */
    template<typename T>
    vector<T> euler(T& a, T& b) {
        static_assert(is_integral<T>::value, "T must be an integral type, (unsigned)int long or long long.");

        vector<T> primes;
        if (b < 2) return primes;
        if (a < 2) a = 2;

        vector<bool> isPrime(b + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i <= b; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && primes[j] * i <= b; j++) {
                isPrime[primes[j] * i] = false;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }

        vector<T> result;
        for (T i = a; i <= b; i++) {
            if (isPrime[i]) {
                result.push_back(i);
            }
        }

        return result;
    }

    string str_repeat(string need_repeat, int re_times) {
        string output;
        for (int i = 0;i < re_times;i++) {
            output += need_repeat;
        }
        return output;
    }
    void check_constants() {
        cout << "INT_MAX : " << INT_MAX << "\n";
        cout << "INT_MIN : " << INT_MIN << "\n";
        cout << __cplusplus;
    }
    vector<int> get_32binary_count(vector<int>& nums, size_t size = 32) {
        vector<int> counts(size, 0);
        for (int i = 0;i < nums.size();i++) {
            string binary = bitset<32>(nums[i]).to_string();
            for (int j = 31;j >= 0;j--) {
                counts[j] += (binary[j] - '0');
            }
        }
        return counts;
    }
};
class ClipboardTools {
private:
    OtherTools ot;
    bool copyToClipboard = false;
    vector<string> nameList;
    void insert_to_clipboard(string input, string line = "") {
        // if (input == "") {
        //     while (getline(cin, line)) {
        //         input += line + "\r\n";
        //     }
        // }
        // OpenClipboard(NULL);
        // EmptyClipboard();
        // size_t inputStringSize = input.size() + 1;
        // HGLOBAL hglob = GlobalAlloc(GMEM_MOVEABLE, inputStringSize);
        // char* pData = (char*)GlobalLock(hglob);
        // memcpy(pData, input.c_str(), inputStringSize);
        // SetClipboardData(CF_TEXT, hglob);
        // CloseClipboard();
        // cout << input;
        // cout << "\n\nCopied to your clipboard";
    }

    string replace_all(string input,const string from,const string to) {
        size_t pos = 0;
        if (from.empty()) return input;  // 防止死循环
        while ((pos = input.find(from, pos)) != string::npos) {
            input.replace(pos, from.length(), to);
            pos += to.length();
        }
        return input;
    }

    int parseLayer(string& nested, int initLayer = 0) {
        for (char& c : nested) {
            if (c == '[') initLayer++;
            else break;
        }
        return initLayer;
    }

    /**
     * @brief get a name-value test code which can copy immediately
     */
    string formatSnippets(string& name, string& value, string container = "vector", string eleType = "int") {
        string output;
        int layer = parseLayer(value);
        if (layer == 0 && value[0] == '"') // a string
            return "string " + name + " = " + value + ";";
        else if (layer == 0 && isdigit(value[0])) // not a string or a container
            return eleType + " " + name + " = " + value + ";";
        else {
            for (int i = 0; i < value.size(); i++) {
                if (value[i] == '[') value[i] = '{';
                if (value[i] == ']') value[i] = '}';
            }
            output = ot.str_repeat(container + "<", layer) + eleType + ot.str_repeat(">",layer) + " ";
        }
        return output += name + " = " + value + ";";
    }

    /**
     * @brief parse raw text from terminal, and transfrom them to test code sippnets
     * @return vector contains all test snippets
     */
    vector<string> parseInput(string& rawInput) {
        // removeBlanks(rawInput);
        vector<string> result;
        stringstream ss(replace_all(rawInput, ", ", "#"));
        string chunk, name, value;
        while (getline(ss, chunk, '#')) {
            size_t pos = chunk.find('=');
            name = chunk.substr(0, pos - 1);
            nameList.emplace_back(name);
            value = chunk.substr(pos + 2);
            result.emplace_back(formatSnippets(name, value));
        }
        return result;
    }
public:
    ClipboardTools(bool is_copy_to_clipboard) {
        copyToClipboard = is_copy_to_clipboard;
        cout << (copyToClipboard ? "open " : "close ") << "copy to clipboard\n";
    }
    ~ClipboardTools() {
        nameList.clear();
    }

    void changeBrackets(const char from = '[', const char to = '{') {
        string input;
        cin >> input;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '[') input[i] = '{';
            if (input[i] == ']') input[i] = '}';
        }
        if (copyToClipboard) {
            insert_to_clipboard(input);
        }
    }
    void removeChar(string& input, char c) {
        input.erase(remove(input.begin(), input.end(), c), input.end());
    }

    void generateCode() {
        string input, output;
        getline(cin, input);
        output += "int main() {\n";
        for (auto x : parseInput(input)) {
            output += "\t" + x + "\n";
        }
        output += "\tcout << Solution().method(";
        for (auto& n : nameList) {
            output += n +", ";
        }
        nameList.clear();
        output.pop_back();
        output.pop_back();
        output += ");\n}";
        insert_to_clipboard(output);
        // cout << output;
    }
};

class FileTools {
private:
    enum comments_match {
        all, single_line, multi_line
    };
    inline string erase_suffix(string filename, const string& suffix = "") {
        if (!suffix.empty()) {
            if (filename.size() >= suffix.size() &&
                filename.compare(filename.size() - suffix.size(), suffix.size(), suffix) == 0) {
                filename.erase(filename.size() - suffix.size());
            }
        }

        size_t dot_pos = filename.find_last_of('.');
        if (dot_pos != string::npos) {
            filename = filename.substr(0, dot_pos);
        }

        return filename;
    }
    inline string erase_suffix(const fs::directory_entry& fde, const string& suffix = "") {
        return erase_suffix(fde.path().filename().string(), suffix);
    }

    /**
     * @brief delete folder suffix downloaded from github, commonly foldername isn't empty, so after process there no error
     */
    void erase_folder_suffix(const string& folder_path, string suffix ="") {
        try {
            for (const auto& entry : fs::directory_iterator(folder_path)) {
                if (fs::is_directory(entry)) {
                    string folder_name = entry.path().filename().string();
                    filesystem::path new_path;

                    if (folder_name.ends_with(suffix)) {
                        new_path = entry.path().parent_path() / folder_name.substr(0, folder_name.size() - suffix.size());
                    }
                    if (!new_path.empty()) {
                        fs::rename(entry.path(), new_path);
                        cout << "Renamed " << entry.path() << " to " << new_path << endl;
                    }
                }
            }
        } catch (const fs::filesystem_error& e) {
            cerr << "Filesystem error: " << e.what() << endl;
        } catch (const exception& e) {
            cerr << "Unexpected error: " << e.what() << endl;
        }
    }
    /**
     * @brief open a folder and generate a md file contains filename as 2 level title and content to the text body
     * @param folderPath the files in this directory you want extract content;
     * @param outputFilePath the md file output path
     * @return
     */
    void extract_content_to_md(const string& folderPath, const string& outputFilePath) {
        ofstream outputFile(outputFilePath);
        if (!outputFile.is_open()) {
            cerr << "Failed to open output file: " << outputFilePath << endl;
            return;
        }
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            if (entry.is_regular_file()) {
                string fileName = erase_suffix(entry);
                fileName.pop_back();
                ifstream inputFile(entry.path());

                if (inputFile.is_open()) {
                    outputFile << "## " << fileName << "\n";
                    string line;
                    while (getline(inputFile, line)) {
                        outputFile << line << "\n";
                    }
                    outputFile << "\n";
                    inputFile.close();
                } else {
                    cerr << "Failed to open file: " << fileName << endl;
                }
            }
        }
        outputFile.close();
        cout << "Done, output file generated in : " << outputFilePath << endl;
    }
    /**
     * @brief operate a plaint text file
     * read all line in file, and you can choose modules to satisfy your need.
     * @param processing_module the module you wanna
     *
     * 1 -> remove all comments in cpp file,default remove all
     *
     * 2 -> adjust the title layer in md inputFile,the param addOrSub == true add a '#' in titles, false reverse.
     *
     * 3 -> remove all blank content (tabs wraps and space line) in inputFile
     *
     * @param addOrSub you wanna add a '#' in title or sub one
     * @param match_module choose match method to remove comments_match
     * (all / single_line / multi_line)
     * @return all modules include this function return void, In-Place Modification
     */
    void plaint_process(int processing_module = -1, bool addOrSub = true, comments_match match_module = all) {
        string inputPath, outputPath, line;
        inputPath = "D:\\Code Files\\vscode\\Drafts\\inputFile.md";
        outputPath = "D:\\Code Files\\vscode\\Drafts\\outputFile.md";
        ifstream inputFile(inputPath, ios::in);
        ofstream outputFile(outputPath, ios::out | ios::trunc);
        switch (processing_module) {
        case 1: {
            cout << "remove all comments in cpp file \n";
            regex commentsRegex(R"(\/\*[\s\S]*\*\/|\/\/.*)");
            while (getline(inputFile, line)) {
                string after_replace = regex_replace(line, commentsRegex, "");
                if (after_replace.empty()) {
                    continue;
                }
                else {
                    outputFile << after_replace << endl;
                }
            }
            break;
        }
        case 2: {
            cout << addOrSub ? "add" : "sub";
            cout << "title layer \n";
            regex titleRegex("^(#+)( .+)$");
            while (getline(inputFile, line)) {
                smatch match;
                if (regex_match(line, match, titleRegex)) {
                    string hashes = match[1].str();
                    string content = match[2].str();
                    if (hashes.length() > 1) {
                        if (addOrSub == true) {
                            hashes.append("#");
                        }
                        else {
                            hashes.pop_back();
                        }
                    }
                    outputFile << hashes << content << endl;
                }
                else {
                    outputFile << line << endl;
                }
            }
        }
        case 3: {
            cout << "remove all blank lines \n";
            while (getline(inputFile, line)) {
                bool is_blank = all_of(line.begin(), line.end(), [](unsigned char c) {
                    return isspace(c);
                    });
                if (!is_blank) {
                    outputFile << line << "\n";
                }
            }
        }
        default:
            break;
        }
        inputFile.close();
        outputFile.close();
        cout << "Done";
    }
public:
    void plaint_file_operator() {
        plaint_process();
    }

    void directory_extract() {
        string directory_to_extract, md_output_path;
        cin >> directory_to_extract;
        cin >> md_output_path;
        extract_content_to_md(directory_to_extract, md_output_path);
    }

    void delete_github_suffix() {
        erase_folder_suffix("D:\\test_folder");
    }

};


int main() {
    ClipboardTools ct(true);
    // ct.changeBrackets();
    ct.generateCode();
    
}