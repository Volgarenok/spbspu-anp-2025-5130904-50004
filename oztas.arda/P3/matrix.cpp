#include "matrix.hpp"

#include <cstdlib>
#include <istream>

namespace oztas
{
  namespace
  {
    int** allocateMatrix(int rows, int cols)
    {
      if (rows < 0 || cols < 0) {
        return nullptr;
      }

      // Handle empty matrix
      if (rows == 0 || cols == 0) {
        return nullptr;
      }

      int** matrix = static_cast <int**>(std::malloc(rows * sizeof(int*)));
      if (!matrix) {
        return nullptr;
      }

      for (size_t i = 0; i < static_cast<size_t>(rows); ++i) {
        matrix[i] = static_cast <int*>(std::malloc(cols * sizeof(int)));
        if (!matrix[i]) {
          for (size_t j = 0; j < i; ++j)
            std::free(matrix[j]);
          std::free(matrix);
          return nullptr;
        }
      }

      return matrix;
    }
  }

  bool readMatrix(std::istream& input,
    int matrix[][MAX],
    int& rows,
    int& cols)
  {
    if (!(input >> rows >> cols)) {
      return false;
    }

    // Check for valid dimensions
    if (rows < 0 || cols < 0) {
      return false;
    }

    // Empty matrix is valid
    if (rows == 0 || cols == 0) {
      return true;
    }

    int** tmp = allocateMatrix(rows, cols);
    if (!tmp) {
      return false;
    }

    for (size_t i = 0; i < static_cast<size_t>(rows); ++i)
      for (size_t j = 0; j < static_cast<size_t>(cols); ++j) {
        if (!(input >> tmp[i][j])) {
          freeMatrix(tmp, rows);
          return false;
        }
      }

    for (size_t i = 0; i < static_cast<size_t>(rows); ++i) {
      for (size_t j = 0; j < static_cast<size_t>(cols); ++j) {
        matrix[i][j] = tmp[i][j];
      }
    }
    freeMatrix(tmp, rows);
    return true;
  }

  void writeMatrix(std::ostream& output,
    const int matrix[][MAX],
    int rows,
    int cols)
  {
    output << rows << " " << cols;
    for (size_t i = 0; i < static_cast<size_t>(rows); ++i) {
      for (size_t j = 0; j < static_cast<size_t>(cols); ++j)
        output << " " << matrix[i][j];
    }
  }

  void freeMatrix(int** matrix, int rows)
  {
    if (!matrix) {
      return;
    }

    for (size_t i = 0; i < static_cast<size_t>(rows); ++i) {
      std::free(matrix[i]);
    }

    std::free(matrix);
  }

}
