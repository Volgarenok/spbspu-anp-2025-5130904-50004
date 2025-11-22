#include <iostream>
#include "string_operations.hpp"

int main()
{
  size_t size = 0;
  size_t number_of_letters = 0;
  char* arr = zinovev::SetLine(std::cin, size, number_of_letters);

  zinovev::GetLine(std::cout, arr, size);

  size_t size_ptr = 0;
  char* arr_ptr = (char*)malloc((size - number_of_letters) * sizeof(char));

  zinovev::CutLetters(arr, arr_ptr, size, size_ptr);
  zinovev::GetLine(std::cout, arr_ptr, size_ptr);
  std::cout << zinovev::GetRepetitions(arr, size) << "\n";

  free(arr);
  free(arr_ptr);
}
