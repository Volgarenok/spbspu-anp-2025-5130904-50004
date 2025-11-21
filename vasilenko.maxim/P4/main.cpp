#include <cstring>
#include <iostream>
#include <new>

#include "strings.hpp"

int main()
{
  size_t capacity = 10;
  size_t size = 0;
  char* buffer = nullptr;

  try
  {
    buffer = new char[capacity];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation failed: " << e.what() << "\n";
    return 1;
  }

  std::cin >> std::noskipws;
  char c = 0;

  while (std::cin >> c)
  {
    if (c == '\n')
    {
      break;
    }

    if (size == capacity - 1)
    {
      size_t newCapacity = capacity * 2;
      char* newBuffer = nullptr;
      try
      {
        newBuffer = new char[newCapacity];
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << "Memory reallocation failed: " << e.what() << "\n";
        delete[] buffer;
        return 1;
      }

      std::memcpy(newBuffer, buffer, size);
      delete[] buffer;
      buffer = newBuffer;
      capacity = newCapacity;
    }

    buffer[size++] = c;
  }
  buffer[size] = '\0';

  char* missingRes = nullptr;
  try
  {
    missingRes = new char[27];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation failed: " << e.what() << "\n";
    delete[] buffer;
    return 1;
  }

  vasilenko::findMissingLetters(buffer, missingRes);
  std::cout << missingRes << "\n";
  delete[] missingRes;

  delete[] buffer;

  return 0;
}
