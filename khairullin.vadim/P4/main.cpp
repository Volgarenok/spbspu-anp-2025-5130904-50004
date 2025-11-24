#include <iostream>
#include "khairullin.hpp"

int main()
{
  char * str1 = nullptr;
  size_t size1 = 10;
  const size_t size2 = 11;
  const char str2[size2] = {'F', 'o', 'r', 'e', 'x', 'a', 'm', 'p', 'l', 'e', '\0'};
  try
  {
    str1 = new char [10];
    size_t realsize = 0;
    realsize = khairullin::getline(std::cin, str1, size1);
    if (realsize == 0)
    {
      std::cerr << "No string\n";
      delete [] str1;
      return 1;
    }
    khairullin::unique_str(str1, str2, realsize, size2);
    khairullin::delete_vowels(str1, realsize);
    delete [] str1;
  }
  catch (std::exception & msg)
  {
    std::cerr << msg.what();
    delete [] str1;
    return 1;
  }
}
