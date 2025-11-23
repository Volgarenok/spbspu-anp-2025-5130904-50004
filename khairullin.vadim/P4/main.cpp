#include <iostream>
#include "khairullin.hpp"

int main()
{
  char * str1 = nullptr;
  size_t size1 = 0;
  const size_t size2 = 11;
  const char str2[size2] = {'F', 'o', 'r', 'e', 'x', 'a', 'm', 'p', 'l', 'e', '\0'};
  try
  {
    bool is_skipws = std::cin.flags() & std::ios_base::skipws;
    if (is_skipws)
    {
      std::cin >> std::noskipws;
    }
    size1 = khairullin::getline(std::cin, str1, size1);
    if (is_skipws)
    {
      std::cin >> std::skipws;
    }
    std::cout << size1 << "\n";
    if (size1 == 0)
    {
      std::cerr << "No string\n";
      return 1;
    }
    else
    {
    khairullin::unique_str(str1, str2, size1, size2);
    khairullin::delete_vowels(str1, size1);
    delete [] str1;
    }
  }
  catch (std::exception & msg)
  {
    std::cerr << msg.what();
    delete [] str1;
    return 1;
  }
}
