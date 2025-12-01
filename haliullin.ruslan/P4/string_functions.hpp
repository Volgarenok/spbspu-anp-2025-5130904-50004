#ifndef STRING_FUNCTIONS_HPP
#define STRING_FUNCTIONS_HPP
#include <iostream>
namespace haliullin
{
  char *getline(std::istream &in, size_t &size);
  size_t DIF_LAT(const char *arr);
  char *RMV_VOW(char *new_arr, const char *arr);
  bool isVowel(const char c);
  size_t sizeWithoutVowels(const char *arr);
}
#endif
