#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iosfwd>

namespace aydogan
{
  std::istream& readMatrix(std::istream& input, int* arr, int count);
  int numColLsr(int r, int c, const int* a);
  long long minSumMDG(int r, int c, const int* a);
}

#endif