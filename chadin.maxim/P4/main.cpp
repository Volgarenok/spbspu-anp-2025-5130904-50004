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
    if (line2 == nullptr)
    {
      std::free(line1);
      std::cerr << "Error: Incomplete input." << std::endl;
      return 1;
    }

    int hasSame = chadin::hasSameSymbols(line1, line2);
    std::cout << hasSame << '\n';

    size_t len1 = 0;
    while (line1[len1] != '\0')
    {
      ++len1;
    }

    size_t digits2 = 0;
    for (size_t i = 0; line2[i] != '\0'; ++i)
    {
      if (line2[i] >= '0' && line2[i] <= '9')
      {
        ++digits2;
      }
    }

    size_t resultSize = len1 + digits2 + 1;
    char* result = static_cast<char*>(std::malloc(resultSize));
    if (result == nullptr)
    {
      std::free(line1);
      std::free(line2);
      std::cerr << "Error: Memory allocation failed." << std::endl;
      return 1;
    }

    int dgtErr = chadin::digitSnd(line1, line2, result, resultSize);
    if (dgtErr != 0)
    {
      std::free(line1);
      std::free(line2);
      std::free(result);
      std::cerr << "Error: digitSnd failed." << std::endl;
      return 1;
    }

    std::cout << result << '\n';

    
}
