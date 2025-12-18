#ifndef STRING_ACTIONS_H
#define STRING_ACTIONS_H
#include <cstddef>


namespace alekseev {
  char * exc_scd(const char * first, const char * second, char * result, size_t * res_len);
  char * lat_rmv(const char * original, char * result, size_t * res_len);
}

#endif
