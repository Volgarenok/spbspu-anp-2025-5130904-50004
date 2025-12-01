#include <iostream>
#include <cstring>
#include <cstdlib>
#include "string.hpp"

int main() {
    char input[10000];
    if (!std::cin.getline(input, sizeof(input))) {
        std::cerr << "Ошибка ввода\n";
        return 1;
    }

    char* result_rmv = static_cast<char*>(malloc(strlen(input) + 1));
    if (result_rmv == nullptr) {
        std::cerr << "Ошибка выделения памяти\n";
        return 1;
    }
    em::remove_latin(input, result_rmv);
    std::cout << result_rmv << std::endl;
    free(result_rmv);

    const char* second_str = "abs";
    int common = em::has_common_chars(input, second_str);
    std::cout << common << std::endl;

    return 0;
}
