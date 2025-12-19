#include "string_ideas.h"
#include <iostream>
#include <cctype>
#include <cstddef>

char *ivanov::get_line(std::istream &in, size_t &length, char stop)
{
  char *data = nullptr;
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws)
  {
    in >> std::noskipws;
  }
  char tmp = stop;
  size_t size = 0;
  std::cin >> tmp;
  try
  {
    data = dataGen(tmp, stop, in, size, length);
  }
  catch (const std::bad_alloc &z)
  {
    if (is_skipws)
    {
      in >> std::skipws;
    }
    throw;
  }
  data[size] = '\0';
  if (is_skipws)
  {
    in >> std::skipws;
  }
  return data;
}

char *ivanov::dataGen(char tmp, char stop, std::istream &in, size_t &size, size_t &capacity)
{
  char *data = new char[capacity];
  while (tmp != stop && in && !in.eof())
  {
    if (size + 1 >= capacity)
    {
      try
      {
        data = resize(capacity, size, data);
      }
      catch (const std::bad_alloc &k)
      {
        delete[] data;
        throw;
      }
    }
    data[size] = tmp;
    size++;
    if (in.eof() || in.fail())
    {
      break;
    }
    std::cin >> tmp;
  }
  return data;
}

char *ivanov::resize(size_t &capacity, size_t size, const char *data)
{
  size_t new_capacity = capacity * 2;
  char *new_data = new char[new_capacity];
  for (size_t i = 0; i < size; ++i)
  {
    new_data[i] = data[i];
  }
  delete[] data;


  capacity = new_capacity;
  return new_data;
}


char *ivanov::del_lat(const char *content, char *tmpx)
{
  if (content[0] == '\0')
  {
    tmpx[0] = content[0];
    return tmpx;
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
char *ivanov::spc_rmv(char *content)
{
  if (!*content)
  {
    return content;
  }
  size_t new_size = 0;
  for (size_t c = 0; content[c] != '\0'; ++c)
  {
    if (content[c] != ' ' || (new_size > 0 && content[new_size - 1] != ' '))
    {
      content[new_size++] = content[c];
    }
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
char *ivanov::get_find(const char *content, char *tmp)
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
  for (bool f: found)
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
size_t ivanov::count(const char *content, char symbol)
{
  size_t ans = 0;
  size_t i = 0;
  while (content[i] != '\0')
  {
    if (content[i] == symbol)
    {
      ans++;
    }

    i++;
  }
  return ans;
}
