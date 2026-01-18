#include "transform.h"
#include <cctype>

namespace ahrameev
{

  const int LATIN_LETTERS_COUNT = 26;

  int count_diff_latin_letters(const char* str) {
    if (str == 0) return 0;

    int seen[LATIN_LETTERS_COUNT] = { 0 };

    for (int i = 0; str[i] != '\0'; ++i) {
      unsigned char c = static_cast<unsigned char>(str[i]);
      if (std::isalpha(c)) {
        c = std::tolower(c);
        seen[c - 'a'] = 1;
      }
    }

    int count = 0;
    for (int i = 0; i < LATIN_LETTERS_COUNT; ++i) {
      count += seen[i];
    }

    return count;
  }

  char* to_lower_latin(char* dest, size_t dest_size, const char* src) {
    if (dest == 0 || src == 0) return 0;

    size_t i = 0;
    while (src[i] != '\0') {
      if (i + 1 >= dest_size) return 0;
      dest[i] = std::tolower(static_cast<unsigned char>(src[i]));
      ++i;
    }

    dest[i] = '\0';
    return dest;
  }

}
