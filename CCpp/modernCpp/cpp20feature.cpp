#include<ranges>
#include <vector>
#include <iostream>
#include <concepts>

const auto use_vector(){
    std::vector<int> vec{1, 2, 3, 4};
    return vec;
}

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <typename T>
requires Numeric<T>
T arg42(const T & arg) {
    return arg + 42;
}

int main(){
    // int x{-3};
    // unsigned y{7};
    // // std::cout << static_cast<unsigned>(x) << std::endl;
    // if(x < y)
    //     std::cout << true;
    // else
    //     std::cout << false;

    std::vector<int> vec{1, 2, 3, 4, 5};
    auto res = vec | std::views::take(3);
    auto res2 = vec | std::views::filter([](int x) { return x > 2; });
    
}