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
char* kuchukbaeva::readStr(std::istream& input, size_t& read_size)
{
  size_t capacity = 16;
  size_t size = 0;
  char* buffer = new char[capacity];
  char c = 0;
  input >> std::noskipws;
  while (input.get(c) && c != '\n')
  {
    if (size + 1 >= capacity)
    {
      size_t new_capacity = capacity * 2;
      char* new_buffer = nullptr;
      try
      {
        new_buffer = new char[new_capacity];
      }
      catch (...)
      {
        delete[] buffer;
        throw;
      }
      for (size_t i = 0; i < size; ++i)
      {
        new_buffer[i] = buffer[i];
      }
      delete[] buffer;
      buffer = new_buffer;
      capacity = new_capacity;
    }
    buffer[size] = c;
    size++;
  }
  if (size == 0 && !input)
  {
    delete[] buffer;
    return nullptr;
  }
  buffer[size] = '\0';
  read_size = size;
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
    if (!isVowel(src[i]))
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

