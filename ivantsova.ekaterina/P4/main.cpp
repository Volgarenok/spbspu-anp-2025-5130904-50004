#include "functions_for_strings.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
  size_t size = 0;
  char * input_str = ivantsova::readLine(std::cin, size);
  if (input_str == nullptr)
  {
    std::cerr << "Memory allocation error" << "\n";
    return 1;
  }
  if (size == 0)
  {
    std::cerr << "Empty input" << "\n";
    free(input_str);
    return 1;
  }

  const char * second_str_for_ils = "def ";
  size_t ils_size = 0;
  while (second_str_for_ils[ils_size] != '\0')
  {
    ++ils_size;
  }
  size_t result_for_ils_size = size + ils_size;
  char * result_for_ils = reinterpret_cast<char *>(malloc((result_for_ils_size + 1) * sizeof(char)));
  if (result_for_ils == nullptr)
  {
    std::cerr << "Memory allocation error" << "\n";
    free(input_str);
    return 1;
  }
  const char * ils_result = ivantsova::interleaveStrings(input_str, second_str_for_ils, result_for_ils);
  std::cout << ils_result << "\n";
  const char * second_str_for_ad = "g1h2k";
  size_t ad_size = 0;
  while (second_str_for_ad[ad_size] != '\0')
  {
    ++ad_size;
  }
  size_t result_for_ad_size = size + ad_size;
  char * result_for_ad = reinterpret_cast<char *>(malloc((result_for_ad_size + 1) * sizeof(char)));
  if (result_for_ad == nullptr)
  {
    std::cerr << "Memory allocation error" << "\n";
    free(input_str);
    free(result_for_ils);
    return 1;
  }
  size_t actual_result_for_ad_size = 0;
  const char * ad_result = ivantsova::addDigits(input_str, second_str_for_ad, result_for_ad, &actual_result_for_ad_size);
  std::cout << ad_result << "\n";
  free(input_str);
  free(result_for_ils);
  free(result_for_ad);
  return 0;
}
