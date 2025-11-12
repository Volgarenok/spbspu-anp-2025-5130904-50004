#include "matrix_actions.h"

#include <cstddef>
#include <iostream>

namespace alekseev {
  void input_matrix(std::istream & input, int * matrix, const size_t n, const size_t m)
  {
    for (size_t i = 0ull; i < n; ++i) {
      for (size_t j = 0ull; j < m; ++j) {
        input >> matrix[i * m + j];
      }
    }
    if (input.fail()) {
      throw std::invalid_argument("Matrix unread");
    }
  }


  void output_matrix(std::ostream & output, int * matrix, const size_t n, const size_t m)
  {
    for (size_t i = 0ull; i < n; ++i) {
      output << matrix[i * m];
      for (size_t j = 1ull; j < m; ++j) {
        output << " " << matrix[i * m + j];
      }
      output << "\n";
    }
  }


  void lft_top_clk(int * matrix, size_t n, size_t m)
  {
    int modifiers[4]{0, 1, 0, -1};
    int modifier_id = 0;
    size_t i = 1ull, j = 1ull;
    size_t top = 1ull, bottom = n, left = 1ull, right = m;
    for (size_t k = 0ull; k < n * m; ++k) {
      matrix[(i - 1) * m + (j - 1)] -= k + 1;

      i += modifiers[modifier_id];
      j += modifiers[modifier_id + 1];
      modify(i, j, modifier_id, top, bottom, left, right);
    }
  }


  void modify(size_t & i, size_t & j, int & modifier_id,
              size_t & top, size_t & bottom, size_t & left, size_t & right)
  {
    if (j > right) {
      ++top;
      j = right;
      ++i;
      modifier_id = (modifier_id + 1) % 4;
    } else if (i > bottom) {
      --right;
      i = bottom;
      --j;
      modifier_id = (modifier_id + 1) % 4;
    } else if (j < left) {
      --bottom;
      j = left;
      --i;
      modifier_id = (modifier_id + 1) % 4;
    } else if (i < top) {
      ++left;
      i = top;
      ++j;
      modifier_id = (modifier_id + 1) % 4;
    }
  }


  size_t min(int * start, const int * end)
  {
    int * m = start;
    for (int * id = start + 1; id < end; ++id) {
      if (*id < *m) {
        m = id;
      }
    }
    return m - start;
  }


  size_t cnt_sdl_pnt(int * matrix, size_t n, size_t m)
  {
    size_t counter = 0;
    for (size_t i = 0ull; i < n; ++i) {
      size_t str_min = min(matrix + i * m, matrix + (i + 1) * m);
      bool is_col_max = true;
      for (size_t j = 0ull; j < n; ++j) {
        if (matrix[i * m + str_min] < matrix[j * m + str_min]) {
          is_col_max = false;
        }
      }
      counter += is_col_max;
    }
    return counter;
  }
}
