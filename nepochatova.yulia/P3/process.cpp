#include "io.h"

void nepochatova::transformMatrixSpiral(int** arr, size_t n, size_t m)
{
  if (n == 0 || m == 0 || arr == nullptr)
    return;
  size_t top = 0;
  size_t bottom = n - 1;
  size_t left = 0;
  size_t right = m - 1;
  size_t increment = 1;
  while (top <= bottom && left <= right) {
    for (size_t j = left; j <= right; j++) {
      arr[bottom][j] += increment;
      increment++;
    }
    if (bottom == 0) break;
    bottom--;

    for (size_t i = bottom; i >= top; i--) {
      arr[i][right] += increment;
      increment++;
      if (i == 0) {
        break;
      }
    }
    if (right == 0) break;
    right--;

    if (top <= bottom) {
      for (size_t j = right; j >= left; j--) {
        arr[top][j] += increment;
        increment++;
        if (j == 0) break;
      }
      top++;
    }
    if (left <= right) {
      for (size_t i = top; i <= bottom; i++) {
        arr[i][left] += increment;
        increment++;
      }
      left++;
    }
  }
}

void nepochatova::transformMatrixCircular(int** arr, size_t n, size_t m) {
  size_t layer = 1;
  size_t top = 0, bottom = n - 1, left = 0, right = m - 1;

  while (top <= bottom && left <= right) {
    for (size_t j = left; j <= right; j++)
      arr[top][j] += layer;

    for (size_t i = top + 1; i <= bottom; i++)
      arr[i][right] += layer;

    if (top < bottom) {
      for (size_t j = right - 1; j >= left; j--){
        arr[bottom][j] += layer;
        if (j == 0) break;
      }
    }

    if (left < right) {
      for (size_t i = bottom - 1; i > top; i--){
        arr[i][left] += layer;
        if (i == 0) break;
      }
    }
    top++;
    bottom--;
    left++;
    right--;
    layer++;
  }

}
