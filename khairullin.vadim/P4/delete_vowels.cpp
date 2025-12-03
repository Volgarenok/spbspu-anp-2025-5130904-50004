#include <iostream>
#include "functions.hpp"

char * khairullin::delete_vowels(char * str, size_t size, char * str_without_vowels)
{
  bool flag = false;
  size_t counter = 0;
  const size_t count_vowels = 12;
  char vowels[] = "AaoOiIuUeEyY";
  for (size_t i = 0; i < size; ++i)
  {
    for (size_t j = 0; j < count_vowels; ++j)
    {
      if (str[i] == vowels[j])
      {
        flag = true;
      }
    }
    if (!flag)
    {
      str_without_vowels[counter] = str[i];
      counter++;
    }
    flag = false;
  }
  str_without_vowels[counter++] = '\0';
  return str_without_vowels;
}
