#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iosfwd>
#include <cstddef>

namespace aydogan
{
  std::istream& readMatrix(std::istream& input, int* arr, size_t count);
  int numColLsr(size_t r, size_t c, const int* a);
  long long minSumMDG(size_t r, size_t c, const int* a);
}

#endif
