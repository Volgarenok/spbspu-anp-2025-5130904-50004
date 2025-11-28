#include "matrix_operations.hpp"
#include <iostream>

std::istream& velizade::readArr(std::istream& input, int* arr, size_t rows, size_t cols)
{
  int value;
  for (size_t i = 0; i < rows * cols; i++)
  {
    if (!(input >> value))
    {
      return input;
    }
    arr[i] = value;
  }
  return input;
}

std::ostream& velizade::writeResult(std::ostream& output, const int* arr, size_t rows, size_t cols, int result)
{
  output << result;
  if (rows > 0 && cols > 0)
  {
    output << "\n";
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < cols; j++)
      {
        output << arr[i * cols + j];
        if (j < cols - 1)
        {
           output << " ";
        }
      }
      if (i < rows - 1)
      {
        output << "\n";
      }
    }
  }
  return output;
}

size_t velizade::countLocalMins(const int* arr, size_t rows, size_t cols)
{
  if (rows < 3 || cols < 3)
  {
    return 0;
  }

  size_t count = 0;
  for (size_t i = 1; i < rows - 1; i++)
  {
    for (size_t j = 1; j < cols - 1; j++)
    {
      int current = arr[i * cols + j];
      bool isLocalMin = true;

      for (int di = -1; di <= 1; di++)
      {
        for (int dj = -1; dj <= 1; dj++)
        {
          if (di == 0 && dj == 0)
          {
            continue;
          }
          size_t ni = i + di;
          size_t nj = j + dj;
          if (current >= arr[ni * cols + nj])
          {
            isLocalMin = false;
            break;
          }
        }
        if (!isLocalMin)
        {
          break;
        }
      }

      if (isLocalMin)
      {
        count++;
      }
    }
  }
  return count;
}

void velizade::leftTopClockwise(int* arr, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0)
  {
    return;
  }
  int top = 0, bottom = rows - 1;
  int left = 0, right = cols - 1;
  int decrement = 1;

  while (top <= bottom && left <= right)
  {
    for (int j = left; j <= right; j++)
    {
      arr[top * cols + j] -= decrement++;
    }
    top++;

    for (int i = top; i <= bottom; i++)
    {
      arr[i * cols + right] -= decrement++;
    }
    right--;

    if (top <= bottom)
    {
      for (int j = right; j >= left; j--)
      {
        arr[bottom * cols + j] -= decrement++;
      }
      bottom--;
    }

    if (left <= right)
    {
      for (int i = bottom; i >= top; i--)
      {
        arr[i * cols + left] -= decrement++;
      }
      left++;
    }
  }
}
