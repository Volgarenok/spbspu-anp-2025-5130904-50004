#include "strings.hpp"
#include <iostream>
char * khairullin::delete_vowels(const char * str, char * str_without_vowels)
{
  size_t counter = 0;
  const char * vowels = "AaoOiIuUeEyY";
  for (const char * copy1 = str; *copy1 != '\0'; copy1++)
  {
    const char * copy2 = vowels;
    for (; *copy2 != '\0'; copy2++)
    {
      if (*copy1 == *copy2)
      {
        break;
      }
    }
    if (*copy2 == '\0')
    {
      str_without_vowels[counter] = *copy1;
      counter++;
    }
  }
  str_without_vowels[counter++] = '\0';
  return str_without_vowels;
}
