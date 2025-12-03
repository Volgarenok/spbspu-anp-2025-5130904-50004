#ifndef OZTAS_T3_MATRIX_HPP
#define OZTAS_T3_MATRIX_HPP

#include <iosfwd>

namespace oztas
{
  bool readMatrix(std::istream& input, int**& matrix, int& rows, int& cols);

  void writeMatrix(std::ostream& output, int* const* matrix, int rows, int cols);

  void freeMatrix(int** matrix, int rows);
}

#endif

