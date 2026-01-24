#include "strings.hpp"
#include <iostream>
#include <iomanip>

namespace dolenko
{

char* getline(std::istream& input, char* data)
{
  bool was_skipws = (input.flags() & std::ios_base::skipws) != 0;
  if (was_skipws)
  {
    input >> std::noskipws;
  }

  size_t size = 0;
  size_t capacity = 10;
  char symbol = 0;

  if (!data)
  {
    data = new char[capacity];
  }

  char* buffer = data;

  try
  {
    while (input >> symbol && symbol != '\n')
    {
      if (size >= capacity - 1)
      {
        size_t new_capacity = capacity + 10;
        char* temp_buffer = new char[new_capacity];

        for (size_t i = 0; i < size; ++i)
        {
          temp_buffer[i] = buffer[i];
        }

        delete[] buffer;
        buffer = temp_buffer;
        capacity = new_capacity;
      }

      buffer[size] = symbol;
      ++size;
    }

    buffer[size] = '\0';

    if (was_skipws)
    {
      input >> std::skipws;
    }

    return buffer;
  }
  catch (const std::bad_alloc& error)
  {
    if (buffer != data)
    {
      delete[] buffer;
    }
    if (was_skipws)
    {
      input >> std::skipws;
    }
    throw;
  }
}

} 