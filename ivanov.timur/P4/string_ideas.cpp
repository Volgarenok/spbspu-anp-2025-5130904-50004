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
  in >> tmp;
  while (tmp != '\n' && in)
  {
    if (size + 1 > length)
    {
      char * tmx = new char[++length];
      for (size_t i = 0; i < length - 1; ++i)
      {
        tmx[i] = data[i];
      }
      delete[] data;
      data = tmx;
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
  size_t c = 0;
  size_t e = 0;

  for (size_t i = 0; i < size; ++i)
  {
    if (!std::isalpha(content[i]))
    {
      e++;
    }
  }
  char tmp[e];
  for (size_t i = 0; i < size; ++i)
  {
    if (!std::isalpha(content[i]))
    {
      tmp[i - c] = content[i];
    }
    else
    {
      c++;
    }
  }
  delete[] content;
  size = e;

  return tmp;
}
void ivanov::output(const char *content)
{
  size_t i = 0;
  while (content[i] != '\0')
  {
      std::cout << content[i++] << " ";
  }
}
char * ivanov::spc_rmv(char *content, size_t &size)
{
  char tmp[size - count(content, ' ')];
  bool flag = false;
  size_t c = 0;
  for (size_t i = 0; i < size; ++i)
  {
    if ((!flag || content[i - 1] == ' ') && content[i] == ' ')
    {
      tmp[i - c] = content[i];
      flag = true;
    }
    else
    {
      c++;
    }
  }
  delete[] content;
  size-=c;

  return tmp;
}
char * ivanov::merge(char *content1, char *content2, size_t &size1, size_t size2)
{
  char tmp[size1 + size2];
  for (size_t i = 0; i < size1; ++i)
  {
    tmp[i] = content1[i];
  }
  for (size_t i = size1; i < size1 + size2; ++i)
  {
    tmp[i] = content2[i - size1];
  }
  delete[] content1;
  size1+=size2;

  return tmp;
}
char * ivanov::get_find(char *content, size_t &size)
{
  char tmp[26];
  size_t l = 0;
  char x = 'a';
  char z = 'A';
  for (size_t c = 0; c < 26; ++c)
  {
    if (find(x, content) || find(z, content))
    {
      tmp[l] = x;
      l++;
    }
    x++;
    z++;
  }
  delete[] content;
  size = l;

  return tmp;
}
bool ivanov::find(char symbol, const char *content)
{
  size_t i = 0;
  while (content[i] != '\0')
  {
    if (content[i++] == symbol)
    {
      return true;
    }
  }
  return false;
}
size_t ivanov::count(char *content, char symbol) {
  size_t ans = 0;
  size_t i = 0;
  while (content[i] != '\0')
  {
    if (content[i++] == symbol) ans++;
  }
  return ans;
}
