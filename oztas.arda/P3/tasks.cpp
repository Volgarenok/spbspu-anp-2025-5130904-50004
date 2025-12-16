#include "tasks.hpp"

namespace oztas
{
  int countNonZeroDiagonals(const int matrix[][MAX], int rows, int cols)
  {
    int result = 0;

    const int minOffset = -rows + 1;
    const int maxOffset = cols - 1;

    for (int offset = minOffset; offset <= maxOffset; ++offset) {
      bool hasElement = false;
      bool allNonZero = true;

      for (int i = 0; i < rows; ++i) {
        const int j = i + offset;
        if (j < 0 || j >= cols) {
          continue;
        }

        hasElement = true;
        if (matrix[i][j] == 0) {
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

  void applyFillIncreasingWave(int* matrix, int rows, int cols)
  {
    int value = 1;
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
      for (int j = left; j < right; ++j) {
        matrix[top * cols + j] = value++;
      }
      top++;

      for (int i = top; i <= bottom; ++i) {
        matrix[i * cols + right] = value++;
      }
      right--;

      if (top <= bottom) {
        for (int j = right; j >= left; --j) {
          matrix[bottom * cols + j] = value++;
        }
        bottom--;
      }

      if (left <= right) {
        for (int i = bottom; i >= top; --i) {
          matrix[i * cols + left] = value++;
        }
        left++;
      }
    }
  }
}
