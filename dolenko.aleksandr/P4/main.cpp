#include <iostream>
#include "strings.hpp"

int main()
{
  char* str1 = nullptr;
  char* str_unified = nullptr;
  const char* str2 = "def_";

  try
  {
    str1 = dolenko::getline(std::cin, str1);
  }
  catch (const std::bad_alloc& error)
  {
    std::cerr << error.what();
    return 1;
  }

  if (!str1 || str1[0] == '\0')
  {
    std::cerr << "Missing string\n";
    delete[] str1;
    return 1;
  }

  return 0;
}