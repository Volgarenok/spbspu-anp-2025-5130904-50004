#include <iostream>
#include "functions.hpp"

int main()
{
  char * str1 = nullptr;
  char * str_unique = nullptr;
  char * str_without_vowels = nullptr;
  size_t realsize = 0;
  const size_t size2 = 11;
  const char str2[] = "For example";
  try
  {
    str1  = khairullin::getline(std::cin, str1, realsize);
    if (realsize == 0)
    {
      std::cerr << "No string\n";
      delete [] str1;
      return 1;
    }
    str_without_vowels = new char[realsize + 1];
    str_unique = new char[realsize + size2 + 1];
    str_unique = khairullin::unique_str(str1, str2, realsize, size2, str_unique);
    str_without_vowels = khairullin::delete_vowels(str1, realsize, str_without_vowels);
    std::cout << str_without_vowels << "\n" << str_unique << "\n";
    delete [] str1;
    delete [] str_unique;
    delete [] str_without_vowels;
  }
  catch (std::exception & msg)
  {
    std::cerr << msg.what();
    if (str1)
    {
      delete [] str1;
    }
    else if (str_unique)
    {
      delete [] str1;
      delete [] str_unique;
    }
    else
    {
      delete [] str1;
      delete [] str_unique;
      delete [] str_without_vowels;
    }
    return 1;
  }
}
