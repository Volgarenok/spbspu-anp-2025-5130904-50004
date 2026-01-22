#include "tasks.hpp"

int oztas::countNonZeroDiagonals(const int* matrix, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }

  int result = 0;
  const size_t totalDiagonals = rows + cols - 1;

  for (size_t diagonal = 0; diagonal < totalDiagonals; ++diagonal)
  {
    bool hasElement = false;
    bool allNonZero = true;
    size_t startRow = 0;
    size_t startCol = 0;

    if (diagonal < cols)
    {
      startRow = 0;
      startCol = cols - 1 - diagonal;
    }
    else
    {
      startRow = diagonal - cols + 1;
      startCol = 0;
    }

    size_t i = startRow;
    size_t j = startCol;

    while (i < rows && j < cols)
    {
      hasElement = true;

      if (matrix[i * cols + j] == 0)
      {
        allNonZero = false;
        break;
      }

      ++i;
      ++j;
    }

    if (hasElement && allNonZero)
    {
      ++result;
    }
  }

  return result;
}

void oztas::applyFillIncreasingWave(int* matrix, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0) 
  {
    return;
  }

  int value = 1;

  size_t top = 0;
  size_t bottom = rows - 1;
  size_t left = 0;
  size_t right = cols - 1;

  while (top <= bottom && left <= right) 
  {
    for (size_t j = left; j < right; ++j) 
    {
      matrix[top * cols + j] = value++;
    }
    ++top;

    for (size_t i = top; i <= bottom; ++i) 
    {
      matrix[i * cols + right] = value++;
    }
    if (right == 0) 
    {
      break;
    }
    --right;

    if (top <= bottom) 
    {
      for (size_t j = right + 1; j > left; --j) 
      {
        matrix[bottom * cols + (j - 1)] = value++;
      }
      if (bottom == 0)
      {
        break;
      }
      --bottom;
    }

    if (left <= right)
    {
      for (size_t i = bottom + 1; i > top; --i)
      {
        matrix[(i - 1) * cols + left] = value++;
      }
      ++left;
    }
  }
}
