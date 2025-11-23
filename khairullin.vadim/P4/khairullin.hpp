#ifndef KHAIRULLIN_HPP
#define KHAIRULLIN_HPP
#include <iostream>
#include <cstddef>
namespace khairullin
{
  size_t getline(std::istream & input, char *& data, size_t & size);
  void unique_str(char * str1, const char * str2, size_t size1, size_t size2);
  void delete_vowels(char * str, size_t size);
}
#endif
