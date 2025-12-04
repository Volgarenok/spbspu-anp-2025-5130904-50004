#include "matrix_functions.hpp"
#include <iostream>
#include <istream>
#include <ostream>

bool kuchukbaeva::cntLocMax(const int* matrix, size_t rows, size_t cols, size_t i, size_t j)
{
  if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
  {
    return false;
  }
  int m = matrix[i * cols + j];
  for (size_t k = i - 1; k <= i + 1; ++k)
  {
    for (size_t f = j - 1; f <= j + 1; ++f)
    {
      if (k == i && f == j)
      {
        continue;
      }
      if (matrix[k * cols + f] >= m)
      {
        return false;
      }
    }
  }
  return true;
}

size_t kuchukbaeva::countLocMax(const int* matrix, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t i = 1; i < rows - 1; i++)
  {
    for (size_t j = 1; j < cols - 1; j++)
    {
      if (cntLocMax(matrix, rows, cols, i, j))
      {
        count++;
      }
    }
  }
  return count;
}

void kuchukbaeva::lftBotClk(int* matrix, size_t rows, size_t cols)
{
  size_t top = 0;
  size_t bottom = rows - 1;
  size_t left = 0;
  size_t right = cols - 1;
  size_t counter = 1;

  while (top <= bottom && left <= right)
  {
    for (size_t i = bottom; i >= top && i < rows; --i)
    {
      matrix[i * cols + left] -= counter++;
    }
    left++;
    if (left > right)
    {
      break;
    }
    for (size_t j = left; j <= right; ++j)
    {
      matrix[top * cols + j] -= counter++;
    }
    top++;
    if (top > bottom)
    {
      break;
    }
    for (size_t i = top; i <= bottom; ++i)
    {
      matrix[i * cols + right] -= counter++;
    }
    right--;
    if (left > right)
    {
      break;
    }
    for (size_t j = right; j >= left && j < cols ; --j)
    {
      matrix[bottom * cols + j] -= counter++;
    }
    bottom--;
  }
}

size_t kuchukbaeva::readMatrix(std::istream& in, int *matrix, size_t rows, size_t cols)
{
  size_t read_count = 0;
  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (in >> matrix[i])
    {
      read_count++;
    }
    else
    {
      break;
    }
  }
  return read_count;
}

void kuchukbaeva::writeMatrix(std::ostream& out, const int* matrix, size_t rows, size_t cols)
{
  out << rows << " " << cols;
  for (size_t i = 0; i < rows * cols; ++i)
  {
    out << " " << matrix[i];
  }
  out << "\n";
}
