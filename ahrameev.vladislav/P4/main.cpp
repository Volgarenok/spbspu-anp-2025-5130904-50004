#include <iostream>
#include <cstdlib>
#include <cstring>
#include "transform.h"

namespace ahrameev
{

  char* read_line()
  {
    const int START_SIZE = 10;

    char* buffer = static_cast<char*>(malloc(START_SIZE));

    if (buffer == 0)
    {
      return 0;
    }

    int capacity = START_SIZE;
    int length = 0;
    char c;

    while (std::cin.get(c))
    {
      if (c == '\n')
      {
        break;
      }

      if (length + 1 >= capacity)
      {
        int new_capacity = capacity * 2;

        char* new_buffer = static_cast<char*>(malloc(new_capacity));

        if (new_buffer == 0)
        {
          free(buffer);
          return 0;
        }

        for (int i = 0; i < length; ++i)
        {
          new_buffer[i] = buffer[i];
        }

        free(buffer);
        buffer = new_buffer;
        capacity = new_capacity;
      }

      buffer[length] = c;
      ++length;
    }

    buffer[length] = '\0';

    return buffer;
  }

}

int main()
{
  char* input_str = ahrameev::read_line();

  if (input_str == 0)
  {
    std::cerr << "Error: cannot allocate memory\n";
    return 1;
  }

  int diff_count = ahrameev::count_diff_latin_letters(input_str);
  std::cout << diff_count << '\n';

  size_t len = std::strlen(input_str);

  char* dest = static_cast<char*>(malloc(len + 1));

  if (dest == 0)
  {
    std::cerr << "Error: cannot allocate output buffer\n";
    free(input_str);
    return 1;
  }

  if (ahrameev::to_lower_latin(dest, len + 1, input_str) == 0)
  {
    std::cerr << "Error: conversion failed\n";
    free(input_str);
    free(dest);
    return 1;
  }

  std::cout << dest << '\n';

  free(input_str);
  free(dest);

  return 0;
}
