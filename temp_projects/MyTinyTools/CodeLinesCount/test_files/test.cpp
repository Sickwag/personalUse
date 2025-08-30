#include <iostream>
#include <vector>

// 这是一个单行注释
int main() {
    /*
     * 这是一个多行注释
     * 用来测试注释统计功能
     */
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 另一个单行注释
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << std::endl; // 行尾注释
    }

    return 0;
}

// 最后的注释
