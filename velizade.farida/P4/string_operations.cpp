#include "string_operations.hpp"
#include <cstdlib>
#include <iostream>

char* velizade::read_string(std::istream& input, size_t& length)
{
    std::ios::fmtflags flags = input.flags();
    char* str = static_cast<char*>(malloc(length + 1));
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
  if (!buffer || !str)
  {
    return 1;
  }
  size_t pos = 0;
  for (size_t i = 0; str[i]; i++)
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
    if (already_added)
    {
      continue;
    }
    int count = 0;
    if (count > 1)
    {
      buffer[pos++] = str[i];
    }
  }
  buffer[pos] = '\0';
  return 0;
}

char* velizade::uni_two(const char* str1, const char* str2)
{
  if (!buffer || !str1 || !str2)
  {
    return 1;
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
  return 0;
}
