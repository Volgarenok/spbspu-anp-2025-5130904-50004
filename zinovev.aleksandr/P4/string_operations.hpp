#ifndef STRING_OPERATIONS_HPP
#define STRING_OPERATIONS_HPP

#include <iostream>

namespace zinovev
{
  char* SetLine(std::istream & in, size_t& size, size_t& number_of_letters);
  void CutLetters(char* arr, char* ptr, size_t& size, size_t& size_ptr);
  void GetLine(std::ostream & out, char* array, const size_t size);
  int GetRepetitions(const char* arr, const size_t size);
}

#endif
