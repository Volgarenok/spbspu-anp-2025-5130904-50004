#include <iostream>
#include <iomanip>
#include "khairullin.hpp"

namespace khairullin
{
  size_t getline(std::istream & input, char *& data, size_t & size)
  {
    bool is_skipws = input.flags() & std::ios_base::skipws;
    if (is_skipws)
    {
      input >> std::noskipws;
    }
    try
    {
      size_t i = 0;
      char symbol = 0;
      while (input >> symbol && symbol != '\n')
      {
        if (i >= size - 1)
        {
          char * temp = new char [size + 10];
          for (size_t j = 0; j < i; ++j)
          {
            temp[j] = data[j];
          }
          delete [] data;
          data = temp;
          size += 10;
        }
        data[i] = symbol;
        ++i;
        input >> symbol;
      }
      data[i] = '\0';
      if (is_skipws)
      {
        input >> std::skipws;
      }
      return i;
    }
    catch (...)
    {
      throw;
    }
  }
}
