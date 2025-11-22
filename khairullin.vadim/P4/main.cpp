#include <iostream>
#include "khairullin.hpp"

int main()
{
  char * str1 = nullptr;
  try
  {
    size_t size1 = 0;
    size1 = khairullin::getline(std::cin, str1, size1);
    const size_t size2 = 11;
    const char str2[size2] = {'F', 'o', 'r', 'e', 'x', 'a', 'm', 'p', 'l', 'e', '\0'};
    khairullin::unique_str(str1, str2, size1, size2);
    khairullin::delete_vowels(str1, size1);
    delete [] str1;
  }
  catch (std::exception & msg)
  {
    delete [] str1;
    std::cerr << msg.what();
    return 1;
  }
}
