#ifndef KHAIRULLIN_HPP
#define KHAIRULLIN_HPP
#include <iostream>
#include <cstddef>
namespace khairullin
{
  char * getline(std::istream & input, char * data, size_t & size);
  char * unique_str(char * str1, const char * str2, size_t size1, size_t size2, char * str_unique);
  char * delete_vowels(char * str, size_t size, char * str_without_vowels);
}
#endif
