#include "matrix.hpp"
#include <istream>
#include <ostream>

bool oztas::readMatrix(std::istream& input,
                       int matrix[],
                       int rows,
                       int cols)
{
  if (rows < 0 || cols < 0) {
    return false;
  }

  if (rows == 0 || cols == 0) {
    return true;
  }

  const size_t srows = static_cast< size_t >(rows);
  const size_t scols = static_cast< size_t >(cols);

  for (size_t i = 0; i < srows; ++i) {
    for (size_t j = 0; j < scols; ++j) {
      if (!(input >> matrix[i * scols + j])) {
        return false;
      }
    }
  }

  return true;
}

void oztas::writeMatrix(std::ostream& output,
                        const int matrix[],
                        int rows,
                        int cols)
{
  output << rows << " " << cols;

  const size_t srows = static_cast< size_t >(rows);
  const size_t scols = static_cast< size_t >(cols);

  for (size_t i = 0; i < srows; ++i) {
    for (size_t j = 0; j < scols; ++j) {
      output << " " << matrix[i * scols + j];
    }
  }
}
