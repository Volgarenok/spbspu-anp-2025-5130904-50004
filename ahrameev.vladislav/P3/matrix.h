#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>

namespace ahrameev
{
  bool is_upper_triangular(const int* matrix, size_t rows, size_t cols);
  void build_spiral(const int* src, int* dst, size_t rows, size_t cols);
}

#endif
