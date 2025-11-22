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

}

int main() {
    char input[10000];
    std::cin.getline(input, sizeof(input));

    char* result_rmv = static_cast<char*>(malloc(strlen(input) + 1));
    em::remove_latin(input, result_rmv);
    std::cout << result_rmv << std::endl;
    free(result_rmv);

    return 0;
}
