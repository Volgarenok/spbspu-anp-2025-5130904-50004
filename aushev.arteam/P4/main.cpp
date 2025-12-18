#include "string_utils.hpp"
#include <cstdio>
#include <new>

int main() {
    int ch;
    size_t len = 0;
    size_t cap = 64;
    char* buf = new (std::nothrow) char[cap];
    if (!buf) {
        std::fputs("Allocation error\n", stderr);
        return 1;
    }

    while ((ch = std::getchar()) != EOF && ch != '\n') {
        if (len + 1 >= cap) {
            cap *= 2;
            char* tmp = new (std::nothrow) char[cap];
            if (!tmp) {
                delete[] buf;
                std::fputs("Allocation error\n", stderr);
                return 1;
            }
            for (size_t i = 0; i <= len; ++i) tmp[i] = buf[i];
            delete[] buf;
            buf = tmp;
        }
        buf[len++] = static_cast<char>(ch);
    }
    buf[len] = '\0';

    const char* second = "abc_ef";
    int result = aushev::has_sam(buf, second);
    std::printf("%d\n", result);

    char* clean = new (std::nothrow) char[len + 1];
    if (!clean) {
        delete[] buf;
        std::fputs("Allocation error\n", stderr);
        return 1;
    }
    aushev::spc_rmv(clean, buf);
    std::puts(clean);

    delete[] buf;
    delete[] clean;
    return 0;
}

