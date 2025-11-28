#include <iostream>
#include <cstring>
#include <cstdlib>
#include "transform.h"

namespace ahrameev {

    int count_diff_latin_letters(const char* str) {
        if (str == 0) return 0;
        int seen[26] = { 0 };
        for (int i = 0; str[i] != '\0'; ++i) {
            char c = str[i];
            if (c >= 'A' && c <= 'Z') seen[c - 'A'] = 1;
            else if (c >= 'a' && c <= 'z') seen[c - 'a'] = 1;
        }
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (seen[i]) count++;
        }
        return count;
    }

}

int main() {
    const char* test = "AB";
    std::cout << ahrameev::count_diff_latin_letters(test) << "\n"
    return 0;
}
