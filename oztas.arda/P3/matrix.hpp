#ifndef OZTAS_T3_MATRIX_HPP
#define OZTAS_T3_MATRIX_HPP

#include <iosfwd>

namespace oztas
{
  const int MAX = 256;

  bool readMatrix(std::istream& input, int matrix[][MAX], int& rows, int& cols);

  void writeMatrix(std::ostream& output, const int matrix[][MAX], int rows, int cols);

  void freeMatrix(int** matrix, int rows);
}

#endif
