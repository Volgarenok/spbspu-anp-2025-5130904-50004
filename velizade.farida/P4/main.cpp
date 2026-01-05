#include "string_operations.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>

int main()
{
  char* data = velizade::read_string(std::cin, size);
  if (!data)
  {
    std::cerr << "Memory error" << "\n";
    return 1;
  }
  if (!data[0])
  {
    std::cerr << "Empty input" << "\n";
    free(data);
    return 1;
  }
  size_t len = strlen(data);
  char* buf1 = reinterpret_cast<char*>(malloc(len + 1));
  char* buf2 = reinterpret_cast<char*>(malloc(len + 10));
  if (!buf1 || !buf2)
  {
    std::cerr << "Memory error" << "\n";
    free(data);
    free(buf1);
    free(buf2);
    return 1;
  }
  if (velizade::rep_sym(buf1, data) != 0)
  {
    std::cerr << "REP_SYM faild" << "\n";
    free(data);
    free(buf1);
    free(buf2);
    return 1;
  }
  if (velizade::uni_two(buf2, data, "def_") != 0)
  {
    std::cerr << "UNI_TWO failed" << "\n";
    free(data);
    free(buf1);
    free(buf2);
    return 1;
  }
  std::cout << buf1 << "\n";
  std::cout << buf2 << "\n";
  free(data);
  free(buf1);
  free(buf2);
  return 0;
}
