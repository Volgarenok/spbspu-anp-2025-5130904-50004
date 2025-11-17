#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <cstddef>
#include <iosfwd>

namespace kuchukbaeva
{
  bool CntLocMax(const int* matrix, size_t rows, size_t cols, size_t i, size_t j);
  int countLocMax(const int* matrix, size_t rows, size_t cols);
  void LftBotClk(int* matrix, size_t rows, size_t cols);
  std::istream& readMatrix(std::istream& in, int* matrix, size_t rows, size_t cols);
  std::ostream& writeMatrix(std::ostream& out, const int* matrix, size_t rows, size_t cols, int locMaxCount);
}

#endif


