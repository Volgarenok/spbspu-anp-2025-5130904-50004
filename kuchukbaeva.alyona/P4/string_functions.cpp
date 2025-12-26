#include "string_functions.hpp"
#include <cctype>
#include <new>
#include <istream>

char* kuchukbaeva::reSize(char* buffer, size_t& capacity)
{
  size_t new_capacity = capacity * 2;
  char* new_buffer = new char[new_capacity];
  for (size_t i = 0; i < capacity; ++i)
  {
    new_buffer[i] = buffer[i];
  }
  delete[] buffer;
  capacity = new_capacity;
  return new_buffer;
}


char* kuchukbaeva::readStr(std::istream& input, size_t& read_size)
{
  size_t capacity = 16;
  size_t size = 0;
  char* buffer = new char[capacity];
  try
  {
    std::ios_base::fmtflags origin_flags = input.flags();
    input >> std::noskipws;
    char c = 0;
    while ((input >> c) && c != '\n')
    {
      if (size + 1 >= capacity)
      {
        buffer = reSize(buffer, capacity);
      }
      buffer[size++] = c;
    }
    input.flags(origin_flags);
    buffer[size] = '\0';
    read_size = size;
  }
  catch (const std::bad_alloc& e)
  {
    delete[] buffer;
    throw;
  }
  return buffer;
}
int kuchukbaeva::isVowel(char c) noexcept
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
