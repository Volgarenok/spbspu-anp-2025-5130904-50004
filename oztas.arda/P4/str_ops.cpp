#include "str_ops.hpp"
#include <cctype>

namespace {

  void markLatinLetters(
    const char* s,
    unsigned char present[26]
  ) noexcept
  {
    size_t i = 0;
    while (s[i] != '\0') {
      const unsigned char c = static_cast<unsigned char>(s[i]);
      if (std::isalpha(c) != 0) {
        const int lc = std::tolower(c);
        if (lc >= 'a' && lc <= 'z') {
          present[static_cast<size_t>(lc - 'a')] = 1;
        }
      }
      ++i;
    }
  }

}

size_t oztas::cstrLen(const char* s) noexcept
{
  size_t n = 0;
  if (s == nullptr) {
    return 0;
  }
  while (s[n] != '\0') {
    ++n;
  }
  return n;
}

size_t oztas::replaceSymbol(
  const char* src,
  int fromCh,
  int toCh,
  char* dst,
  size_t dstSize
) noexcept
{
  const size_t n = oztas::cstrLen(src);
  if ((dst == nullptr) || (dstSize < (n + 1))) {
    return n;
  }

  const char from = static_cast<char>(fromCh);
  const char to = static_cast<char>(toCh);

  for (size_t i = 0; i < n; ++i) {
    const char c = src[i];
    if (c == from) {
      dst[i] = to;
    }
    else {
      dst[i] = c;
    }
  }
  dst[n] = '\0';
  return n;
}

size_t oztas::latinTwo(
  const char* s1,
  const char* s2,
  char* dst,
  size_t dstSize
) noexcept
{
  unsigned char present[26] = { 0 };

  if (s1 != nullptr) {
    markLatinLetters(s1, present);
  }
  if (s2 != nullptr) {
    markLatinLetters(s2, present);
  }

  size_t need = 0;
  for (size_t i = 0; i < 26; ++i) {
    if (present[i] != 0) {
      ++need;
    }
  }

  if ((dst == nullptr) || (dstSize < (need + 1))) {
    return need;
  }

  size_t pos = 0;
  for (size_t i = 0; i < 26; ++i) {
    if (present[i] != 0) {
      dst[pos] = static_cast<char>('a' + static_cast<char>(i));
      ++pos;
    }
  }
  dst[pos] = '\0';
  return need;
}
