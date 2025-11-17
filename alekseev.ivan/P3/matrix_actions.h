#ifndef MATRIX_ACTIONS_H
#define MATRIX_ACTIONS_H
#include <fstream>

namespace alekseev {
  void input_matrix(std::istream & input, int * matrix, size_t rows, size_t cols);
  void output_matrix(std::ostream & output, int * matrix, size_t rows, size_t cols);
  void lft_top_clk(int * matrix, size_t rows, size_t cols);
  void modify(size_t & i, size_t & j, size_t & modifier_id,
      size_t & top, size_t & bottom, size_t & left, size_t & right);
  int * min(int * start, const int * end);
  int * max_of_column(int * matrix, const size_t rows, const size_t cols, size_t j);
  size_t cnt_sdl_pnt(int * matrix, size_t rows, size_t cols);
}
#endif
