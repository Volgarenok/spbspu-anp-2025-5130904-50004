#include <iostream>
#include <cstring>
#include <cstdlib>

namespace em {

void remove_latin(const char* src, char* dest) {
    if (src == nullptr || dest == nullptr) return;
    while (*src) {
        char c = *src;
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            *dest = c;
            dest++;
        }
        src++;
    }
    *dest = '\0';
}

int has_common_chars(const char* str1, const char* str2) {
    if (str1 == nullptr || str2 == nullptr) return 0;

    bool found[256] = {false};

    while (*str1) {
        found[static_cast<unsigned char>(*str1)] = true;
        str1++;
    }

    while (*str2) {
        if (found[static_cast<unsigned char>(*str2)]) {
            return 1;
        }
        str2++;
    }

    return 0;
}

}

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
