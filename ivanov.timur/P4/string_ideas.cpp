#include "string_ideas.h"
#include <iostream>
#include <cctype>
#include <cstddef>

char *ivanov::get_line(std::istream &in, size_t &length, char stop)
{
  char *data = nullptr;
  size_t capacity = length;

    data = new char[capacity];

  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws)
  {
    in >> std::noskipws;
  }
  char tmp = stop;
  size_t size = 0;
  std::cin >> tmp;
  while (tmp != stop && in && !in.eof())
  {
    if (size + 1 >= capacity)
    {
      size_t new_capacity = capacity * 2;
      char *new_data = nullptr;

      try
      {
        new_data = new char[new_capacity];
      }
      catch (const std::bad_alloc &k)
      {
        delete[] data;
        throw std::bad_alloc(k);
      }
      for (size_t i = 0; i < size; ++i)
      {
        new_data[i] = data[i];
      }
      delete[] data;
      data = new_data;
      capacity = new_capacity;
    }
    data[size] = tmp;
    size++;
    if (in.eof() || in.fail())
    {
      break;
    }
    std::cin >> tmp;
  }
  data[size] = '\0';
  if (is_skipws)
  {
    in >> std::skipws;
  }
  return data;
}

char *ivanov::del_lat(char *content, char *tmpx) {
  if (content[0] == '\0')
  {
    return content;
  }
  size_t new_size = 0;
  size_t c = 0;
  while (*(content + c))
  {
    if (!std::isalpha(static_cast< unsigned char >(content[c])))
    {
      tmpx[new_size++] = content[c];
    }
    c++;
  }
  tmpx[new_size] = '\0';
  return tmpx;
}
void ivanov::output(const char *content)
{
  size_t i = 0;
  while (content[i] != '\0')
  {
    std::cout << " " << content[i++];
  }
}
char *ivanov::spc_rmv(char *content)
{
  if (!*content)
  {
    return content;
  }
  size_t new_size = 0;
  size_t c = 0;
  bool last_was_space = false;
  while (*(content + c))
  {
    if (content[c] != ' ')
    {
      content[new_size++] = content[c];
      last_was_space = false;
    }
    else if (!last_was_space)
    {
      content[new_size++] = ' ';
      last_was_space = true;
    }
    c++;
  }
  if (new_size > 0 && content[new_size - 1] == ' ')
  {
    new_size--;
  }
  content[new_size] = '\0';
  return content;
}

char *ivanov::merge(char *content1, const char *content2, char *tmp, size_t size2)
{
  size_t c = 0;
  while (*(content1 + c))
  {
    tmp[c] = content1[c];
    c++;
  }
  for (size_t i = 0; i < size2; ++i)
  {
    tmp[c + i] = content2[i];
  }
  tmp[c + size2] = '\0';
  return tmp;
}
char *ivanov::get_find(char *content, char *tmp)
{
  bool found[26] = {false};
  size_t e = 0;
  while (*(content + e))
  {
    char c = content[e];
    if (c >= 'a' && c <= 'z')
    {
      found[c - 'a'] = true;
    }
    else if (c >= 'A' && c <= 'Z')
    {
      found[c - 'A'] = true;
    }
    e++;
  }
  size_t found_count = 0;
  for (bool f : found)
  {
    if (f)
    {
      found_count++;
    }
  }
  size_t index = 0;
  for (char c = 'a'; c <= 'z'; ++c)
  {
    if (found[c - 'a'])
    {
      tmp[index++] = c;
    }
  }
  tmp[found_count] = '\0';
  return tmp;
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
size_t ivanov::count(const char *content, char symbol) {
  size_t ans = 0;
  size_t i = 0;
  while (content[i] != '\0')
  {
    if (content[i] == symbol) ans++;
    i++;
  }
  return ans;
}
