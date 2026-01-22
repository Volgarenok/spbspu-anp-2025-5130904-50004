#include "string.hpp"

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
