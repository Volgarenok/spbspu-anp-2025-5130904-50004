#include "string_actions.h"
#include <cstddef>
#include <cctype>

size_t alekseev::exc_scd(const char * first, const size_t length1,
  const char * second, const size_t length2, char * result)
{
  size_t length_result = 0;
  for (size_t i = 0; i < length1; ++i) {
    bool is_in_second = false;
    for (size_t j = 0; j < length2; ++j) {
      if (first[i] == second[j]) {
        is_in_second = true;
      }
    }
    if (!is_in_second) {
      result[length_result++] = first[i];
    }
  }
  result[length_result] = '\0';
  return length_result;
}


size_t alekseev::lat_rmv(char * original, size_t length, char * result)
{
  size_t length_result = 0;
  for (size_t i = 0; i < length; ++i) {
    if (!isalpha(original[i])) {
      result[length_result++] = original[i];
    }
  }
  result[length_result] = '\0';
  return length_result;
}

