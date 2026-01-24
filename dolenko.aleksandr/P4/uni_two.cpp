#include "strings.hpp"

namespace dolenko
{

char* uni_two(char* dest, const char* str1, const char* str2)
{
  if (!dest || !str1 || !str2)
  {
    return dest;
  }

  size_t i = 0;
  size_t j = 0;
  size_t index = 0;

  while (str1[i] != '\0' || str2[j] != '\0')
  {
    if (str1[i] != '\0')
    {
      dest[index++] = str1[i++];
    }
    if (str2[j] != '\0')
    {
      dest[index++] = str2[j++];
    }
  }

  dest[index] = '\0';
  return dest;
}

} 