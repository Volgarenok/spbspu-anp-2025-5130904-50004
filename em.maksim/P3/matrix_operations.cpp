#include "matrix_operations.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

bool em::validate_arguments(int argc, char* argv[])
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

void em::read_matrix(const char* filename, int* matrix, int& rows, int& cols, int max_size)
{
  rows = 0;
  cols = 0;

  std::ifstream file(filename);
  if (!file.is_open())
  {
    std::cerr << "Failed to read matrix from file";
    std::exit(2);
  }

  file >> rows >> cols;

  if (file.fail() || rows < 0 || cols < 0)
  {
    std::cerr << "Failed to read matrix from file";
    std::exit(2);
  }

  if (rows == 0 && cols == 0)
  {
    return;
  }

  if (rows * cols > max_size)
  {
    std::cerr << "Failed to read matrix from file";
    std::exit(2);
  }

  for (size_t i = 0; i < static_cast<size_t>(rows); ++i)
  {
    for (size_t j = 0; j < static_cast<size_t>(cols); ++j)
    {
      file >> matrix[i * cols + j];
    }
  }

  if (file.fail())
  {
    std::cerr << "Failed to read matrix from file";
    std::exit(2);
  }
}

void em::read_matrix(const char* filename, int** matrix, int& rows, int& cols)
{
  rows = 0;
  cols = 0;
  *matrix = nullptr;

  std::ifstream file(filename);
  if (!file.is_open())
  {
    std::cerr << "Failed to read matrix from file";
    std::exit(2);
  }

  file >> rows >> cols;

  if (file.fail() || rows < 0 || cols < 0)
  {
    std::cerr << "Failed to read matrix from file";
    std::exit(2);
  }

  if (rows == 0 && cols == 0)
  {
    return;
  }

  *matrix = new int[rows * cols]();
  if (!*matrix)
  {
    std::cerr << "Failed to read matrix from file";
    std::exit(2);
  }

  for (size_t i = 0; i < static_cast<size_t>(rows); ++i)
  {
    for (size_t j = 0; j < static_cast<size_t>(cols); ++j)
    {
      file >> (*matrix)[i * cols + j];
    }
  }

  if (file.fail())
  {
    delete[] matrix[0];
    *matrix = nullptr;
    std::cerr << "Failed to read matrix from file";
    std::exit(2);
  }
}

void em::write_matrix(const char* filename, const int* matrix, int rows, int cols, bool smooth_matrix)
{
  std::ofstream file(filename);
  if (!file.is_open())
  {
    std::cerr << "Failed to write matrix to file";
    std::exit(2);
  }

  file << rows << " " << cols;

  if (rows > 0 && cols > 0)
  {
    for (size_t i = 0; i < static_cast<size_t>(rows); ++i)
    {
      for (size_t j = 0; j < static_cast<size_t>(cols); ++j)
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

  if (!file.good())
  {
    std::cerr << "Failed to write matrix to file";
    std::exit(2);
  }
}

void em::process_left_bottom_clockwise(int* matrix, int rows, int cols)
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

void em::build_smooth_matrix(int* matrix, int rows, int cols)
{
  if (!matrix || rows <= 0 || cols <= 0)
  {
    return;
  }

  int* temp = new int[rows * cols]();
  if (!temp)
  {
    std::cerr << "Failed to allocate memory";
    std::exit(2);
  }

  for (size_t i = 0; i < static_cast<size_t>(rows); ++i)
  {
    for (size_t j = 0; j < static_cast<size_t>(cols); ++j)
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

          int ni = static_cast<int>(i) + di;
          int nj = static_cast<int>(j) + dj;
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

  for (size_t i = 0; i < static_cast<size_t>(rows * cols); ++i)
  {
    matrix[i] = temp[i];
  }

  delete[] temp;
}
