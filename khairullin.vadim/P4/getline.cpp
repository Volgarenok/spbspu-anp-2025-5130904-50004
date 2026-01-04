#include "strings.hpp"
#include <iostream>
#include <iomanip>
char * khairullin::getline(std::istream & input, char * data)
{
  bool is_skipws = input.flags() & std::ios_base::skipws;
  if (is_skipws)
  {
    input >> std::noskipws;
  }
  size_t size = 0;
  size_t capacity = 10;
  char symbol = 0;
  data = new char[capacity];
  try
  {
    while (input >> symbol && symbol != '\n')
    {
      if (size >= capacity - 1)
      {
        char * temp = new char[capacity + 10];
        for (size_t j = 0; j < size; ++j)
        {
          temp[j] = data[j];
        }
        delete [] data;
        data = temp;
        capacity += 10;
      }
      data[size] = symbol;
      ++size;
    }
    data[size] = '\0';
    if (is_skipws)
    {
      input >> std::skipws;
    }
    return data;
  }
  catch (const std::bad_alloc & error)
  {
    delete [] data;
    if (is_skipws)
    {
      input >> std::skipws;
    }
    throw;
  }
}
