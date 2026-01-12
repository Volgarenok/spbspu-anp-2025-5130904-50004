#include <iostream>
#include "string.hpp"

int main()
{
  size_t size = 0;
  char* str = nullptr;
  const char* str2 = "abc";
  str = bychkovskaya::getline(std::cin, size);
  if (std::cin.eof() || std::cin.bad()) {
    free(str);
    std::cerr << "Input failed" << "\n";
    return 1;
  }
  if (str == nullptr) {
    std::cerr << "Not enough memory" << "\n";
    return 1;
  }
  char* result = reinterpret_cast< char* >(malloc(sizeof(char) * size));
  if (result == nullptr) {
    std::cerr << "Not enough memory" << "\n";
    free(str);
    return 1;
  }
  bychkovskaya::latrmv(str, result);
  std::cout << result << "\n";
  free(result);
  char* result2 = reinterpret_cast< char* >(malloc(sizeof(char) * size));
  if (result2 == nullptr) {
    std::cerr << "Not enough memory" << "\n";
    free(str);
    return 1;
  }
  bychkovskaya::excsnd(str, str2, result2);
  std::cout << result2 << "\n";
  free(str);
  free(result2);
  return 0;
}
