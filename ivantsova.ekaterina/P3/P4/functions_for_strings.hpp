#ifndef FUNCTIONS_FOR_STRINS_HPP
#define FUNCTIONS_FOR_STRINS_HPP
#include <iostream>

namespace ivantsova
{
  char * readLine(std::istream & in, size_t & size);
  char * interleaveStrings(const char * str1, const char * str2, size_t size1, size_t & result_size);
  char * addDigits(const char * str1, const char * str2, size_t size1, size_t & result_size);
  void printString(std::ostream & out, const char * str, size_t size);
}

#endif
