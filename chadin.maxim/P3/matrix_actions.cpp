#include "matrix_actions.hpp"
#include <iostream>

std::istream& chadin::readArr(std::istream& input, int* arr, size_t rows, size_t cols)
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

std::ostream& chadin::writeArr(std::ostream& output, const int* arr, size_t rows, size_t cols)
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

void chadin::increaseElements(int* arr, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0)
  {
    return;
  }

  int left = 0;
  int right = static_cast<int>(cols) - 1;
  int top = 0;
  int bottom = static_cast<int>(rows) - 1;
  int step = 1;

  while (left <= right && top <= bottom)
  {
    for (int i = bottom; i >= top; --i)
    {
      arr[i * static_cast<int>(cols) + left] += step++;
    }
    ++left;
    if (left > right) break;

    for (int j = left; j <= right; ++j)
    {
      arr[top * static_cast<int>(cols) + j] += step++;
    }
    ++top;
    if (top > bottom) break;

    for (int i = top; i <= bottom; ++i)
    {
      arr[i * static_cast<int>(cols) + right] += step++;
    }
    --right;
    if (left > right) break;

    for (int j = right; j >= left; --j)
    {
      arr[bottom * static_cast<int>(cols) + j] += step++;
    }
    --bottom;
  }
}

int chadin::countDiagonals(const int* arr, size_t rows, size_t cols)
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
    size_t len = 0;
    while (r < rows && c < cols)
    {
      if (arr[r * cols + c] == 0)
      {
        has_zero = true;
        break;
      }
      ++r;
      ++c;
      ++len;
    }
    if (!has_zero && len >= 2)
    {
      ++count;
    }
  }

  for (size_t start_row = 1; start_row < rows; ++start_row)
  {
    bool has_zero = false;
    size_t r = start_row;
    size_t c = 0;
    size_t len = 0;
    while (r < rows && c < cols)
    {
      if (arr[r * cols + c] == 0)
      {
        has_zero = true;
        break;
      }
      ++r;
      ++c;
      ++len;
    }
    if (!has_zero && len >= 2)
    {
      ++count;
    }
  }

  return count;
}
