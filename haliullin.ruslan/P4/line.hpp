#ifndef LINE_HPP
#define LINE_HPP
#include <iostream>
namespace haliullin
{
  char *getline(std::istream &in, char end, size_t &size);
  size_t DIF_LAT(const char *arr);
  char *RMV_VOW(char *new_arr, const char *arr);
  bool isVowel(const char c);
  size_t sizeWithoutVowels(const char *arr);
}
#endif
