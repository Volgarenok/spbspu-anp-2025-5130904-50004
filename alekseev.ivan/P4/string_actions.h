#ifndef STRING_ACTIONS_H
#define STRING_ACTIONS_H
#include <cstddef>

namespace alekseev {
  size_t exc_scd(const char * first, const size_t length1,
    const char * second, const size_t length2, char * result);
  size_t lat_rmv(char * original, size_t length, char * result);
}

#endif