#include "strings.h"
#include <iostream>
#include <cstdlib>
#include <cctype>

namespace {

  char* readLine(std::istream& input, size_t& outLength)
  {
    const size_t initialSize = 64;
    size_t capacity = initialSize;
    size_t length = 0;
    char* buffer = static_cast< char* >( std::malloc( capacity ) );
    if (buffer == nullptr)
    {
      outLength = 0;
      return nullptr;
    }

    int ch;
    while ((ch = input.get()) != '\n' && ch != EOF)
    {
      if (length + 1 >= capacity)
      {
        capacity *= 2;
        char* newBuffer = static_cast< char* >( std::malloc( capacity ) );
        if (newBuffer == nullptr)
        {
          std::free(buffer);
          outLength = 0;
          return nullptr;
        }
        for (size_t i = 0; i < length; ++i)
        {
          newBuffer[i] = buffer[i];
        }
        std::free(buffer);
        buffer = newBuffer;
      }
      buffer[length++] = static_cast< char >( ch );
    }

    if (ch == EOF && length == 0)
    {
      std::free(buffer);
      outLength = 0;
      return nullptr;
    }

    buffer[length] = '\0';
    outLength = length;
    return buffer;
  }

}

int main()
{
  bool processedAtLeastOnePair = false;

  size_t len1 = 0;
  char* line1 = readLine(std::cin, len1);
  while (line1 != nullptr)
  {
    size_t len2 = 0;
    char* line2 = readLine(std::cin, len2);
    if (line2 == nullptr)
    {
      line2 = static_cast< char* >( std::malloc( 1 ) );
      if (line2 == nullptr)
      {
        std::free(line1);
        std::cerr << "Error: Memory allocation failed." << std::endl;
        return 2;
      }
      line2[0] = '\0';
      len2 = 0;
    }

    processedAtLeastOnePair = true;

    int hasSame = chadin::hasSameSymbols(line1, line2);
    std::cout << hasSame << '\n';

    size_t digits2 = 0;
    for (size_t i = 0; i < len2; ++i)
    {
      if (std::isdigit(static_cast<unsigned char>(line2[i])))
      {
        ++digits2;
      }
    }

    size_t resultSize = len1 + digits2 + 1;
    char* result = static_cast< char* >( std::malloc( resultSize ) );
    if (result == nullptr)
    {
      std::free(line1);
      std::free(line2);
      std::cerr << "Error: Memory allocation failed." << std::endl;
      return 2;
    }

    int dgtErr = chadin::digitSnd(line1, line2, result, resultSize);
    if (dgtErr != 0)
    {
      std::free(line1);
      std::free(line2);
      std::free(result);
      std::cerr << "Error: digitSnd failed." << std::endl;
      return 2;
    }

    std::cout << result << '\n';

    std::free(line1);
    std::free(line2);
    std::free(result);

    line1 = readLine(std::cin, len1);
  }

  if (!processedAtLeastOnePair)
  {
    std::cerr << "Error: No input provided." << std::endl;
    return 1;
  }

  return 0;
}
