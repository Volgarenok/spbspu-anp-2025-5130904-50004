#ifndef STRING_OPERATIONS_HPP
#define STRING_OPERATIONS_HPP

#include <iostream>

namespace zinovev
{
  char* setLine(std::istream& in, size_t& size, size_t& number_of_letters);
  char* cutLetters(const char* arr, char* arr_ptr, size_t& size, size_t& size_ptr);
  void printLine(std::ostream& out, const char* array, size_t size);
  int getRepetitions(const char* arr, size_t size);
}

#endif
