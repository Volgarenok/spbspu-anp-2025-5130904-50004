#include "string_ideas.h"
#include <iostream>
#include <cctype>
#include <cstddef>

char * ivanov::get_line(std::istream &in, char *data, size_t &size, size_t &length)
{
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws)
  {
    in >> std::noskipws;
  }
  char tmp = '\n';
  size = 0;
  in >> tmp;
  while (tmp != '\n' && in)
  {
    if (size + 1 >= length)
    {
      size_t new_length = length * 2;
      char * tmx = new char[new_length];
      for (size_t i = 0; i < size; ++i)
      {
        tmx[i] = data[i];
      }
      delete[] data;
      data = tmx;
      length = new_length;
    }
    data[size] = tmp;
    size++;
    in >> tmp;
  }
  data[size] = '\0';
  if (is_skipws)
  {
    in >> std::skipws;
  }

  return data;
}

char * ivanov::del_lat(char *content, size_t &size) {
  if (size == 0) return content;

  size_t new_size = 0;
  for (size_t i = 0; i < size; ++i)
  {
    if (!std::isalpha(static_cast<unsigned char>(content[i])))
    {
      content[new_size++] = content[i];
    }
  }
  content[new_size] = '\0';
  size = new_size;
  if (new_size > 0 && new_size < size / 2)
  {
    char * tmp = new char[new_size + 1];
    for (size_t i = 0; i <= new_size; ++i)
    {
      tmp[i] = content[i];
    }
    delete[] content;
    content = tmp;
  }

  return content;
}
void ivanov::output(const char *content)
{
  size_t i = 0;
  while (content[i] != '\0')
  {
    std::cout << content[i++];
    if (content[i] != '\0') std::cout << " ";
  }
}
char * ivanov::spc_rmv(char *content, size_t &size)
{
  if (size == 0) return content;

  size_t new_size = 0;
  bool last_was_space = false;

  for (size_t i = 0; i < size; ++i)
  {
    if (content[i] != ' ')
    {
      content[new_size++] = content[i];
      last_was_space = false;
    }
    else if (!last_was_space)
    {
      content[new_size++] = ' ';
      last_was_space = true;
    }
  }
  if (new_size > 0 && content[new_size - 1] == ' ')
  {
    new_size--;
  }

  content[new_size] = '\0';
  size = new_size;

  return content;
}

char * ivanov::merge(char *content1, const char *content2, size_t &size1, size_t size2)
{
  size_t total_size = size1 + size2;
  char * tmp = new char[total_size + 1];

  for (size_t i = 0; i < size1; ++i)
  {
    tmp[i] = content1[i];
  }
  for (size_t i = 0; i < size2; ++i)
  {
    tmp[size1 + i] = content2[i];
  }
  tmp[total_size] = '\0';
  delete[] content1;
  content1 = tmp;
  size1 = total_size;

  return content1;
}
char * ivanov::get_find(char *content, size_t &size)
{
  bool found[26] = {false};
  for (size_t i = 0; i < size; ++i)
  {
    char c = content[i];
    if (c >= 'a' && c <= 'z')
    {
      found[c - 'a'] = true;
    }
    else if (c >= 'A' && c <= 'Z')
    {
      found[c - 'A'] = true;
    }
  }
  size_t found_count = 0;
  for (bool f : found)
  {
    if (f) found_count++;
  }
  char * tmp = new char[found_count + 1];
  size_t index = 0;
  for (char c = 'a'; c <= 'z'; ++c)
  {
    if (found[c - 'a'])
    {
      tmp[index++] = c;
    }
  }
  tmp[found_count] = '\0';
  delete[] content;
  content = tmp;
  size = found_count;

  return content;
}
bool ivanov::find(char symbol, const char *content)
{
  size_t i = 0;
  while (content[i] != '\0')
  {
    if (content[i] == symbol)
    {
      return true;
    }
    i++;
  }
  return false;
}
size_t ivanov::count(char *content, char symbol) {
  size_t ans = 0;
  size_t i = 0;
  while (content[i] != '\0')
  {
    if (content[i] == symbol) ans++;
    i++;
  }
  return ans;
}
