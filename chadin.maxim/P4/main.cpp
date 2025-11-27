#include "strings.h"
#include <iostream>
#include <cstdlib>

namespace
{
char* readLine()
{
  const size_t initialSize = 64;
  size_t capacity = initialSize;
  size_t length = 0;
  char* buffer = static_cast<char*>(std::malloc(capacity));
  if (buffer == nullptr)
  {
    return nullptr;
  }

  int ch;
  while ((ch = std::getchar()) != '\n' && ch != EOF)
  {
    if (length + 1 >= capacity)
    {
      capacity *= 2;
      char* newBuffer = static_cast<char*>(std::realloc(buffer, capacity));
      if (newBuffer == nullptr)
      {
        std::free(buffer);
        return nullptr;
      }
      buffer = newBuffer;
    }
    buffer[length++] = static_cast<char>(ch);
  }
  if (ch == EOF && length == 0)
  {
    std::free(buffer);
    return nullptr;
  }

  buffer[length] = '\0';
  return buffer;
}
}


int main()
{
  while (true)
  {
    char* line1 = readLine();
    if (line1 == nullptr)
    {
      break;
    }

    char* line2 = readLine();
    if (line2 == nullptr) {
      std::free(line1);
      std::cerr << "Error: Incomplete input." << std::endl;
      return 1;
    }
    
}
