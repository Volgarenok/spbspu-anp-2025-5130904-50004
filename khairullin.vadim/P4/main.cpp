#include <iostream>
#include "khairullin.hpp"
 

int main()
{
  try
  {
    size_t size1 = 0;
    char * str1 = new char [size1];
    size1 = khairullin::getline(std::cin, str1, size1);
    const size_t size2 = 11;
    char str2[size2] = {'F', 'o', 'r', 'e', 'x', 'a', 'm', 'p', 'l', 'e', '\0')}
    khairullin::unique_str(str1, str2, size1, size2);
    khairullin::delete_vowels(str1, size1);
  }
  catch (std::bad_alloc & msg)
  {
    std::cerr << msg.what();
    return 1;
  }
}
