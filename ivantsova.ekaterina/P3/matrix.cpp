#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

std::istream & ivantsova::readArr(std::istream & input, int * arr, size_t rows, size_t cols)
{
  size_t number = 0;
  for (size_t i = 0; i < rows * cols && input >> arr[i]; i++)
  {
    ++number;
  }
  return input;
}

std::ostream & ivantsova::writeArr(std::ostream & output, const int * arr, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      output << arr[i * cols + j];
      if (j < cols - 1)
      {
        output << " ";
      }
    }
    output << "\n";
  }
  return output;
}

void ivantsova::reduceElements(int * arr, size_t rows, size_t cols)
{
  size_t left = 0;
  size_t up = 0;
  size_t original_cols = cols;
  int step = 1;
  while (up < rows && left < cols)
  {
    for (size_t i = rows - 1; i >= up && i < rows; i--)
    {
      arr[i * original_cols + left] -= step++;
      if (i == 0 && i >= up)
      {
        break;
      }
    }
    left++;
    if (left >= cols)
    {
      break;
    }
    for (size_t i = left; i < cols; i++)
    {
      arr[up * original_cols + i] -= step++;
    }
    up++;
    if (up >= rows)
    {
      break;
    }
    for (size_t i = up; i < rows; i++)
    {
      arr[i * original_cols + (cols - 1)] -= step++;
    }
    cols--;
    if (left >= cols)
    {
      break;
    }
    for (size_t i = cols - 1; i >= left; i--)
    {
      arr[(rows - 1) * original_cols + i] -= step++;
      if (i == 0)
      {
        break;
      }
    }
    rows--;
  }
}

int ivantsova::countColumns(const int * arr, size_t rows, size_t cols)
{
  int count = 0;
  for (size_t j = 0; j < cols; j++)
  {
    bool rep = false;
    for (size_t i = 0; i + 1 < rows; i++)
    {
      if (arr[i * cols + j] == arr[(i + 1) * cols + j])
      {
        rep = true;
        break;
      }
    }
    if (!rep)
    {
      count++;
    }
  }
  return count;
}

void ivantsova::workWithArray(std::istream & input, std::ostream & output, int * arr, size_t rows, size_t cols)
{
  if (arr == nullptr || rows == 0 || cols == 0)
  {
    return;
  }
  readArr(input, arr, rows, cols);
  if (!input)
  {
    return;
  }
  int result = countColumns(arr, rows, cols);
  output << result << "\n";
  reduceElements(arr, rows, cols);
  writeArr(output, arr, rows, cols);
}
