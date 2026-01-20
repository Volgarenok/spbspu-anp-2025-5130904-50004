#include "string_operations.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
  size_t len = 0;
  char* data = velizade::read_string(std::cin, len);
  if (!data)
  {
    std::cerr << "Memory error" << "\n";
    return 1;
  }
  if (len == 0)
  {
    std::cerr << "Empty input" << "\n";
    free(data);
    return 1;
  }
  char* result1 = velizade::rep_sym(data);
  char* result2 = velizade::uni_two(data, "def_");
  if (!result1)
  {
    std::cerr << "REP_SYM failed" << "\n";
    free(data);
    free(result2);
    return 1;
  }
  if (!result2)
  {
    std::cerr << "UNI_TWO failed" << "\n";
    free(data);
    free(result1);
    return 1;
  }
  std::cout << result1 << "\n";
  std::cout << result2 << "\n";
  free(data);
  free(result1);
  free(result2);
  return 0;
}
