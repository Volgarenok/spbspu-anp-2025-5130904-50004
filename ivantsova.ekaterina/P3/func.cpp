#include "func.hpp"
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
  }
  else if (rows * cols > number)
  {
    std::cerr << "Not enough elements" << "\n";
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
  size_t t = rows * cols;
  int temp[10000];
  for (size_t i = 0; i < t; i++)
  {
    temp[i] = arr[i];
  }
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
      temp[index] -= step++;
    }
    left++;
    if (left > right)
    {
      break;
    }
    for (int i = left; i <= right; i++)
    {
      size_t index = up * cols + i;
      temp[index] -= step++;
    }
    up++;
    if (up > down)
    {
      break;
    }
    for (int i = up; i <= down; i++)
    {
      size_t index = i * cols + right;
      temp[index] -= step++;
    }
    right--;
    if (left > right)
    {
      break;
    }
    for (int i = right; i >= left; i--)
    {
      size_t index = down * cols + i;
      temp[index] -= step++;
    }
    down--;
  }
  for (size_t i = 0; i < t; i++)
  {
    arr[i] = temp[i];
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
