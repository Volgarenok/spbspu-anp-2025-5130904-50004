#include <iostream>
#include "string.hpp"

int main()
{
  size_t size = 0;
  char* str = nullptr;
  const char* str2 = "abc";
  try {
    str = bychkovskaya::getline(std::cin, size);
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
  char* result = bychkovskaya::create(size);
  if (result == nullptr) {
    std::cerr << "Not enough memory" << "\n";
    free(str);
    return 1;
  }
  bychkovskaya::latrmv(str, result);
  std::cout << result << "\n";
  free(result);
  char* result2 = bychkovskaya::create(size);
  if (result2 == nullptr) {
    std::cerr << "Not enough memory";
    free(str);
    return 1;
  }
  bychkovskaya::excsnd(str, str2, result2);
  std::cout << result2 << "\n";
  free(str);
  free(result2);
  return 0;
}
