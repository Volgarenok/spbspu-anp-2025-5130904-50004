#include "strings.hpp"
#include <iostream>

char * khairullin::unique_str(const char * str1, const char * str2, char * str_unique)
{
  size_t counter = 0;
  for (const char * copy1 = str1; *copy1 != '\0'; copy1++)
  {
    const char * copy2 = str2;
    for (; *copy2 != '\0'; copy2++)
    {
      if (*copy1 == *copy2)
      {
        break;
      }
    }
    if (*copy2 == '\0' && *copy1 != ' ')
    {
      str_unique[counter] = *copy1;
      counter++;
    }
  }
  for (const char * copy2 = str2; *copy2 != '\0'; copy2++)
  {
    const char * copy1 = str1;
    for (; *copy1 != '\0'; copy1++)
    {
      if (*copy2 == *copy1)
      {
        break;
      }
    }
    if (*copy1 == '\0' && *copy2 != ' ')
    {
      str_unique[counter] = *copy2;
      counter++;
    }
  }
  str_unique[counter++] = '\0';
  return str_unique;
}
