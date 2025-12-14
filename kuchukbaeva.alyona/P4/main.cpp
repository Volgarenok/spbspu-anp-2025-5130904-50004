#include "string_functions.hpp"
#include <iostream>
#include <new>

int main()
{
  size_t len = 0;
  char* input_str = kuchukbaeva::readStr(std::cin, len);
  if (input_str == nullptr)
  {
    std::cerr << "Empty input" << "\n";
    return 1;
  }
  char* res_str = nullptr;
  try
  {
    res_str = new char[len + 1];
  }
  catch (const std::bad_alloc& e)
  {
    delete[] input_str;
    std::cerr << "Troubles with memory: " << e.what() << "\n";
    return 1;
  }
  kuchukbaeva::rmvVow(input_str, res_str);
  std::cout << res_str << "\n";
  int repeatdig = kuchukbaeva::repDgt(input_str);
  std::cout << repeatdig << "\n";
  delete[] input_str;
  delete[] res_str;
  return 0;
}

