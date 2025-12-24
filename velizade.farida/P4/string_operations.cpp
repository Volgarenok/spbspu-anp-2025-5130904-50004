#include "string_operations.hpp"
#include <cstdlib>

char* velizade::read_string(std::istream& input, size_t size)
{
  char* str = static_cast<char*>(malloc(size + 1));
  if (!str)
  {
    return nullptr;
  }
  size_t i = 0;
  int ch = input.get();
  while (i < size && ch != EOF && ch != '\n')
  {
    str[i++] = static_cast<char>(ch);
    ch = input.get();
  }
  str[i] = '\0';
  return str;
}

void velizade::print_string(std::ostream& output, const char* str)
{
  if (str)
  {
    output << str;
  }
}

int velizade::rep_sym(char* buffer, const char* str)
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

int velizade::uni_two(char* buffer, const char* str1, const char* str2)
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
