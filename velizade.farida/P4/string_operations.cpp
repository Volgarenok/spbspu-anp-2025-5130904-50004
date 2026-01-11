#include "string_operations.hpp"
#include <cstdlib>
#include <iostream>

char* velizade::read_string(std::istream& input, size_t& length)
{
    std::ios::fmtflags flags = input.flags();
    char* str = static_cast< char* >( malloc( length + 1 ) );
    if (!str)
    {
        return nullptr;
    }
    size_t i = 0;
    char ch;
    input >> std::noskipws;
    while (i < length && input >> ch && ch != '\n')
    {
        str[i++] = ch;
    }
    str[i] = '\0';
    input.flags(flags);
    length = i;
    return str;
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
  char* buffer = reinterpret_cast< char* >( malloc( unique_count + 1 ) );
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
  char* buffer = reinterpret_cast< char* >( malloc ( total_len + 1 ) );
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
