#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "string_functions.hpp"
int main()
{
  namespace hal = haliullin;
  char *arr = nullptr;
  size_t size = 0;
  size_t count = 0;

  arr = hal::getline(std::cin, size);
  if (arr == nullptr)
  {
    std::cerr << "Memory allocation error" << "\n";
    return 1;
  }

  hal::writeString(arr);
  count = hal::DIF_LAT(arr);
  std::cout << count << "\n";

  char *new_arr = nullptr;
  size_t new_size = hal::sizeWithoutVowels(arr);
  new_arr = reinterpret_cast< char* >(malloc((new_size + 1) * sizeof(char)));
  if (new_arr == nullptr)
  {
    std::cerr << "Memory allocation error" << "\n";
    return 1;
  }
  new_arr = hal::RMV_VOW(new_arr, arr);
  hal::writeString(new_arr);

  free(arr);
  free(new_arr);
  return 0;
}
