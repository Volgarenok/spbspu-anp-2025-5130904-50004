#ifndef FUNCTIONS_FOR_STRINS_HPP
#define FUNCTIONS_FOR_STRINS_HPP
#include <iostream>

namespace ivantsova
{
  char * readLine(std::istream & in, size_t & size);
  const char * interleaveStrings(const char * str1, const char * str2, char * result);
  const char * addDigits(const char * str1, const char * str2, char * result, size_t * result_size);
}

#endif
