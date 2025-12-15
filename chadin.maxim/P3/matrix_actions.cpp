#include "matrix_actions.hpp"
#include <iostream>
#include <cstdlib>

namespace chadin
{

std::istream& readArr(std::istream& input, int* arr, std::size_t rows, std::size_t cols)
{
  for (std::size_t i = 0; (i < rows * cols) && (input >> arr[i]); ++i)
  {
  }
  return input;
}

std::ostream& writeArr(std::ostream& output, const int* arr, std::size_t rows, std::size_t cols, int result)
{
  output << result << "\n";
  for (std::size_t i = 0; i < rows; ++i)
  {
    if (cols > 0)
    {
      output << arr[i * cols];
    }
    for (std::size_t j = 1; j < cols; ++j)
    {
      output << " " << arr[i * cols + j];
    }
    output << "\n";
  }
  return output;
}

void increaseElements(int* arr, std::size_t rows, std::size_t cols)
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
      arr[i * cols + left] += step++;
    }
    ++left;
    if (left > right)
    {
      break;
    }

    for (int j = left; j <= right; ++j)
    {
      arr[bottom * cols + j] += step++;
    }
    --bottom;
    if (top > bottom)
    {
      break;
    }

    for (int j = right; j >= left; --j)
    {
      arr[top * cols + j] += step++;
    }
    ++top;
    if (top > bottom)
    {
      break;
    }

    for (int i = top; i <= bottom; ++i)
    {
      arr[i * cols + right] += step++;
    }
    --right;
  }
}

int countDiagonals(const int* arr, std::size_t rows, std::size_t cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }

  int count = 0;

  for (std::size_t start_col = 0; start_col < cols; ++start_col)
  {
    bool has_zero = false;
    std::size_t r = 0;
    std::size_t c = start_col;
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

  for (std::size_t start_row = 1; start_row < rows; ++start_row)
  {
    bool has_zero = false;
    std::size_t r = start_row;
    std::size_t c = 0;
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
