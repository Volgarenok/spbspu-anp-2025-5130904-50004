#include "line.hpp"
#include <iostream>

char *haliullin::getline(std::istream &in, char end, size_t &size)
{
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws)
  {
    in >> std::noskipws;
  }

  char symb = '\0';
  size_t s = 0;
  size_t cap = 10;
  char *arr = reinterpret_cast< char* >(malloc(cap * sizeof(char)));
  if (arr == nullptr)
  {
    if (is_skipws)
    {
      in >> std::skipws;
    }
    return nullptr;
  }

  while (in >> symb && symb != end)
  {
    if (s == cap)
    {
      char *temp = reinterpret_cast< char* >(malloc(2 * cap * sizeof(char)));

      if (temp == nullptr)
      {
        if (is_skipws)
        {
          in >> std::skipws;
        }
        free(arr);
        return nullptr;
      }

      for (size_t i = 0; i < s; ++i)
      {
        temp[i] = arr[i];
      }
      cap *= 2;
      free(arr);
      arr = temp;
    }

    arr[s++] = symb;
  }

  if (is_skipws)
  {
    in >> std::skipws;
  }

  arr[s] = '\0';
  size = s;
  return arr;
}

size_t haliullin::DIF_LAT(const char *arr)
{
  size_t count = 0;
  size_t ind = 0;
  char symb = '\0';
  const size_t alphs = 26;
  bool info[alphs] = {};

  for (size_t i = 0; arr[i] != '\0'; ++i)
  {
    symb = char(std::tolower(arr[i]));
    if (std::isalpha(symb))
    {
      ind = symb - 'a';
      if (!info[ind])
      {
        info[ind] = true;
        ++count;
      }
    }
  }
  return count;
}

char *haliullin::RMV_VOW(char *new_arr, const char *arr)
{
  size_t ind = 0;
  char symb = '\0';
  for (size_t i = 0; arr[i] != '\0'; ++i)
  {
    symb = char(std::tolower(arr[i]));
    if (!isVowel(symb))
    {
      new_arr[ind++] = arr[i];
    }
  }
  new_arr[ind] = '\0';
  return new_arr;
}

bool haliullin::isVowel(const char c)
{
  char alph[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
  for (size_t i = 0; i < 6; ++i)
  {
    if (c == alph[i])
    {
      return true;
    }
  }
  return false;
}

size_t haliullin::sizeWithoutVowels(const char *arr)
{
  size_t count = 0;
  char symb = '\0';
  for (size_t i = 0; arr[i] != '\0'; ++i)
  {
    symb = char(std::tolower(arr[i]));
    if (!isVowel(symb))
    {
      ++count;
    }
  }
  return count;
}

