#include "matrix.hpp"
#include <iostream>
std::istream &haliullin::readMatrix(std::istream &in, int *arr, size_t rows, size_t cols)
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

void haliullin::FllIncrementWave(int *arr, size_t rows, size_t cols)
{
  size_t val = (std::min(rows, cols) + 1) / 2;
  for (size_t k = 0; k < val; ++k)
  {
    for (size_t j = k; j < cols - k; ++j)
    {
      arr[k * cols + j] += (k + 1);
      if (2 * k < rows - 1)
      {
        arr[(rows - (k + 1)) * cols + j] += (k + 1);
      }
  }
    for (size_t i = k + 1; i < rows - (k + 1); ++i)
    {
      arr[i * cols + k] += (k + 1);
      arr[i * cols + cols - (k + 1)] += (k + 1);
    }
  }
}

size_t haliullin::NumColLsr(const int *arr, size_t rows, size_t cols)
{
  size_t res = 0;
  size_t cur_length = 1;
  size_t max_length = 1;
  size_t max_length_total = 1;
  int prev = 0;
  for (size_t j = 0; j < cols; ++j)
  {
    cur_length = 1;
    max_length = 1;
    for (size_t i = 1; i < rows; ++i)
    {
      int cur = arr[i * cols + j];
      prev = arr[(i - 1) * cols + j];

      if (cur == prev)
      {
        ++cur_length;
        max_length = std::max(cur_length, max_length);
      }
      else
      {
        cur_length = 1;
      }
    }
    if (max_length > max_length_total)
    {
      max_length_total = max_length;
      res = j;
    }
  }
  return res;
}

std::ostream &haliullin::writeMatrix(std::ostream &out, const int *arr, size_t rows, size_t cols, size_t res)
{
  out << res << "\n";
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols - 1; ++j)
    {
      out << arr[i * cols + j] << " ";
    }
    out << arr[i * cols + cols - 1] << "\n";
  }
  return out;
}
