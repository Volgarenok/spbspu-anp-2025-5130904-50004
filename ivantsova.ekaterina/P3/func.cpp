#include "functions_for_matrix.hpp"
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
  if (!input)
  {
    std::cerr << "Incorrect input" << "\n";
    input.clear();
    input.setstate(std::ios::failbit);
  }
  else if (rows * cols > number)
  {
    std::cerr << "Not enough elements" << "\n";
    input.setstate(std::ios::failbit);
  }
  return input;
}

std::ostream & ivantsova::writeArr(std::ostream & output, const int * arr, size_t rows, size_t cols, int result)
{
  output << result << "\n";
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      output << arr[i * cols + j] << " ";
    }
    output << "\n";
  }
  return output;
}

void ivantsova::reduceElements(int * arr, size_t rows, size_t cols)
{
  int left = 0;
  int right = cols - 1;
  int up = 0;
  int down = rows - 1;
  int step = 1;
  while (left <= right && up <= down)
  {
    for (int i = down; i >= up; i--)
    {
      size_t index = i * cols + left;
      arr[index] -= step++;
    }
    left++;
    if (left > right)
    {
      break;
    }
    for (int i = left; i <= right; i++)
    {
      size_t index = up * cols + i;
      arr[index] -= step++;
    }
    up++;
    if (up > down)
    {
      break;
    }
    for (int i = up; i <= down; i++)
    {
      size_t index = i * cols + right;
      arr[index] -= step++;
    }
    right--;
    if (left > right)
    {
      break;
    }
    for (int i = right; i >= left; i--)
    {
      size_t index = down * cols + i;
      arr[index] -= step++;
    }
    down--;
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
  readArr(input, arr, rows, cols);
    if (!input)
    {
      return;
    }
    int result = countColumns(arr, rows, cols);
    reduceElements(arr, rows, cols);
    writeArr(output, arr, rows, cols, result);
}
