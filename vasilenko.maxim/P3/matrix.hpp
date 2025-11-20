#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

namespace vasilenko
{
  int countColsNsm(const int* matrix, size_t rows, size_t cols);
  int maxSumSdg(const int* matrix, size_t rows, size_t cols);
  void inputMatrix(std::istream& in, int* matrix, const size_t size);
}

#endif
