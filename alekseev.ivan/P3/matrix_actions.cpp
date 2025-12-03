#include "matrix_actions.h"

#include <cstddef>
#include <iostream>


void alekseev::input_matrix(std::istream & input, int * matrix, size_t rows, size_t cols)
{
  for (size_t i = 0ull; i < rows; ++i) {
    for (size_t j = 0ull; j < cols; ++j) {
      input >> matrix[i * cols + j];
    }
  }
}


void alekseev::output_matrix(std::ostream & output, const int * matrix, size_t rows, size_t cols)
{
  for (size_t i = 0ull; i < rows; ++i) {
    output << matrix[i * cols];
    for (size_t j = 1ull; j < cols; ++j) {
      output << " " << matrix[i * cols + j];
    }
    output << "\n";
  }
}


void alekseev::lft_top_clk(int * matrix, size_t rows, size_t cols)
{
  int modifiers[4]{0, 1, 0, -1};
  size_t modifier_id = 0;
  size_t i = 1, j = 1;
  size_t top = 1, bottom = rows, left = 1, right = cols;
  for (size_t k = 0ull; k < rows * cols; ++k) {
    matrix[(i - 1) * cols + (j - 1)] -= k + 1;

    i += modifiers[modifier_id % 4];
    j += modifiers[(modifier_id + 1) % 4];
    if (j > right) {
      ++top;
      j = right;
      ++i;
      ++modifier_id;
    } else if (i > bottom) {
      --right;
      i = bottom;
      --j;
      ++modifier_id;
    } else if (j < left) {
      --bottom;
      j = left;
      --i;
      ++modifier_id;
    } else if (i < top) {
      ++left;
      i = top;
      ++j;
      ++modifier_id;
    }
  }
}


const int * alekseev::min(const int * start, size_t k)
{
  if (k == 0) {
    return start;
  }
  const int * m = start;
  for (size_t i = 1ull; i < k; ++i) {
    if (start[i] < *m) {
      m = start + i;
    }
  }
  return m;
}


const int * alekseev::max_of_column(const int * matrix, size_t rows, size_t cols, size_t j)
{
  const int * ma = matrix + j;
  for (size_t i = 0ull; i < rows; ++i) {
    if (*ma < matrix[i * cols + j]) {
      ma = matrix + i * cols + j;
    }
  }
  return ma;
}


size_t alekseev::cnt_sdl_pnt(const int * matrix, size_t rows, size_t cols)
{
  size_t counter = 0;
  for (size_t i = 0ull; i < rows; ++i) {
    int mi = *min(matrix + i * cols, cols);
    for (size_t j = 0ull; j < cols; ++j) {
      if (matrix[i * cols + j] == mi) {
        if (matrix[i * cols + j] == *max_of_column(matrix, rows, cols, j)) {
          ++counter;
        }
      }
    }
  }
  return counter;
}
