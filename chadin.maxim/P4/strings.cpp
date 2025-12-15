#include "strings.h"
#include <cctype>

namespace chadin
{
  int hasSameSymbols(const char* str1, const char* str2)
  {
    if (str1 == nullptr || str2 == nullptr)
    {
      return 0;
    }

    for (const char* p1 = str1; *p1 != '\0'; ++p1)
    {
      for (const char* p2 = str2; *p2 != '\0'; ++p2)
      {
        if (*p1 == *p2)
        {
          return 1;
        }
      }
    }
    return 0;
  }

  int digitSnd(const char* str1, const char* str2, char* result, size_t bufferSize)
  {
    if (str1 == nullptr || str2 == nullptr || result == nullptr || bufferSize == 0)
    {
      return 1;
    }

    size_t pos = 0;

    for (size_t i = 0; str1[i] != '\0'; ++i)
    {
      if (pos >= bufferSize - 1)
      {
        return 1;
      }
      result[pos++] = str1[i];
    }

    for (size_t i = 0; str2[i] != '\0'; ++i)
    {
      if (std::isdigit(static_cast<unsigned char>(str2[i])))
      {
        if (pos >= bufferSize - 1)
        {
          return 1;
        }
        result[pos++] = str2[i];
      }
    }

    result[pos] = '\0';
    return 0;
  }
}
