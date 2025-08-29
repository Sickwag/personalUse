#include <string>
#include "utils.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
std::string get_exec_path() {
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    return std::string(path);
}
#elif defined(__linux__)
#include <limits.h>
#include <unistd.h>
std::string get_exec_path() {
    char path[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", path, PATH_MAX);
    if (count != -1) {
        path[count] = '\0';
        return std::string(path);
    } else {
        throw std::runtime_error("Error getting executable path");
    }
}
#else
#error "Unsupported platform"
#endif