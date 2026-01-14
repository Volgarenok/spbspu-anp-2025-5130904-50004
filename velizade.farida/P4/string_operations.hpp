#ifndef STRING_OPERATIONS_HPP
#define STRING_OPERATIONS_HPP
#include <iostream>
#include <iomanip>

namespace velizade
{
  char* read_string(std::istream& input, size_t& length);
  char* rep_sym(const char* str);
  char* uni_two(const char* str1, const char* str2);
}

#endif
