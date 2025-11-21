#include "strings.hpp"

#include <cctype>
#include <cstring>

char* vasilenko::findMissingLetters(const char* src, char* dest)
{
  int present[26] = {};
  size_t len = std::strlen(src);

  for (size_t i = 0; i < len; ++i)
  {
    unsigned char uChar = src[i];

    if (std::isalpha(uChar))
    {
      char lower = std::tolower(uChar);
      int index = lower - 'a';
      if (index >= 0 && index < 26)
      {
        present[index] = 1;
      }
    }
  }

  size_t destIdx = 0;
  for (int i = 0; i < 26; ++i)
  {
    if (present[i] == 0)
    {
      dest[destIdx++] = 'a' + i;
    }
  }
  dest[destIdx] = '\0';

  return dest;
}

char* vasilenko::mergeStrings(const char* src1, const char* src2, char* dest)
{
  size_t len1 = std::strlen(src1);
  size_t len2 = std::strlen(src2);
  size_t i = 0;
  size_t j = 0;
  size_t k = 0;

  while (i < len1 && j < len2)
  {
    dest[k++] = src1[i++];
    dest[k++] = src2[j++];
  }

  if (i < len1)
  {
    std::strcpy(dest + k, src1 + i);
  }
  else if (j < len2)
  {
    std::strcpy(dest + k, src2 + j);
  }
  else
  {
    dest[k] = '\0';
  }

  return dest;
}
