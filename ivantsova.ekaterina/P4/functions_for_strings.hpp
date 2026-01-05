#ifndef FUNCTIONS_FOR_STRINS_HPP
#define FUNCTIONS_FOR_STRINS_HPP
#include <iostream>

namespace ivantsova
{
  char * readLine(std::istream & in, size_t & size);
  void interleaveStrings(const char * str1, const char * str2, size_t size1, char * result);
  void addDigits(const char * str1, const char * str2, size_t size1, char * result, size_t & result_size);
  void printString(std::ostream & out, const char * str);
}

#endif
