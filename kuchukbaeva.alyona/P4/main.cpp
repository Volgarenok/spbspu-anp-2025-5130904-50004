#include "string_functions.hpp"
#include <iostream>
#include <new>

int main()
{
  char* input_str = nullptr;
  char* res_str = nullptr;
  try
  {
    size_t len = 0;
    input_str = kuchukbaeva::readStr(std::cin, len);
    if (len == 0 && std::cin.eof())
    {
      std::cerr << "Troubles with input" << "\n";
      delete[] input_str;
      return 1;
    }
    res_str = new char[len + 1];
    kuchukbaeva::rmvVow(input_str, res_str);
    std::cout << res_str << "\n";
    int repeat_digit = kuchukbaeva::repDgt(input_str);
    std::cout << repeat_digit << "\n";
    delete[] res_str;
    delete[] input_str;
  }
  catch (const std::bad_alloc& e)
  {
    delete[] input_str;
    delete[] res_str;
    std::cerr << "Troubles with memory: " << e.what() << "\n";
    return 1;
  }
  return 0;
}
