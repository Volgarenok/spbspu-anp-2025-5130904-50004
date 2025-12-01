#ifndef STRING_FUNCTIONS_HPP
#define STRING_FUNCTIONS_HPP
#include <iostream>
#include <cstddef>

namespace kuchukbaeva
{
  size_t strLen(const char* str);
  int isVowel(char c);
  char* rmvVow(const char* src, char* dest) noexcept;
  int repDgt(const char* str) noexcept;
  char* readStr(std::istream& input, size_t& read_size);
}

#endif

