#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <cstddef>
#include <iostream>

namespace dolenko
{
  size_t dif_lat(const char* arr);
  char* uni_two(char* dest, const char* str1, const char* str2);
  char* getline(std::istream& input, char* data);
}

#endif