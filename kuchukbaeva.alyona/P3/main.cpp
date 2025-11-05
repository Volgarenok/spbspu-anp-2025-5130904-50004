#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
namespace kuchukbaeva
{
  bool readMatrix(const std::string& filename, int*** matrix, size_t& rows, size_t& cols)
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
  bool readMatrixStatic(const std::string& filename, int** matrix, size_t& rows, size_t& cols, size_t max_rows, size_t max_cols)
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
  void freMatrix(int** matrix, size_t rows)
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
}
int main()
{
}
