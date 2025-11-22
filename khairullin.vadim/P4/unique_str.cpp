#include <iostream>
#include "khairullin.hpp"

namespace khairullin
{
  void unique_str(const char * str1, const char * str2, size_t size1, const size_t size2)
  {
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
        std::cout << str1[i];
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
        std::cout << str2[i];
      }
      flag = false;
    }
    std::cout << "\n";
  }
}
