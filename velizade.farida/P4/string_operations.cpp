#include "string_operations.hpp"
#include <cstdlib>
#include <iostream>

char* velizade::read_string(std::istream& input, size_t& length)
{
  std::ios::fmtflags original_flags = input.flags();
  size_t capacity = 32;
  size_t size = 0;
  char* buffer = static_cast< char* >(malloc(capacity));
  if (!buffer)
  {
    input.flags(original_flags);
    return nullptr;
  }
  input >> std::noskipws;
  char ch;
  while (input >> ch && ch != '\n')
  {
    if (size + 1 >= capacity)
    {
      capacity *= 2;
      char* new_buffer = static_cast< char* >(realloc(buffer, capacity));
      if (!new_buffer)
      {
        free(buffer);
        input.flags(original_flags);
        return nullptr;
      }
      buffer = new_buffer;
    }
    buffer[size] = ch;
    size++;
  }
  buffer[size] = '\0';
  length = size;
  if (size + 1 < capacity)
  {
    char* exact_buffer = static_cast< char* >(realloc(buffer, size + 1));
    if (exact_buffer)
    {
      buffer = exact_buffer;
    }
  }
  input.flags(original_flags);
  return buffer;
}

char* velizade::rep_sym(const char* str)
{
  if (!str)
  {
    return nullptr;
  }
  size_t unique_count = 0;
  for (size_t i = 0; str[i]; i++)
  {
    int count = 0;
    for(size_t j = 0; str[j]; j++)
    {
      if (str[i] == str[j])
      {
        count++;
      }
    }
    if (count > 1)
    {
      bool already_counted = false;
      for (size_t k = 0; k < i; k++)
      {
        if (str[k] == str[i])
        {
          already_counted = true;
          break;
        }
      }
      if (!already_counted)
      {
        unique_count++;
      }
    }
  }
  char* buffer = reinterpret_cast< char* >(malloc(unique_count + 1));
  if (!buffer)
  {
    return nullptr;
  }
  size_t pos = 0;
  for (size_t i = 0; str[i]; i++)
  {
    int count = 0;
    for (size_t j = 0; str[j]; j++)
    {
      if (str[i] == str[j])
      {
        count++;
      }
    }
    if (count > 1)
    {
      bool already_added = false;
      for (size_t k = 0; k < pos; k++)
      {
        if (buffer[k] == str[i])
        {
          already_added = true;
          break;
        }
      }
      if (!already_added)
      {
        buffer[pos++] = str[i];
      }
    }
  }
  buffer[pos] = '\0';
  return buffer;
}
char* velizade::uni_two(const char* str1, const char* str2)
{
  if (!str1 || !str2)
  {
    return nullptr;
  }
  size_t len1 = 0;
  size_t len2 = 0;
  while (str1[len1])
  {
    len1++;
  }
  while (str2[len2])
  {
    len2++;
  }
  size_t total_len = len1 + len2;
  char* buffer = reinterpret_cast< char* >(malloc(total_len + 1));
  if (!buffer)
  {
    return nullptr;
  }
  size_t i = 0;
  size_t j = 0;
  size_t pos = 0;
  while (str1[i] || str2[j])
  {
    if (str1[i])
    {
      buffer[pos++] = str1[i++];
    }
    if (str2[j])
    {
      buffer[pos++] = str2[j++];
    }
  }
  buffer[pos] = '\0';
  return buffer;
}
