#include "func.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

bool Khvaevskii::isValidNumber (long long num)
{
  const long long MIN_VALUE = -1000000;
  const long long MAX_VALUE = 1000000;
  return (num >= MIN_VALUE && num <= MAX_VALUE);
}

bool Khvaevskii::readMatrixFixed (std::ifstream& file, int* matrix, int rows, int cols)
{
  if (!file.is_open ())
  {
    return false;
  }

  long long temp_rows, temp_cols;
  if (!(file >> temp_rows >> temp_cols))
  {
    return false;
  }

  if (temp_rows < 0 || temp_cols < 0 || temp_rows > 100 || temp_cols > 100)
  {
    return false;
  }

  int actual_rows = static_cast<int> (temp_rows);
  int actual_cols = static_cast<int> (temp_cols);

  if (actual_rows > rows || actual_cols > cols)
  {
    return false;
  }

  if (static_cast<long long> (actual_rows) * actual_cols > 10000)
  {
    return false;
  }

  for (int i = 0; i < actual_rows; i++)
  {
    for (int j = 0; j < actual_cols; j++)
    {
      long long temp_val;
      if (!(file >> temp_val))
      {
        return false;
      }
      if (!Khvaevskii::isValidNumber (temp_val))
      {
        return false;
      }
      matrix[i * actual_cols + j] = static_cast<int> (temp_val);
    }
  }

  return true;
}

int* Khvaevskii::readMatrixDynamic (std::ifstream& file, int& rows, int& cols)
{
  if (!file.is_open ())
  {
    return nullptr;
  }

  long long temp_rows, temp_cols;
  if (!(file >> temp_rows >> temp_cols))
  {
    return nullptr;
  }

  if (temp_rows < 0 || temp_cols < 0)
  {
    return nullptr;
  }

  rows = static_cast<int> (temp_rows);
  cols = static_cast<int> (temp_cols);

  int* matrix = static_cast<int*> (malloc (rows * cols * sizeof (int)));
  if (!matrix)
  {
    return nullptr;
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      long long temp_val;
      if (!(file >> temp_val))
      {
        free (matrix);
        return nullptr;
      }
      if (!Khvaevskii::isValidNumber (temp_val))
      {
        free (matrix);
        return nullptr;
      }
      matrix[i * cols + j] = static_cast<int> (temp_val);
    }
  }

  return matrix;
}

void Khvaevskii::freeMatrix (int* matrix)
{
  if (matrix)
  {
    free (matrix);
  }
}

long long Khvaevskii::maxSumDiagonal (int* matrix, int rows, int cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }

  long long max_sum = -9223372036854775807LL - 1;

  for (int col_offset = 0; col_offset < cols; col_offset++)
  {
    long long sum = 0;
    int i = 0;
    int j = col_offset;
    while (i < rows && j < cols)
    {
      sum += matrix[i * cols + j];
      i++;
      j++;
    }
    if (sum > max_sum)
    {
      max_sum = sum;
    }
  }

  for (int row_offset = 1; row_offset < rows; row_offset++)
  {
    long long sum = 0;
    int i = row_offset;
    int j = 0;
    while (i < rows && j < cols)
    {
      sum += matrix[i * cols + j];
      i++;
      j++;
    }
    if (sum > max_sum)
    {
      max_sum = sum;
    }
  }

  return max_sum;
}

int Khvaevskii::countSaddlePoints (int* matrix, int rows, int cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }

  int count = 0;

  for (int i = 0; i < rows; i++)
  {
    int min_in_row = matrix[i * cols + 0];
    for (int j = 1; j < cols; j++)
    {
      if (matrix[i * cols + j] < min_in_row)
      {
        min_in_row = matrix[i * cols + j];
      }
    }

    for (int j = 0; j < cols; j++)
    {
      if (matrix[i * cols + j] == min_in_row)
      {
        bool is_max_in_col = true;
        for (int k = 0; k < rows; k++)
        {
          if (matrix[k * cols + j] > matrix[i * cols + j])
          {
            is_max_in_col = false;
            break;
          }
        }

        if (is_max_in_col)
        {
          count++;
        }
      }
    }
  }

  return count;
}
