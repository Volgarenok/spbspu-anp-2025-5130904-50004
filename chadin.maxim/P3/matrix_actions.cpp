#include "matrix_actions.hpp"
#include <iostream>

namespace chadin
{
int* readMatrix(std::istream& in, int& rows, int& cols)
{
  if (!(in >> rows >> cols))
  {
    return nullptr;
  }
  if (rows < 0 || cols < 0)
  {
    return nullptr;
  }
  if (rows == 0 || cols == 0)
  {
    return new int[0];
  }
  int size = rows * cols;
  int* matrix = new int[size];
  for (int i = 0; i < size; ++i)
  {
    if (!(in >> matrix[i]))
    {
      delete[] matrix;
      return nullptr;
    }
  }
  return matrix;
}

void deleteMatrix(int* matrix)
{
  delete[] matrix;
}

int countNonZeroDiagonals(const int* matrix, int rows, int cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  int total_diagonals = rows + cols - 1;
  int count = 0;
  for (int d = 0; d < total_diagonals; ++d)
  {
    bool has_zero = false;
    int start_row = (d < cols) ? 0 : d - cols + 1;
    int start_col = (d < cols) ? d : 0;
    int r = start_row;
    int c = start_col;

    while (r < rows && c < cols)
    {
      if (matrix[r * cols + c] == 0)
      {
        has_zero = true;
        break;
      }
      ++r;
      ++c;
    }

    if (!has_zero)
    {
      ++count;
    }
  }

  return count;
}

void transformSpiralFromBottomLeft(int* matrix, int rows, int cols)
{
  if (rows == 0 || cols == 0)
  {
    return;
  }

  int total = rows * cols;
  bool* visited = new bool[total]();
  int value = 1;
  int r = rows - 1;
  int c = 0;

  const int dr[4] = {0, -1, 0, 1};
  const int dc[4] = {1, 0, -1, 0};
  int dir = 0;
  
  for (int step = 0; step < total; ++step)
  {
    matrix[r * cols + c] += value;
    visited[r * cols + c] = true;
    ++value;

    int nr = r + dr[dir];
    int nc = c + dc[dir];

    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || visited[nr * cols + nc])
    {
      dir = (dir + 1) % 4;
      nr = r + dr[dir];
      nc = c + dc[dir];
    }

    r = nr;
    c = nc;
  }

  delete[] visited;
}

void writeMatrix(std::ostream& out, const int* matrix, int rows, int cols)
{
  out << rows << " " << cols << "\n";
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (j > 0)
      {
        out << " ";
      }
      out << matrix[i * cols + j];
    }
    out << "\n";
  }
}
}
