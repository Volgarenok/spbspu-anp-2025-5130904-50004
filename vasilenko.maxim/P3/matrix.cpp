#include "matrix.hpp"

#include <algorithm>
#include <iostream>

size_t vasilenko::countColsNsm(const int* matrix, size_t rows, size_t cols)
{
  size_t count = 0;
  if (rows < 2)
  {
    return cols;
  }

  for (size_t j = 0; j < cols; ++j)
  {
    bool hasConsecutive = false;
    for (size_t i = 0; i < rows - 1; ++i)
    {
      if (matrix[i * cols + j] == matrix[(i + 1) * cols + j])
      {
        hasConsecutive = true;
        break;
      }
    }
    if (!hasConsecutive)
    {
      count++;
    }
  }
  return count;
}

int vasilenko::maxSumSdg(const int* matrix, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }

  int maxSum = 0;
  bool firstDiag = true;

  size_t diagCount = rows + cols - 1;

  for (size_t d = 0; d < diagCount; ++d)
  {
    size_t r = 0;
    size_t c = 0;

    if (d < cols)
    {
      r = 0;
      c = cols - 1 - d;
    }
    else
    {
      r = d - cols + 1;
      c = 0;
    }

    int currentSum = 0;
    while (r < rows && c < cols)
    {
      currentSum += matrix[r * cols + c];
      r++;
      c++;
    }

    if (firstDiag)
    {
      maxSum = currentSum;
      firstDiag = false;
    }
    else
    {
      maxSum = std::max(maxSum, currentSum);
    }
  }

  return maxSum;
}

void vasilenko::inputMatrix(std::istream& in, int* matrix, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    in >> matrix[i];
  }
}
