#ifndef STRING_FUNCTIONS_HPP
#define STRING_FUNCTIONS_HPP
#include <iostream>
namespace haliullin
{
  char *getline(std::istream &in, size_t &size);
  size_t DIF_LAT(const char *arr, size_t str_size);
  char *RMV_VOW(char *new_arr, const char *arr, size_t str_size);
  bool isVowel(const char c);
  size_t sizeWithoutVowels(const char *arr, size_t str_size);
  void writeString(const char *arr, size_t str_size);
}
#endif
