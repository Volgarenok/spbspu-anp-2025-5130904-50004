#include "tasks.hpp"

int oztas::countNonZeroDiagonals(const int* matrix, size_t rows, size_t cols) {
  int result = 0;

  const int minOffset = -static_cast<int>(rows) + 1;  // int'e çevir
  const int maxOffset = static_cast<int>(cols) - 1;   // int'e çevir

  for (int offset = minOffset; offset <= maxOffset; ++offset) {
    bool hasElement = false;
    bool allNonZero = true;

    for (size_t i = 0; i < rows; ++i) {
      const int j = static_cast<int>(i) + offset;  // int'e çevir
      if (j < 0 || j >= static_cast<int>(cols)) {
        continue;
      }

      hasElement = true;
      if (matrix[i * cols + static_cast<size_t>(j)] == 0) {
        allNonZero = false;
        break;
      }
    }

    if (hasElement && allNonZero) {
      ++result;
    }
  }

  return result;
}

void oztas::applyFillIncreasingWave(int* matrix, size_t rows, size_t cols) {
  int value = 1;

  size_t top = 0;
  size_t bottom = rows - 1;
  size_t left = 0;
  size_t right = cols - 1;

  while (top <= bottom && left <= right) {
    for (size_t j = left; j < right; ++j) {
      matrix[top * cols + j] = value++;
    }
    top++;

    for (size_t i = top; i <= bottom; ++i) {
      matrix[i * cols + right] = value++;
    }
    right--;

    if (top <= bottom) {
      for (size_t j = right + 1; j > left; --j) {
        matrix[bottom * cols + j - 1] = value++;
      }
      bottom--;
    }

    if (left <= right) {
      for (size_t i = bottom + 1; i > top; --i) {
        matrix[(i - 1) * cols + left] = value++;
      }
      left++;
    }
  }
}
