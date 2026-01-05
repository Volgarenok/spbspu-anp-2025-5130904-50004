#include "matrix_work.hpp"
#include <fstream>
#include <cctype>

std::ifstream& bychkovskaya::inputMatrix(std::ifstream& in, int* m, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      in >> m[i * cols + j];
    }
  }
  return in;
}

size_t bychkovskaya::cntColNsm(const int* m, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t j = 0; j < cols; ++j) {
    size_t countCol = 0;
    for (size_t i = 0; i < rows - 1; ++i) {
      if (m[i * cols + j] == m[i * cols + j + cols]) {
        ++countCol;
      }
    }
    if (countCol == 0) {
      ++count;
    }
  }
  return count;
}

size_t bychkovskaya::cntNzrDig(const int* m, size_t rows, size_t cols)
{
    size_t originalCols = cols;
    if (rows > cols) {
        rows = cols;
    }
    else if (rows < cols) {
        cols = rows;
    }
    size_t count = 0;
    size_t k = 1;
    while (k < rows) {
        size_t countDiag1 = 0;
        size_t countDiag2 = 0;
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; j++) {
                if (i == j) {
                    if (j + k < cols) {
                        if (m[i * originalCols + j + k] == 0) {
                            ++countDiag1;
                        }
                    }
                    if ((j >= k) && (j < cols + k)) {
                        if (m[i * originalCols + j - k] == 0) {
                            ++countDiag2;
                        }
                    }
                }
            }
        }
        if (countDiag1 == 0) {
            ++count;
        }
        if (countDiag2 == 0) {
            ++count;
        }
        ++k;
    }
    return count;
}

