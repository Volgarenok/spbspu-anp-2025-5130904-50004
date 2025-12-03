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

  void applyFillIncreasingWave(const int matrix[][MAX], int rows, int cols);
  {
    int value = 1;
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
      // Top row (left to right)
      for (int j = left; j < right; ++j) {
        matrix[top][j] = value++;
      }
      top++;

      // Right column (top to bottom)
      for (int i = top; i <= bottom; ++i) {
        matrix[i][right] = value++;
      }
      right--;

      // Bottom row (right to left) - if rows remain
      if (top <= bottom) {
        for (int j = right; j >= left; --j) {
          matrix[bottom][j] = value++;
        }
        bottom--;
      }

      // Left column (bottom to top) - if columns remain
      if (left <= right) {
        for (int i = bottom; i >= top; --i) {
          matrix[i][left] = value++;
        }
        left++;
      }
    }
  }
}
