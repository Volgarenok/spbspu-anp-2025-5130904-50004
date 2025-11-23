#ifndef LAB_HPP
#define LAB_HPP
#include <iosfwd>

namespace aydogan
{
  std::istream & readMatrix(std::istream & input, int * arr, int count);
  int numCollSr(int r, int c, const int * a);
  long long minSumMDG(int r, int c, const int * a);
  int processMatrix(int r, int c, const int * a, int variant);
}

#endif
