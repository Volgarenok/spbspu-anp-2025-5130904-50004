#include "matrix_operations.hpp"
#include <fstream>
#include <iostream>

namespace em {

bool validate_arguments(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Invalid number of arguments";
    return false;
  }

  char first_char = argv[1][0];
  if (first_char != '1' && first_char != '2')
  {
    std::cerr << "First parameter is out of range or not a number";
    return false;
  }

  return true;
}

bool read_matrix(const char* filename, int* matrix, int& rows, int& cols, int max_size)
{
  rows = 0;
  cols = 0;

  std::ifstream file(filename);
  if (!file.is_open())
  {
    return false;
  }

  file >> rows >> cols;

  if (file.fail() || rows < 0 || cols < 0)
  {
    return false;
  }

  if (rows == 0 && cols == 0)
  {
    return true;
  }

  if (rows * cols > max_size)
  {
    return false;
  }

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (!(file >> matrix[i * cols + j]))
      {
        return false;
      }
    }
  }

  return true;
}

bool read_matrix(const char* filename, int** matrix, int& rows, int& cols)
{
  rows = 0;
  cols = 0;
  *matrix = nullptr;

  std::ifstream file(filename);
  if (!file.is_open())
  {
    return false;
  }

  file >> rows >> cols;

  if (file.fail() || rows < 0 || cols < 0)
  {
    return false;
  }

  if (rows == 0 && cols == 0)
  {
    return true;
  }

  *matrix = new int[rows * cols]();
  if (!*matrix)
  {
    return false;
  }

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (!(file >> (*matrix)[i * cols + j]))
      {
        delete[] matrix[0];
        *matrix = nullptr;
        return false;
      }
    }
  }

  return true;
}

bool write_matrix(const char* filename, const int* matrix, int rows, int cols, bool smooth_matrix)
{
  std::ofstream file(filename);
  if (!file.is_open())
  {
    return false;
  }

  file << rows << " " << cols;

  if (rows > 0 && cols > 0)
  {
    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        file << " ";
        if (smooth_matrix)
        {
          int value = matrix[i * cols + j];
          file << value / 10 << "." << (value % 10 < 0 ? -value % 10 : value % 10);
        }
        else
        {
          file << matrix[i * cols + j];
        }
      }
    }
  }

  return file.good();
}

void process_left_bottom_clockwise(int* matrix, int rows, int cols)
{
  if (!matrix || rows <= 0 || cols <= 0)
  {
    return;
  }

  int top = 0;
  int bottom = rows - 1;
  int left = 0;
  int right = cols - 1;
  int counter = 1;

  while (top <= bottom && left <= right)
  {
    for (int i = bottom; i >= top; --i)
    {
      matrix[i * cols + left] -= counter;
      counter++;
    }
    left++;
    if (left > right)
    {
      break;
    }

    for (int j = left; j <= right; ++j)
    {
      matrix[top * cols + j] -= counter;
      counter++;
    }
    top++;
    if (top > bottom)
    {
      break;
    }

    for (int i = top; i <= bottom; ++i)
    {
      matrix[i * cols + right] -= counter;
      counter++;
    }
    right--;
    if (left > right)
    {
      break;
    }

    for (int j = right; j >= left; --j)
    {
      matrix[bottom * cols + j] -= counter;
      counter++;
    }
    bottom--;
  }
}

void build_smooth_matrix(int* matrix, int rows, int cols)
{
  if (!matrix || rows <= 0 || cols <= 0)
  {
    return;
  }

  int* temp = new int[rows * cols]();
  if (!temp)
  {
    return;
  }

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      int sum = 0;
      int count = 0;

      for (int di = -1; di <= 1; ++di)
      {
        for (int dj = -1; dj <= 1; ++dj)
        {
          if (di == 0 && dj == 0)
          {
            continue;
          }

          int ni = i + di;
          int nj = j + dj;
          if (ni >= 0 && ni < rows && nj >= 0 && nj < cols)
          {
            sum += matrix[ni * cols + nj];
            count++;
          }
        }
      }

      if (count > 0)
      {
        temp[i * cols + j] = sum * 10 / count;
      }
      else
      {
        temp[i * cols + j] = matrix[i * cols + j] * 10;
      }
    }
  }

  for (int i = 0; i < rows * cols; ++i)
  {
    matrix[i] = temp[i];
  }

  delete[] temp;
}

}
