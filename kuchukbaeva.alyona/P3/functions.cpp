#include "functions.hpp"
#include <iostream>
#include <istream>
#include <ostream>

bool kuchukbaeva::CntLocMax(int** matrix, size_t rows, size_t cols, size_t i, size_t j)
{
  if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
  {
    return false;
  }
  int m = matrix[i][j];
  for (int k = -1; k <= 1; ++k)
  {
    for (int f = -1; f <= 1; ++f)
    {
      if (k == 0 && f == 0)
      {
        continue;
      }
      if (matrix[i + k][j + f] >= m)
      {
        return false;
      }
    }
  }
  return true;
}

int kuchukbaeva::countLocMax(int** matrix, size_t rows, size_t cols)
{
  int count = 0;
  for (size_t i = 1; i < rows - 1; i++)
  {
    for (size_t j = 1; j < cols - 1; j++)
    {
      if (CntLocMax(matrix, rows, cols, i, j))
      {
        count++;
      }
    }
  }
  return count;
}

void kuchukbaeva::LftBotClk(int** matrix, size_t rows, size_t cols)
{
  int top = 0;
  int bottom = static_cast<int>(rows) - 1;
  int left = 0;
  int right = static_cast<int>(cols) - 1;
  int schet = 1;
  while (top <= bottom && left <= right)
  {
    for (int i = bottom; i >= top; i--)
    {
      matrix[i][left] -= schet;
      schet++;
    }
    left++;
    if (left > right)
    {
      break;
    }
    for (int j = left; j <= right; j++)
    {
      matrix[top][j] -= schet;
      schet++;
    }
    top++;
    if (top > bottom)
    {
      break;
    }
    for (int i = top; i <= bottom; i++)
    {
      matrix[i][right] -= schet;
      schet++;
    }
    right--;
    if (left > right)
    {
      break;
    }
    for (int j = right; j >= left; j--)
    {
      matrix[bottom][j] -= schet;
      schet++;
    }
    bottom--;
  }
}

std::istream& kuchukbaeva::readMatrix(std::istream &in, int *arr, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t i = 0; i < rows * cols && in >> arr[i]; ++i)
  {
    ++count;
  }
  if (!in)
  {
    std::cerr << "Unexpected input" << "\n";
  }
  else if (count < rows * cols)
  {
    std::cerr << "Not enough elements" << "\n";
  }
  return in;
}

std::ostream& kuchukbaeva::writeMatrix(std::ostream& out, const int* matrix, size_t rows, size_t cols, int locMaxCount)
{
  out << locMaxCount << "\n";
  for (size_t i = 0; i < rows * cols; ++i)
  {
    out << matrix[i];
    if (i < rows * cols -1)
    {
      out << " ";
    }
  }
  out << "\n";
  return out;
}
