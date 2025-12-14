#include <iostream>
#include <iomanip>
#include "strings.hpp"

char * khairullin::getline(std::istream & input, char * data)
{
  bool is_skipws = input.flags() & std::ios_base::skipws;
  if (is_skipws)
  {
    input >> std::noskipws;
  }
  size_t size = 1;
  size_t capacity = 10;
  char symbol = 0;
  data = new char[capacity];
  input >> symbol;
  data[0] = symbol;
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
  catch (std::bad_alloc & error)
  {
    delete [] data;
    throw;
  }
}
