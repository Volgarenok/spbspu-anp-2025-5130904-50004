#ifndef MATRIX_FUNCTIONS_HPP
#define MATRIX_FUNCTIONS_HPP
#include <cstddef>
#include <iosfwd>

namespace kuchukbaeva
{
  bool cntLocMax(const int* matrix, size_t rows, size_t cols, size_t i, size_t j);
  size_t countLocMax(const int* matrix, size_t rows, size_t cols);
  void lftBotClk(int* matrix, size_t rows, size_t cols);
  size_t readMatrix(std::istream& in, int* matrix, size_t rows, size_t cols);
  void writeMatrix(std::ostream& out, const int* matrix, size_t rows, size_t cols);
}

#endif

