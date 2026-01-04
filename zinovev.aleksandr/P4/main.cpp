#include <iostream>
#include <cstdlib>
#include "string_operations.hpp"

int main()
{
  size_t size = 0;
  size_t number_of_letters = 0;
  char* arr = zinovev::setLine(std::cin, size, number_of_letters);

  if (arr == nullptr)
  {
    return 1;
  }

  if (size == 0)
  {
    std::cerr << "Empty input\n";
    free(arr);
    return 1;
  }

  std::cout << arr << "\n";

  size_t size_ptr = 0;
  char* arr_ptr = reinterpret_cast< char* >(malloc((size - number_of_letters + 1) * sizeof(char)));

  if (arr_ptr == nullptr)
  {
    free(arr);
    return 1;
  }

  zinovev::cutLetters(arr, arr_ptr, size_ptr);
  std::cout << arr_ptr << "\n";
  std::cout << zinovev::getRepetitions(arr) << "\n";

  free(arr);
  free(arr_ptr);

  return 0;
}
