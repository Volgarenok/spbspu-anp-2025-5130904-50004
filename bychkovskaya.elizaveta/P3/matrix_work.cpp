#include <fstream>
#include <cctype>
#include "matrix_work.hpp"

bool bychkovskaya::ifNumber(char* m)
{
  size_t k = 0;
  size_t k1 = 0;
  for (size_t i = 0; m[i]!='\0'; ++i) {
    if (isdigit(m[i])) {
      ++k;
    }
    ++k1;
  }
  if (k == k1) {
    return true;
  }
  return false;
}

int* bychkovskaya::create(size_t rows, size_t cols)
{
  int* result = nullptr;
  try {
    result = new int [rows * cols];
  } catch (const std::bad_alloc& e) {
    throw std::runtime_error("Not enough memory");
  }
  return result;
}

std::ifstream& bychkovskaya::inputMatrix(std::ifstream& in, int* m, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      in >> m[i * cols + j];
      if (!in) {
        throw std::invalid_argument("Wrong matrix input");
      }
    }
  }
  return in;
}

size_t bychkovskaya::cntColNsm(const int* m, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t j = 0; j < cols; ++j) {
    size_t countCol = 0;
    for (size_t i = 0; i < rows-1; ++i) {
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
  } else if (rows < cols) {
    cols = rows;
  }
  size_t count = 0;
  int k = -int(rows) + 1;
  while (k < int(rows)) {
    size_t countDiag = 0;
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < cols; j++) {
        if (i == j) {
          if ((int(j) + k >= 0) && (int(j) + k < int(cols))) {
            if (m[i * originalCols + j + k] == 0) {
              ++countDiag;
            }
          }
        }
      }
    }
    if (countDiag == 0 && k != 0) {
      ++count;
    }
    ++k;
  }
  return count;
}

void bychkovskaya::outputMatrix(std::ofstream& out, const int* m, size_t rows, size_t cols) {
  out << bychkovskaya::cntColNsm(m, rows, cols) << "\n";
  out << bychkovskaya::cntNzrDig(m, rows, cols) << "\n";
}
