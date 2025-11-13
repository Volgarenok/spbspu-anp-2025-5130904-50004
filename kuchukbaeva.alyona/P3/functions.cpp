#include "functions2.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

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

bool kuchukbaeva::readMatrix(const std::string& filename, int*** matrix, size_t& rows, size_t& cols)
{
  std::ifstream file(filename);
  if (!file.is_open())
  {
    return false;
  }
  if (!(file >> rows >> cols))
  {
    return false;
  }
  if (rows == 0 || cols == 0)
  {
    *matrix = nullptr;
    return true;
  }
  *matrix = static_cast<int**>(malloc(rows * sizeof(int*)));
  if (*matrix == nullptr)
  {
    return false;
  }
  for (size_t i = 0; i < rows; i++)
  {
    (*matrix)[i] = static_cast<int*>(malloc(cols * sizeof(int)));
    if ((*matrix)[i] == nullptr)
    {
      for (size_t j = 0; j < i; j++)
      {
        free((*matrix)[j]);
      }
      free(*matrix);
      *matrix = nullptr;
      return false;
    }
  }
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      if (!(file >> (*matrix)[i][j]))
      {
        for (size_t k = 0; k < rows; k++)
        {
          free((*matrix)[k]);
        }
        free(*matrix);
        *matrix = nullptr;
        return false;
      }
    }
  }
  return true;
}

bool kuchukbaeva::readMatrixStatic(const std::string& filename, int** matrix, size_t& rows, size_t& cols, size_t max_rows, size_t max_cols)
{
  std::ifstream file(filename);
  if (!file.is_open())
  {
    return false;
  }
  if (!(file >> rows >> cols))
  {
    return false;
  }
  if (rows == 0 || cols == 0)
  {
    return true;
  }
  if (rows > max_rows || cols > max_cols)
  {
    return false;
  }
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      if (!(file >> matrix[i][j]))
      {
        return false;
      }
    }
  }
  return true;
}

void kuchukbaeva::freMatrix(int** matrix, size_t rows)
{
  if (matrix != nullptr)
  {
    for (size_t i = 0; i < rows; i++)
    {
      free(matrix[i]);
    }
    free(matrix);
  }
}

bool kuchukbaeva::Res(const std::string& filename, int res)
{
  std::ofstream file(filename);
  if (!file.is_open())
  {
    return false;
  }
  file << res;
  return true;
}

bool kuchukbaeva::writeMatrix(const std::string& filename, int** matrix, size_t rows, size_t cols, int locMaxCount)
{
  std::ofstream file(filename);
  if (!file.is_open())
  {
    return false;
  }
  file << locMaxCount << "\n";
  file << rows << " " << cols;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      file << " " << matrix[i][j];
    }
  }
  return true;
}

