#include <iostream>
#include "khairullin.hpp"

namespace khairullin
{
  void delete_vowels(char * str, size_t size)
  {
    bool flag = false;
    const size_t count_vowels = 12;
    char vowels[count_vowels] = {'A', 'a', 'o', 'O', 'i', 'I', 'u', 'U', 'e', 'E', 'y', 'Y'};
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
        std::cout << str[i];
      }
      flag = false;
    }
    std::cout << "\n";
  }
}
