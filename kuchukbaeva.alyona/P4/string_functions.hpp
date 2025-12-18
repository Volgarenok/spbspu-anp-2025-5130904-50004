#ifndef STRING_FUNCTIONS_HPP
#define STRING_FUNCTIONS_HPP
#include <iostream>
#include <cstddef>

namespace kuchukbaeva
{
  char* reSize(char* buffer, size_t& capacity);
  int isVowel(char c) noexcept;
  char* rmvVow(const char* src, char* dest) noexcept;
  int repDgt(const char* str) noexcept;
  char* readStr(std::istream& input, size_t& read_size);
}

#endif

