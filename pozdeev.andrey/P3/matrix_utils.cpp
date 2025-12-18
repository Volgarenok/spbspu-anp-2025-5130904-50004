#include "matrix_utils.hpp"
#include <cctype>
#include <stdexcept>
#include <iostream>

int pozdeev::countNonSequentialRows(const int * matrix, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0) {
    return 0;
  }

  int rowsWithoutConsecutive = 0;
  for (size_t r = 0; r < rows; ++r) {
    bool hasConsecutive = false;
    for (size_t c = 0; c < cols - 1; ++c) {
      if (matrix[r * cols + c] == matrix[r * cols + c + 1]) {
        hasConsecutive = true;
        break;
      }
    }
    if (!hasConsecutive) {
      rowsWithoutConsecutive++;
    }
  }
  return rowsWithoutConsecutive;
}

void pozdeev::spiral(int * matrix, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0) {
    return;
  }

  size_t minRow = 0;
  size_t maxRow = rows - 1;
  size_t minCol = 0;
  size_t maxCol = cols - 1;
  int decrement = 1;
  size_t count = 0;
  size_t total = rows * cols;

  while (count < total) {
    for (size_t r = maxRow + 1; r > minRow && count < total; --r) {
      matrix[(r - 1) * cols + minCol] -= decrement;
      decrement++;
      count++;
    }
    minCol++;

    for (size_t c = minCol; c <= maxCol && count < total; ++c) {
      matrix[minRow * cols + c] -= decrement;
      decrement++;
      count++;
    }
    minRow++;

    for (size_t r = minRow; r <= maxRow && count < total; ++r) {
      matrix[r * cols + maxCol] -= decrement;
      decrement++;
      count++;
    }
    if (maxCol == 0) {
      break;
    }
    maxCol--;

    for (size_t c = maxCol + 1; c > minCol && count < total; --c) {
      matrix[maxRow * cols + (c - 1)] -= decrement;
      decrement++;
      count++;
    }
    if (maxRow == 0) {
      break;
    }
    maxRow--;
  }
}

int pozdeev::numAnalysis(const char * s)
{
  if (s == nullptr || s[0] == '\0') {
    throw std::invalid_argument("First parameter is not a number");
  }

  for (size_t i = 0; s[i] != '\0'; ++i) {
    if (!std::isdigit(s[i])) {
      throw std::invalid_argument("First parameter is not a number");
    }
  }

  if (s[0] == '1' && s[1] == '\0') {
    return 1;
  }
  if (s[0] == '2' && s[1] == '\0') {
    return 2;
  }

  throw std::out_of_range("First parameter is out of range");
}

void pozdeev::inputMatrix(std::ifstream & in, int * matrix, size_t size)
{
  for (size_t i = 0; i < size; ++i) {
    in >> matrix[i];
  }
}

void pozdeev::outputMatrix(std::ofstream & out, const int * matrix, size_t rows, size_t cols)
{
  out << rows << " " << cols;
  const size_t size = rows * cols;
  for (size_t i = 0; i < size; ++i) {
    out << " " << matrix[i];
  }
  out << "\n";
}
