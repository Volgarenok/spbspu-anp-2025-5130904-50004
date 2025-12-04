#ifndef STRING_ACTIONS_H
#define STRING_ACTIONS_H
#include <cstddef>

namespace alekseev {
  char * exc_scd(const char * first, size_t length1,
      const char * second, size_t length2, char * result, size_t & res_len);
  char * lat_rmv(const char * original, size_t length, char * result, size_t & res_len);
}

#endif
