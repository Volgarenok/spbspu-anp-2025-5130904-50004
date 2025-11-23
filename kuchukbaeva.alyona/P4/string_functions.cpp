#include "string_functions.hpp"
#include <cctype>
#include <new>
#include <istream>

size_t kuchukbaeva::strLen(const char* str)
{
  size_t len = 0;
  while (str[len] != '\0')
  {
    ++len;
  }
  return len;
}
char* kuchukbaeva::readStr(std::istream& input)
{
  if (input.peek() == std::char_traits< char >::eof())
  {
    return nullptr;
  }
  size_t sizes = 16;
  size_t length = 0;
  char* buffer = new char[sizes];
  char c = 0;
  while (input.get(c) && c != '\n')
  {
    if (length + 1 >= sizes)
    {
      size_t new_sizes = sizes * 2;
      char* new_buffer = new  char[new_sizes];
      for (size_t i = 0; i < length; ++i)
      {
        new_buffer[i] = buffer[i];
      }
      delete[] buffer;
      buffer = new_buffer;
      sizes = new_sizes;
    }
    buffer[length] = c;
    length++;
  }
  buffer[length] = '\0';
  return buffer;
}
int kuchukbaeva::isVowel(char c)
{
  const char lower = std::tolower(c);
  return (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u' || lower == 'y');
}

char* kuchukbaeva::rmvVow(const char* src, char* dest) noexcept
{
  size_t destindex = 0;
  for (size_t i = 0; src[i] != '\0'; ++i)
  {
    if (!std::isalpha(src[i]) || !isVowel(src[i]))
    {
      dest[destindex] = src[i];
      destindex++;
    }
  }
  dest[destindex] = '\0';
  return dest;
}
int kuchukbaeva::repDgt(const char* str) noexcept
{
  int counts[10] = {0};
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    if (std::isdigit(str[i]))
    {
      const int digit = str[i] - '0';
      counts[digit]++;
      if (counts[digit] > 1)
      {
        return 1;
      }
    }
  }
  return 0;
}


