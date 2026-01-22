#include "matrix.h"

bool ahrameev::is_upper_triangular(const int* matrix, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0)
  {
    return false;
  }

  for (size_t i = 1; i < rows; ++i)
  {
    for (size_t j = 0; j < i && j < cols; ++j)
    {
      if (matrix[i * cols + j] != 0)
      {
        return false;
      }
    }
  }

  return true;
}

void ahrameev::build_spiral(const int* src, int* dst, size_t rows, size_t cols)
{
  size_t top = 0;
  size_t bottom = rows - 1;
  size_t left = 0;
  size_t right = cols - 1;

  size_t index = 0;
  size_t total = rows * cols;

  while (index < total)
  {
    for (size_t j = left; j <= right && index < total; ++j)
    {
      dst[top * cols + j] = src[index];
      ++index;
    }
    ++top;

    for (size_t i = top; i <= bottom && index < total; ++i)
    {
      dst[i * cols + right] = src[index];
      ++index;
    }

    if (right == 0)
    {
      break;
    }
    --right;

    for (size_t j = right + 1; j-- > left && index < total; )
    {
      dst[bottom * cols + j] = src[index];
      ++index;
    }

    if (bottom == 0)
    {
      break;
    }
    --bottom;

    for (size_t i = bottom + 1; i-- > top && index < total; )
    {
      dst[i * cols + left] = src[index];
      ++index;
    }
    ++left;
  }
}
