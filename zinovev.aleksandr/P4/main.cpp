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

  zinovev::printLine(std::cout, arr, size);
  std::cout << "\n";

  size_t size_ptr = 0;
  char* arr_ptr = static_cast< char* >(malloc((size - number_of_letters) * sizeof(char)));

  if (arr_ptr == nullptr)
  {
    free(arr);
    return 1;
  }

  zinovev::cutLetters(arr, arr_ptr, size, size_ptr);
  zinovev::printLine(std::cout, arr_ptr, size_ptr);
  std::cout << "\n" << zinovev::getRepetitions(arr, size) << "\n";

  free(arr);
  free(arr_ptr);

  return 0;
}
