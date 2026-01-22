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

  size_t size1 = 0;
  size_t size2 = 0;
  while (str1[size1] != '\0')
  {
    size1++;
  }
  while (str2[size2] != '\0')
  {
    size2++;
  }

  try
  {
    str_unified = new char[size1 + size2];
  }
  catch (const std::exception& msg)
  {
    std::cerr << msg.what();
    delete[] str1;
    delete[] str_unified;
    return 1;
  }

  size_t distinct_count = dolenko::dif_lat(str1);
  std::cout << distinct_count << "\n";

  return 0;
}