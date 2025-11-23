#include "string_utils.hpp"
#include <cstddef>

namespace aushev {

int has_sam(const char* s1, const char* s2) {
    if (!s1 || !s2) return 0;
    const char* p1 = s1;
    while (*p1) {
        const char* p2 = s2;
        while (*p2) {
            if (*p1 == *p2) return 1;
            ++p2;
        }
        ++p1;
    }
    return 0;
}

}