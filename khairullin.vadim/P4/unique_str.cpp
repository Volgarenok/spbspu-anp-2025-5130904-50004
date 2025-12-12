#include <iostream>
#include "functions.hpp"

char * khairullin::unique_str(char * str1, const char * str2, size_t size1, const size_t size2, char * str_unique)
{
  size_t counter = 0;
  bool flag = false;
  for (size_t i = 0; i < size1; ++i)
  {
    for (size_t j = 0; j < size2; ++j)
    {
      if (str2[j] == str1[i])
      {
        flag = true;
      }
    }
    if (!flag and str1[i] != ' ')
    {
      str_unique[counter] = str1[i];
      counter++;
    }
    flag = false;
  }
  for (size_t i = 0; i < size2; ++i)
  {
    for (size_t j = 0; j < size1; ++j)
    {
      if (str1[j] == str2[i])
      {
        flag = true;
      }
    }
    if (!flag and str2[i] != ' ')
    {
      str_unique[counter] = str2[i];
      counter++;
    }
    flag = false;
  }
  str_unique[counter++] = '\0';
  return str_unique;
}
