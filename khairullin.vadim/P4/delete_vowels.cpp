#include <iostream>
#include "strings.hpp"

char * khairullin::delete_vowels(char * str, char * str_without_vowels)
{
  bool flag = false;
  size_t counter = 0;
  const char * vowels = "AaoOiIuUeEyY";
  while (*str != '\0')
  {
    size_t c = 0;
    while (*vowels != '\0')
    {
      if (*str == *vowels)
      {
        flag = true;
      }
      vowels++;
      c++;
    }
    if (!flag)
    {
      str_without_vowels[counter] = *str;
      counter++;
    }
    flag = false;
    str++;
    vowels = vowels - c;
  }
  str_without_vowels[counter++] = '\0';
  return str_without_vowels;
}
