#include "matrix_actions.hpp"
#include <iostream>

namespace chadin
{

std::istream& readArr(std::istream& input, int* arr, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (!(input >> arr[i]))
    {
      break;
    }
  }
  return input;
}

std::ostream& writeArr(std::ostream& output, const int* arr, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    if (cols > 0)
    {
      output << arr[i * cols];
      for (size_t j = 1; j < cols; ++j)
      {
        output << " " << arr[i * cols + j];
      }
    }
    output << "\n";
  }
  return output;
}

void increaseElements(int* arr, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0)
  {
    return;
  }

  size_t left = 0;
  size_t right = cols - 1;
  size_t top = 0;
  size_t bottom = rows - 1;
  int step = 1;

  while (left <= right && top <= bottom)
  {
    for (size_t i = bottom; i >= top; --i)
    {
      arr[i * cols + left] += step++;
    }
    ++left;
    if (left > right)
    {
      break;
    }

    for (size_t j = left; j <= right; ++j)
    {
      arr[bottom * cols + j] += step++;
    }
    --bottom;
    if (top > bottom)
    {
      break;
    }

    for (size_t j = right; j >= left; --j)
    {
      arr[top * cols + j] += step++;
    }
    ++top;
    if (top > bottom)
    {
      break;
    }

    for (size_t i = top; i <= bottom; ++i)
    {
      arr[i * cols + right] += step++;
    }
    --right;
  }
}

int countDiagonals(const int* arr, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }

  int count = 0;

  for (size_t start_col = 0; start_col < cols; ++start_col)
  {
    bool has_zero = false;
    size_t r = 0;
    size_t c = start_col;
    while (r < rows && c < cols)
    {
      if (arr[r * cols + c] == 0)
      {
        has_zero = true;
        break;
      }
      ++r;
      ++c;
    }
    if (!has_zero)
    {
      ++count;
    }
  }

  for (size_t start_row = 1; start_row < rows; ++start_row)
  {
    bool has_zero = false;
    size_t r = start_row;
    size_t c = 0;
    while (r < rows && c < cols)
    {
      if (arr[r * cols + c] == 0)
      {
        has_zero = true;
        break;
      }
      ++r;
      ++c;
    }
    if (!has_zero)
    {
      ++count;
    }
  }

  return count;
}

}
