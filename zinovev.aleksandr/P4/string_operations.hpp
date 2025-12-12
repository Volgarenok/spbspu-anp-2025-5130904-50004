#ifndef STRING_OPERATIONS_HPP
#define STRING_OPERATIONS_HPP

#include <iostream>

namespace zinovev
{
  char* setLine(std::istream& in, size_t& size, size_t& number_of_letters);
  char* cutLetters(const char* arr, char* arr_ptr, size_t& size_ptr);
  int getRepetitions(const char* arr);
}

#endif
