#include <iostream>
#include <iomanip>
#include "khairullin.hpp"

namespace khairullin
{
  size_t getline(std::istream & input, char *& data, size_t size)
  {
    try
    {
      size_t i = 0;
      while (true)
      {
        char * temp = new char [size + 1];
        for (size_t j = 0; j < i; ++j)
        {
          temp[j] = data[j];
        }
        delete [] data;
        data = temp;
        size++;
        if (!(input >> data[i]) or data[i] == '\n')
        {
          data[i] = '\0';
          break;
        }
        ++i;
      }
      return i;
    }
    catch (...)
    {
      throw;
    }
  }
}
