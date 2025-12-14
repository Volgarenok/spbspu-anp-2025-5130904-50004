#include <iostream>
#include "strings.hpp"

char * khairullin::unique_str(char * str1, const char * str2, char * str_unique)
{
  size_t counter = 0;
  size_t size1 = 0;
  bool flag = false;
  while (*str1 != '\0')
  {
    size_t size2 = 0;
    while (*str2 != '\0')
    {
      if (*str2 == *str1)
      {
        flag = true;
      }
      str2++;
      size2++;
    }
    if (!flag and *str1 != ' ')
    {
      str_unique[counter] = *str1;
      counter++;
    }
    flag = false;
    str1++;
    size1++;
    str2 = str2 - size2;
  }
  str1 = str1 - size1;
  while (*str2 != '\0')
  {
    size_t c = 0;
    while (*str1 != '\0')
    {
      if (*str1 == *str2)
      {
        flag = true;
      }
      str1++;
      c++;
    }
    if (!flag and *str2 != ' ')
    {
      str_unique[counter] = *str2;
      counter++;
    }
    flag = false;
    str2++;
    str1 = str1 - c;
  }
  str_unique[counter++] = '\0';
  return str_unique;
}
