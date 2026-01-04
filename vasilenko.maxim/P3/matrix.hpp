#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>
#include <iosfwd>

namespace vasilenko
{
  size_t countColsNsm(const int* matrix, size_t rows, size_t cols);
  int maxSumSdg(const int* matrix, size_t rows, size_t cols);
  void inputMatrix(std::istream& in, int* matrix, size_t size);
}

#endif
