#include "string.hpp"
#include <cctype>
#include <cstdlib>
#include <istream>

namespace
{
  bool isLatinVowel(char c) noexcept
  {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'
        || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
  }
}

char* aydogan::readString(std::istream& in)
{
  if (!in)
  {
    return nullptr;
  }

  size_t capacity = 16;
  char* buffer = reinterpret_cast< char* >(std::malloc(capacity));
  if (!buffer)
  {
    return nullptr;
  }

  in >> std::noskipws;

  size_t length = 0;
  char c = '\0';

  while ((in >> c) && (c != '\n'))
  {
    if (length + 1 >= capacity)
    {
      size_t new_capacity = capacity * 2;
      char* new_buffer = reinterpret_cast< char* >(std::realloc(buffer, new_capacity));
      if (!new_buffer)
      {
        std::free(buffer);
        return nullptr;
      }
      buffer = new_buffer;
      capacity = new_capacity;
    }

    buffer[length] = c;
    ++length;
  }

  if (!in && length == 0)
  {
    std::free(buffer);
    return nullptr;
  }

  buffer[length] = '\0';
  return buffer;
}

char* aydogan::removeVowels(const char* src, char* dest) noexcept
{
  if (!src || !dest)
  {
    return nullptr;
  }

  size_t j = 0;
  for (size_t i = 0; src[i] != '\0'; ++i)
  {
    if (isLatinVowel(src[i]))
    {
      continue;
    }
    dest[j] = src[i];
    ++j;
  }

  dest[j] = '\0';
  return dest;
}

char* aydogan::appendDigits(const char* first, const char* second, char* dest) noexcept
{
  if (!first || !second || !dest)
  {
    return nullptr;
  }

  size_t j = 0;

  for (size_t i = 0; first[i] != '\0'; ++i)
  {
    dest[j] = first[i];
    ++j;
  }

  for (size_t i = 0; second[i] != '\0'; ++i)
  {
    unsigned char uc = static_cast< unsigned char >(second[i]);
    if (std::isdigit(uc))
    {
      dest[j] = second[i];
      ++j;
    }
  }

  dest[j] = '\0';
  return dest;
}
