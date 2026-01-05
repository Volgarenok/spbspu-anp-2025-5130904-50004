#ifndef STRING_OPERATIONS_HPP
#define STRING_OPERATIONS_HPP
#include <iostream>
#include <iopmanip>

namespace velizade
{
  char* read_string(std::istream& input, size_t size);
  int rep_sym(char* buffer, const char* str);
  int uni_two(char* buffer, const char* str1, const char* str2);
}

#endif
