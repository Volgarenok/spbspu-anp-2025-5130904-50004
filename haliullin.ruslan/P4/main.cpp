#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "line.hpp"
int main()
{
  namespace hal = haliullin;
  size_t size = 0;
  size_t count = 0;

  char *arr = hal::getline(std::cin, '\n', size);

  if (arr == nullptr)
  {
    std::cerr << "Memory allocation error" << "\n";
    return 1;
  }
  if (size == 0)
  {
    std::cerr << "Empty input" << "\n";
    free(arr);
    return 1;
  }

  std::cout << "\n";
  std::cout << arr << "\n";
  count = hal::DIF_LAT(arr);
  std::cout << count << "\n";

  size_t new_size = hal::sizeWithoutVowels(arr);
  char *new_arr = reinterpret_cast< char* >(malloc((new_size + 1) * sizeof(char)));
  if (new_arr == nullptr)
  {
    std::cerr << "Memory allocation error" << "\n";
    free(arr);
    return 1;
  }
  new_arr = hal::RMV_VOW(new_arr, arr);
  std::cout << new_arr << "\n";

  free(arr);
  free(new_arr);
  return 0;
}
