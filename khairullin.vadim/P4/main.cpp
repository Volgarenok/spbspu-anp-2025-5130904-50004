#include <iostream>
#include "strings.hpp"

int main()
{
  char * str1 = nullptr;
  char * str_unique = nullptr;
  char * str_without_vowels = nullptr;
  const char * str2 = "For example";
  try
  {
    str1  = khairullin::getline(std::cin, str1);
    if (*str1 == '\0')
    {
      std::cerr << "No string\n";
      delete [] str1;
      return 1;
    }
    size_t size1 = 0;
    size_t size2 = 0;
    while (*str1 != '\0')
    {
      str1++;
      size1++;
    }
    while (*str2 != '\0')
    {
      size2++;
      str2++;
    }
    str1 -= size1;
    str2 -= size2;

    str_without_vowels = new char[size1];
    str_unique = new char[size1 + size2];
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
  str_unique = khairullin::unique_str(str1, str2, str_unique);
  str_without_vowels = khairullin::delete_vowels(str1, str_without_vowels);
  std::cout << str_without_vowels << "\n" << str_unique << "\n";
  delete [] str1;
  delete [] str_unique;
  delete [] str_without_vowels;
}
