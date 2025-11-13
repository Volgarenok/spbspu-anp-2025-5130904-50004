#include "matrix_actions.h"

#include <cstddef>
#include <iostream>

namespace alekseev {
  void input_matrix(std::istream & input, int * matrix, const size_t rows, const size_t cols)
  {
    for (size_t i = 0ull; i < rows; ++i) {
      for (size_t j = 0ull; j < cols; ++j) {
        input >> matrix[i * cols + j];
      }
    }
    if (input.fail()) {
      throw std::invalid_argument("Matrix unread");
    }
  }


  void output_matrix(std::ostream & output, int * matrix, const size_t rows, const size_t cols)
  {
    for (size_t i = 0ull; i < rows; ++i) {
      output << matrix[i * cols];
      for (size_t j = 1ull; j < cols; ++j) {
        output << " " << matrix[i * cols + j];
      }
      output << "\n";
    }
  }


  void lft_top_clk(int * matrix, const size_t rows, const size_t cols)
  {
    int modifiers[4]{0, 1, 0, -1};
    size_t modifier_id = 0;
    size_t i = 1ull, j = 1ull;
    size_t top = 1ull, bottom = rows, left = 1ull, right = cols;
    for (size_t k = 0ull; k < rows * cols; ++k) {
      matrix[(i - 1) * cols + (j - 1)] -= k + 1;

      i += modifiers[modifier_id % 4];
      j += modifiers[(modifier_id + 1) % 4];
      modify(i, j, modifier_id, top, bottom, left, right);
    }
  }


  void modify(size_t & i, size_t & j, size_t & modifier_id,
              size_t & top, size_t & bottom, size_t & left, size_t & right)
  {
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


  int * min(int * start, const int * end)
  {
    int * m = start;
    for (int * id = start + 1; id < end; ++id) {
      if (*id < *m) {
        m = id;
      }
    }
    return m;
  }


  int * max_of_column(int * matrix, const size_t rows, const size_t cols, size_t j)
  {
    int * ma = matrix + j;
    for (size_t i = 0ull; i < rows; ++i) {
      if (*ma < matrix[i * cols + j]) {
        ma = matrix + i * cols + j;
      }
    }
    return ma;
  }


  size_t cnt_sdl_pnt(int * matrix, size_t rows, size_t cols)
  {
    bool * str_mins = new bool[rows * cols];
    for (size_t i = 0; i < rows; ++i) {
      int * start = matrix + i * cols;
      int * end = start + cols;
      int minimum = *min(start, end);
      for (size_t j = 0; j < cols; ++j) {
        str_mins[i * cols + j] = (*(start + j) == minimum);
      }
    }

    size_t counter = 0ull;
    for (size_t j = 0ull; j < cols; ++j) {
      int maximum = *max_of_column(matrix, rows, cols, j);
      for (size_t i = 0ull; i < rows; ++i) {
        if (matrix[i * cols + j] == maximum && str_mins[i * cols + j]) {
          ++counter;
        }
      }
    }
    delete[] str_mins;
    return counter;
  }
}
