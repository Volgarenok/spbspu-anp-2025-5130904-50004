#ifndef OZTAS_T3_MATRIX_HPP
#define OZTAS_T3_MATRIX_HPP

#include <iosfwd>
#include <cstddef>

namespace oztas
{
  bool readMatrix(std::istream& input, int matrix[], size_t rows, size_t cols);

  void writeMatrix(std::ostream& output, const int matrix[], size_t rows, size_t cols);
}

#endif
