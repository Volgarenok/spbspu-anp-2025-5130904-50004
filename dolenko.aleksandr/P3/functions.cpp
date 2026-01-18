#include "functions.hpp"

namespace dolenko {

std::istream& read_matrix(std::istream& in, int* arr, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      in >> arr[i * cols + j];
    }
  }
  return in;
}

std::ostream& write_matrix(std::ostream& out, size_t res)
{
  out << res;
  return out;
}

int find_longest_column(const int* data, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }

  int max_length = 0;
  int column_with_max = 0;

  for (size_t j = 0; j < cols; ++j)
  {
    int current_length = 1;
    int max_current_col = 1;

    for (size_t i = 1; i < rows; ++i)
    {
      int current = data[i * cols + j];
      int previous = data[(i - 1) * cols + j];

      if (current == previous)
      {
        current_length++;
      }
      else
      {
        if (current_length > max_current_col)
        {
          max_current_col = current_length;
        }
        current_length = 1;
      }
    }

    if (current_length > max_current_col)
    {
      max_current_col = current_length;
    }

    if (max_current_col > max_length)
    {
      max_length = max_current_col;
      column_with_max = static_cast<int>(j) + 1;
    }
  }

  return column_with_max;
}

int count_local_mins(const int* data, size_t rows, size_t cols)
{
  if (rows < 3 || cols < 3)
  {
    return 0;
  }

  int count = 0;

  for (size_t i = 1; i < rows - 1; ++i)
  {
    for (size_t j = 1; j < cols - 1; ++j)
    {
      int current = data[i * cols + j];
      bool is_local_min = true;

      for (int di = -1; di <= 1 && is_local_min; ++di)
      {
        for (int dj = -1; dj <= 1 && is_local_min; ++dj)
        {
          if (di == 0 && dj == 0)
          {
            continue;
          }
          size_t ni = i + di;
          size_t nj = j + dj;
          int neighbor = data[ni * cols + nj];
          if (current >= neighbor)
          {
            is_local_min = false;
          }
        }
      }

      if (is_local_min)
      {
        count++;
      }
    }
  }

  return count;
}

}
