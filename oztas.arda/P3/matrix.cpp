#include "matrix.hpp"
#include <istream>
#include <ostream>

bool oztas::readMatrix(std::istream& input,
                       int matrix[],
                       size_t rows,
                       size_t cols)
{
  if (rows == 0 || cols == 0) {
    return true;
  }

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (!(input >> matrix[i * cols + j])) {
        return false;
      }
    }
  }

  return true;
}

void oztas::writeMatrix(std::ostream& output,
                        const int matrix[],
                        size_t rows,
                        size_t cols)
{
  output << rows << " " << cols;

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      output << " " << matrix[i * cols + j];
    }
  }
}
