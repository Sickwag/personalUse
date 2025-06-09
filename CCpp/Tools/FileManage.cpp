// 2025年2月24日23:54:49 大概花了2小时从零开始写
#include<algorithm>
#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<filesystem>
using namespace std;
namespace fs = std::filesystem;

class FileTools {
private:
    struct FileInfo {
        int size;
        int lines;
        int characters;
        string filename;
        string extension;
        string foldername;
        bool isFolder;
    };
    class sorter {
    private:
        enum sortMethods {
            name_asc, name_dsc,
            size_asc, size_dsc,
            extension_asc, extension_dsc
        };
    public:
        void changeSortMethodInterface() {
            cout << "input corresponding number to choose sort method :\n"
                << "1 -> name asc\n"
                << "2 -> name dsc\n"
                << "3 -> size asc\n"
                << "4 -> size dsc\n"
                << "5 -> extension asc\n"
                << "6 -> extension dsc\n";
            int selection;
            cin >> selection;
        }
        sortMethods sm = sortMethods::name_asc;
        vector<FileInfo> sorFileList(vector<FileInfo> unordered, sortMethods sm) {
            switch (sm) {
            case name_asc: {
                sm = sortMethods::name_asc;
                cout << "sort method changes to name asc.\n";
                sort(unordered.begin(), unordered.end(), [](const FileInfo& a, const FileInfo& b) {
                    return a.filename < b.filename;});
                break;
            }
            case name_dsc: {
                sm = sortMethods::name_dsc;
                cout << "sort method changes to name dsc.\n";
                sort(unordered.begin(), unordered.end(), [](const FileInfo& a, const FileInfo& b) {
                    return a.filename > b.filename;});
                break;
            }
            case size_asc: {
                sm = sortMethods::size_asc;
                cout << "sort method changes to size asc.\n";
                sort(unordered.begin(), unordered.end(), [](const FileInfo& a, const FileInfo& b) {
                    return a.size < b.size;});
                break;
            }
            case size_dsc: {
                sm = sortMethods::size_dsc;
                cout << "sort method changes to size dsc.\n";
                sort(unordered.begin(), unordered.end(), [](const FileInfo& a, const FileInfo& b) {
                    return a.size < b.size;});
                break;
            }
            case extension_asc: {
                sm = sortMethods::extension_asc;
                cout << "sort method changes to extension asc.\n";
                sort(unordered.begin(), unordered.end(), [](const FileInfo& a, const FileInfo& b) {
                    return a.extension < b.extension;});
                break;
            }
            case extension_dsc: {
                sm = sortMethods::extension_dsc;
                cout << "sort method changes to extension dsc.\n";
                sort(unordered.begin(), unordered.end(), [](const FileInfo& a, const FileInfo& b) {
                    return a.extension < b.extension;});
                break;
            }
            default:
                break;
            }
            return unordered;
        }
    };
    inline string getRidSuffixname(const string& filename) {
        size_t it = filename.find_last_of('.');
        return filename.substr(0, it);
    }
    vector<FileInfo> readFolder(const string& folderPath, bool needLinesAndChars) {
        vector<FileInfo> output;
        for (auto const& entry : fs::directory_iterator(folderPath)) {
            fs::path singleFile(entry);
            output.push_back(getFileInfo(singleFile, needLinesAndChars));
        }
        return output;
    }
    FileInfo getFileInfo(fs::path& filePath, bool needLinesAndChars) {
        FileInfo fi;
        if (!filePath.empty()) {
            if (fs::is_directory(filePath)) {
                fi.foldername = filePath.filename().string();
                fi.isFolder = true;
            }
            else {
                if (needLinesAndChars) {
                    fstream fs(filePath);
                    string line;
                    int lineCount = 0, charCount = 0;
                    while (getline(fs, line)) {
                        lineCount++;
                        charCount += line.size();
                    }
                    fi.lines = lineCount;
                    fi.characters = charCount;
                    fi.size = fs::file_size(filePath);
                    fi.filename = getRidSuffixname(filePath.filename().string());
                    fi.extension = filePath.extension().string();
                }
                fi.isFolder = false;
            }
            return fi;
        }
        else {
            cerr << "Warning: Invalid file.";
        }
        return fi;
    }
    sorter sortHelper;
    void showFileListInterface(vector<FileInfo> afterReadAndSort) {
        const int fileNameWidth = 20; // 文件名列宽度
        const int extensionWidth = 10; // 拓展名宽度
        const int lineCountWidth = 8; // 行数列宽度
        const int charCountWidth = 12; // 字符数列宽度
        const int sizeWidth = 12;        // 大小列宽度

        cout << left << setw(fileNameWidth) << "file name"
            << setw(extensionWidth) << "extension"
            << setw(lineCountWidth) << "lines"
            << setw(charCountWidth) << "characters"
            << setw(sizeWidth) << "size(bytes)" << '\n'
            << string(62, '-') << '\n';

        for (const auto& fi : afterReadAndSort) {
            // 对齐输出
            if (fi.isFolder) {
                cout << left << setw(fileNameWidth) << "$$ " + fi.foldername << '\n';
            }
            else {
                cout << left << setw(fileNameWidth) << fi.filename
                    << setw(extensionWidth) << fi.extension
                    << setw(lineCountWidth) << fi.lines
                    << setw(charCountWidth) << fi.characters
                    << setw(sizeWidth) << fi.size << '\n';
            }
        }
    }
public:
    void showInfo(const string& folderPath) {
        vector<FileInfo> afterReadAndSort = sortHelper.sorFileList(readFolder(folderPath, true), sortHelper.sm);
        showFileListInterface(afterReadAndSort);
    }
};

int main() {
    FileTools ft;
    // string path;
    // cin >> path;
    // ft.showInfo(path);
    ft.showInfo("D:\\Code Files\\vscode\\java\\primary_learn");
    system("pause");
}