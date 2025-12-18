#ifndef KHAIRULLIN_HPP
#define KHAIRULLIN_HPP
#include <iostream>
#include <cstddef>
namespace khairullin
{
  char * getline(std::istream & input, char * data);
  char * unique_str(const char * str1, const char * str2, char * str_unique);
  char * delete_vowels(const char * str, char * str_without_vowels);
}
#endif
