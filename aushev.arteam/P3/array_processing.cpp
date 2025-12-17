#include "array_processing.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

namespace aushev {

int isLowerTriangularMatrix(const int* matrix, int rows, int cols) {
  for (size_t i = 0; i < static_cast<size_t>(rows); ++i) {
    for (size_t j = i + 1; j < static_cast<size_t>(cols); ++j) {
      if (matrix[i * cols + j] != 0) {
        return 0;
      }
    }
  }
  return 1;
}

int countLocalMaxima(const int* matrix, int rows, int cols) {
  if (rows < 3 || cols < 3) {
    return 0;
  }

  int count = 0;
  for (size_t i = 1; i < static_cast<size_t>(rows) - 1; ++i) {
    for (size_t j = 1; j < static_cast<size_t>(cols) - 1; ++j) {
      int current = matrix[i * cols + j];
      int isMax = 1;

      for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
          if (di == 0 && dj == 0) continue;
          size_t ni = i + static_cast<size_t>(di);
          size_t nj = j + static_cast<size_t>(dj);
          if (matrix[ni * cols + nj] >= current) {
            isMax = 0;
            break;
          }
        }
        if (!isMax) break;
      }

      if (isMax) {
        ++count;
      }
    }
  }
  return count;
}

void processFixedArray(std::ifstream& input, std::ofstream& output) {
  int rows = 0, cols = 0;
  if (!(input >> rows >> cols)) {
    throw "Invalid matrix dimensions";
  }
  if (rows < 0 || cols < 0) {
    throw "Invalid matrix dimensions";
  }
  if ((rows == 0 && cols > 0) || (rows > 0 && cols == 0)) {
    throw "Invalid matrix dimensions";
  }
  if (rows == 0 && cols == 0) {
    output << "true\n";
    return;
  }

  const int MAX_SIZE = 10000;
  if (static_cast<long long>(rows) * cols > MAX_SIZE) {
    throw "Matrix size exceeds maximum allowed";
  }
  const int MAX_DIM = 100;
  if (rows > MAX_DIM || cols > MAX_DIM) {
    throw "Matrix dimensions exceed fixed array limits";
  }

  int fixedMatrix[MAX_DIM][MAX_DIM] = {};
  for (size_t i = 0; i < static_cast<size_t>(rows); ++i) {
    for (size_t j = 0; j < static_cast<size_t>(cols); ++j) {
      if (!(input >> fixedMatrix[i][j])) {
        throw "Invalid matrix element";
      }
    }
  }

  int result = isLowerTriangularMatrix(&fixedMatrix[0][0], rows, cols);
  output << (result ? "true" : "false") << "\n";
}

void processDynamicArray(std::ifstream& input, std::ofstream& output) {
  int rows = 0, cols = 0;
  if (!(input >> rows >> cols)) {
    throw "Invalid matrix dimensions";
  }
  if (rows < 0 || cols < 0) {
    throw "Invalid matrix dimensions";
  }
  if ((rows == 0 && cols > 0) || (rows > 0 && cols == 0)) {
    throw "Invalid matrix dimensions";
  }
  if (rows == 0 && cols == 0) {
    output << "0\n";
    return;
  }

  int* matrix = static_cast<int*>(malloc(rows * cols * sizeof(int)));
  if (!matrix) {
    throw "Memory allocation failed";
  }

  for (size_t i = 0; i < static_cast<size_t>(rows); ++i) {
    for (size_t j = 0; j < static_cast<size_t>(cols); ++j) {
      if (!(input >> matrix[i * cols + j])) {
        free(matrix);
        throw "Invalid matrix element";
      }
    }
  }

  int result = countLocalMaxima(matrix, rows, cols);
  free(matrix);
  output << result << "\n";
}

} 