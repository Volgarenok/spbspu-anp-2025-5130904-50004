#include "string_functions.hpp"
#include <iostream>
#include <new>

int main()
{
  try
  {
    char* input_str = kuchukbaeva::readStr(std::cin);
    const size_t len = kuchukbaeva::strLen(input_str);
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

