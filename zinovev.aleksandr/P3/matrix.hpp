#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

namespace zinovev
{
  std::istream& readInput(std::istream& input, int* array, size_t rows, size_t cols);
  void fillSpiral(int* array, size_t rows, size_t cols);
  int findLongestColumn(const int* array, size_t rows, size_t cols);
  std::ostream& writeOutput(std::ostream& output, const int* array, size_t rows, size_t cols, int result);
  void processArray(std::istream& input, std::ostream& output, int* array, size_t rows, size_t cols);
}

#endif
