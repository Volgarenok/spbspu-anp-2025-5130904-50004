#include "string_actions.h"
#include <cstddef>
#include <cctype>


char * alekseev::exc_scd(const char * first, const char * second, char * result, size_t * res_len)
{
  size_t length_result = 0;
  for (size_t i = 0; first[i]; ++i) {
    bool is_in_second = false;
    for (size_t j = 0; second[j]; ++j) {
      if (first[i] == second[j]) {
        is_in_second = true;
      }
    }
    if (!is_in_second) {
      result[length_result++] = first[i];
    }
  }
  result[length_result] = '\0';
  *res_len = length_result;
  return result;
}


char * alekseev::lat_rmv(const char * original, char * result, size_t * res_len)
{
  size_t result_length = 0;
  for (size_t i = 0; original[i]; ++i) {
    if (!isalpha(original[i])) {
      result[result_length++] = original[i];
    }
  }
  result[result_length] = '\0';
  *res_len = result_length;
  return result;
}
