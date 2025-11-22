#include "string_functions.hpp"
#include <iostream>

char *haliullin::getline(std::istream &in, size_t &size)
{
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws)
  {
    in >> std::noskipws;
  }
  char symb = '\0';
  char *arr = nullptr;
  size = 0;

  in >> symb;
  if (in)
  {
    ++size;
    arr = static_cast < char* >(malloc(sizeof(char)));
    if (arr == nullptr)
    {
      if (is_skipws)
      {
        in >> std::skipws;
      }
      return nullptr;
    }
    arr[0] = symb;
    while (in >> symb && symb != '\0')
    {
      char *temp = nullptr;
      temp = static_cast < char* >(malloc((size + 1) * sizeof(char)));
      if (temp == nullptr)
      {
        if (is_skipws)
        {
          in >> std::skipws;
        }
        free(arr);
        return nullptr;
      }
      for (size_t i = 0; i < size; ++i)
      {
        temp[i] = arr[i];
      }
      temp[size] = symb;

      free(arr);
      arr = temp;
      ++size;
    }
    arr[size - 1] = 0;
  }
  if (is_skipws)
  {
    in >> std::skipws;
  }
  return arr;
}

size_t haliullin::DIF_LAT(const char *arr, size_t str_size)
{
  size_t count = 0;
  size_t ind = 0;
  char symb = '\0';
  bool info[26] = {};
  for (size_t i = 0; i < str_size; ++i)
  {
    symb = char(std::tolower(arr[i]));
    if (symb >= 'a' && symb <= 'z')
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

char *haliullin::RMV_VOW(char *new_arr, const char *arr, size_t str_size)
{
  size_t ind = 0;
  char symb = '\0';
  for (size_t i = 0; i < str_size; ++i)
  {
    symb = char(std::tolower(arr[i]));
    if (!isVowel(symb))
    {
      new_arr[ind] = arr[i];
      ++ind;
    }
  }
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

size_t haliullin::sizeWithoutVowels(const char *arr, size_t str_size)
{
  size_t count = 0;
  char symb = '\0';
  for (size_t i = 0; i < str_size; ++i)
  {
    symb = char(std::tolower(arr[i]));
    if (!isVowel(symb))
    {
      ++count;
    }
  }
  return count;
}

void haliullin::writeString(const char *arr, size_t str_size)
{
  for (size_t i = 0; i < str_size; ++i)
  {
    std::cout << arr[i];
  }
  std::cout << "\n";
}
