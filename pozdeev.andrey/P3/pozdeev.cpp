#include "pozdeev.hpp"
#include <iostream>
#include <cctype>

namespace pozdeev
{
int countNonSequentialRows(const int* matrix, size_t rows, size_t cols)
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

void spiral(int* matrix, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0) {
    return;
  }

  size_t top = 0;
  size_t bottom = rows - 1;
  size_t left = 0;
  size_t right = cols - 1;
  int decrement = 1;

  while (top <= bottom && left <= right) {
    for (size_t i = bottom + 1; i > top; --i) {
      size_t r = i - 1;
      matrix[r * cols + left] -= decrement;
      decrement++;
    }
    left++;
    if (left > right) {
      break;
    }

    for (size_t c = left; c <= right; ++c) {
      matrix[top * cols + c] -= decrement;
      decrement++;
    }
    top++;
    if (top > bottom) {
      break;
    }

    for (size_t r = top; r <= bottom; ++r) {
      matrix[r * cols + right] -= decrement;
      decrement++;
    }
    if (right == 0) {
      break;
    }
    right--;
    if (left > right) {
      break;
    }

    for (size_t i = right + 1; i > left; --i) {
      size_t c = i - 1;
      matrix[bottom * cols + c] -= decrement;
      decrement++;
    }
    if (bottom == 0) {
      break;
    }
    bottom--;
  }
}

int numAnalysis(const char* s)
{
  if (s == nullptr || s[0] == '\0') {
    return ERROR_INVALID_FORMAT;
  }

  for (size_t i = 0; s[i] != '\0'; ++i) {
    if (!std::isdigit(s[i])) {
      return ERROR_INVALID_FORMAT;
    }
  }

  if (s[0] == '1' && s[1] == '\0') {
    return 1;
  }
  if (s[0] == '2' && s[1] == '\0') {
    return 2;
  }

  return ERROR_INVALID_VALUE;
}

int processStatic(std::ifstream& fin, std::ofstream& fout, size_t rows, size_t cols)
{
  size_t numElements = rows * cols;

  if (numElements > static_cast<size_t>(MAX_SIZE)) {
    std::cerr << "ERROR: Matrix too large for static array\n" << std::endl;
    return 2;
  }

  int staticMatrix[MAX_SIZE];
  if (numElements == 0) {
    fout << "0";
    return 0;
  }

  for (size_t i = 0; i < numElements; ++i) {
    if (!(fin >> staticMatrix[i])) {
      if (fin.eof()) {
        std::cerr << "ERROR: Not enough matrix elements\n" << std::endl;
      } else {
        std::cerr << "ERROR: Invalid matrix element\n" << std::endl;
      }
      return 2;
    }
  }

  fout << countNonSequentialRows(staticMatrix, rows, cols);
  return 0;
}

int processDynamic(std::ifstream& fin, std::ofstream& fout, size_t rows, size_t cols)
{
  size_t numElements = rows * cols;

  if (rows == 0 || cols == 0) {
    fout << "0 0";
    return 0;
  }

  int* dynamicMatrix = new (std::nothrow) int[numElements];
  if (dynamicMatrix == nullptr) {
    std::cerr << "ERROR: Memory not allocated for array\n" << std::endl;
    return 2;
  }

  for (size_t i = 0; i < numElements; ++i) {
    if (!(fin >> dynamicMatrix[i])) {
      if (fin.eof()) {
        std::cerr << "ERROR: Not enough matrix elements\n" << std::endl;
      } else {
        std::cerr << "ERROR: Invalid matrix element\n" << std::endl;
      }
      delete[] dynamicMatrix;
      return 2;
    }
  }

  spiral(dynamicMatrix, rows, cols);

  fout << rows << " " << cols;
  for (size_t i = 0; i < numElements; ++i) {
    fout << " " << dynamicMatrix[i];
  }

  delete[] dynamicMatrix;
  return 0;
}
}
