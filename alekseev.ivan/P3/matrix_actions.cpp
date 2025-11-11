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


  void lft_bot_clk(int * matrix, size_t n, size_t m)
  {
    int mods[4]{-1, 0, 1, 0};
    size_t modificator_id = 0;
    size_t i = n, j = 0ull;
    size_t top = 0ull, bot = n - 1ull, left = 0ull, right = m - 1ull;
    matrix[i * m + j] += 1;
    for (size_t k = 1ull; k < n * m; ++k) {
      i += mods[modificator_id % 4];
      j += mods[(modificator_id + 1) % 4];
      modify(top, bot, left, right, i, j, modificator_id);
      matrix[i * m + j] -= k + 1;
    }
  }


  void modify(size_t & top, size_t & bot, size_t & left, size_t & right,
              size_t & i, size_t & j, size_t & modificator_id)
  {
    if (i > top) {
      --top;
      --i;
      ++j;
      ++modificator_id;
    } else if (j > right) {
      --right;
      --j;
      ++i;
      ++modificator_id;
    } else if (i < bot) {
      ++bot;
      ++i;
      --j;
      ++modificator_id;
    } else if (j < left) {
      ++left;
      ++j;
      --i;
      ++modificator_id;
    }
  }
}
