#include <iostream>
#include <InputValidator.h>

int main() {
    std::string name = InputValidator<std::string>()
        .prompt("input your name: ")
        .length_range(4, 15)
        .render();
    std::cout << name << std::endl;
}
