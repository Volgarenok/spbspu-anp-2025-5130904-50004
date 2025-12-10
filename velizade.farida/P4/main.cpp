#include "string_operations.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>

int main()
{
  const size_t size = 1000;
  char* input = velizade::read_string(std::cin, size);
  if (!input)
  {
    std::cerr << "Memory error" << "\n";
    return 1;
  }
  if (!input[0])
  {
    std::cerr << "Empty input" << "\n";
    free(input);
    return 1;
  }
  size_t len = strlen(input);
  char* buf1 = static_cast<char*>(malloc(len + 1));
  char* buf2 = static_cast<char*>(malloc(len + 10));
  if (!buf1 || buf2)
  {
    std::cerr << "Memory error" << "\n";
    free(input);
    if (buf1)
    {
      free(buf1);
    }
    if (buf2)
    {
    free(buf2);
    }
    return 1;
  }
  if (velizade::rep_sym(buf1, input) != 0)
  {
    std::cerr << "REP_SYM faild" << "\n";
    free(input);
    free(buf1);
    free(buf2);
    return 1;
  }
  if (velizade::uni_two(buf2, input, "def_") != 0)
  {
    std::cerr << "UNI_TWO failed" << "\n";
    free(input);
    free(buf1);
    free(buf2);
    return 1;
  }
  velizade::print_string(std::cout, buf1);
  std::cout << "\n";
  velizade::print_string(std::cout, buf2);
  std::cout << "\n";
  free(input);
  free(buf1);
  free(buf2);
  return 0;
}
