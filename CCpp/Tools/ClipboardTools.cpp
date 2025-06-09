// ClipboardTools.cpp

#include "ClipboardTools.h"
#include <windows.h>
#include <iostream>

namespace Clipboard {
    void insert_to_clipboard(std::string input, std::string line) {
        if (input == "") {
            while (getline(std::cin, line)) {
                input += line + "\r\n";
            }
        }
        OpenClipboard(NULL);
        EmptyClipboard();
        size_t inputStringSize = input.size() + 1;
        HGLOBAL hglob = GlobalAlloc(GMEM_MOVEABLE, inputStringSize);
        char* pData = (char*)GlobalLock(hglob);
        memcpy(pData, input.c_str(), inputStringSize);
        SetClipboardData(CF_TEXT, hglob);
        CloseClipboard();
        std::cout << input;
        std::cout << "\n\nCopied to your clipboard";
    }
}
