#include "string_ideas.h"
#include <iostream>
#include <cctype>
#include <cstddef>

void ivanov::get_line(std::istream &in, char *&data, size_t &size)
{
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws)
  {
    in >> std::noskipws;
  }
  char tmp = '\n';
  in >> tmp;
  while (tmp != '\n' && std::cin)
  {
    data[size] = tmp;
    size++;
    in >> tmp;
  }
  data[size] = 0;
  size++;
  if (is_skipws)
  {
    in >> std::skipws;
  }
}

bool ivanov::del_lat(char *&content, size_t &size) {
  try
  {
    char* tmp = new char[100000];
    size_t c = 0;
    for (size_t i = 0; i < size; ++i)
    {
      if (!isalpha(content[i]))
      {
        tmp[i - c] = content[i];
      }
      else
      {
        c++;
      }
    }
    delete[] content;
    content = tmp;
    size-=c;
    return true;
  }
  catch (...)
  {
    return false;
  }
}
void ivanov::output(const char *content, size_t &size)
{
  for (size_t i = 0; i < size; ++i)
  {
    std::cout << content[i];
  }
  std::cout << "\n";
}
bool ivanov::spc_rmv(char *&content, size_t &size)
{
  try
  {
    char* tmp = new char[100000];
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
    content = tmp;
    size-=c;
    return true;
  }
  catch (...)
  {
    return false;
  }
}
bool ivanov::merge(char *&content1, char *content2, size_t &size1, size_t size2)
{
  try
  {
    char* tmp = new char[100000];
    for (size_t i = 0; i < size1; ++i)
    {
      tmp[i] = content1[i];
    }
    for (size_t i = size1; i < size1 + size2; ++i)
    {
      tmp[i] = content2[i - size1];
    }
    delete[] content1;
    content1 = tmp;
    size1+=size2;
    return true;
  }
  catch (...)
  {
    return false;
  }
}
bool ivanov::get_find(char *&content, size_t &size)
{
  try
  {
    char* tmp = new char[100000];
    size_t l = 0;
    char x = 'a';
    char z = 'A';
    for (size_t c = 0; c < 26; ++c)
    {
      if (find(x, content, size) || find(z, content, size))
      {
        tmp[l] = x;
        l++;
      }
      x++;
      z++;
    }
    delete[] content;
    content = tmp;
    size = l;
    return true;
  }
  catch (...)
  {
    return false;
  }
}
bool ivanov::find(char symbol, const char *content, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    if (content[i] == symbol)
    {
      return true;
    }
  }
  return false;
}
