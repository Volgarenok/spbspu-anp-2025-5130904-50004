#ifndef MATRIX_ACTIONS_HPP
#define MATRIX_ACTIONS_HPP

#include <iostream>
#include <cstddef>

namespace chadin
{
  std::istream& readArr(std::istream& input, int* arr, size_t rows, size_t cols);
  std::ostream& writeArr(std::ostream& output, const int* arr, size_t rows, size_t cols);
  void increaseElements(int* arr, size_t rows, size_t cols);
  int countDiagonals(const int* arr, size_t rows, size_t cols);
}

#endif
