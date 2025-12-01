#include "string_functions.hpp"
#include <iostream>
#include <new>

int main()
{
  try
  {
    size_t len = 0;
    char* input_str = kuchukbaeva::readStr(std::cin, len);
    if (input_str == nullptr)
    {
      std::cerr << "Empty input" << "\n";
      return 1;
    }
    char* res_str = new char[len + 1];
    kuchukbaeva::rmvVow(input_str, res_str);
    std::cout << res_str << "\n";
    int repeatdig = kuchukbaeva::repDgt(input_str);
    std::cout << repeatdig << "\n";
    delete[] input_str;
    delete[] res_str;
    return 0;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation failed (" << e.what() << ")" << "\n";
    return 1;
  }
}

