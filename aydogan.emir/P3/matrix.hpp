#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iosfwd>
#include <cstddef>

namespace aydogan
{
  std::istream& readMatrix(std::istream& input, int* arr, std::size_t count);
  int numColLsr(int r, int c, const int* a);
  long long minSumMDG(int r, int c, const int* a);
}

#endif
