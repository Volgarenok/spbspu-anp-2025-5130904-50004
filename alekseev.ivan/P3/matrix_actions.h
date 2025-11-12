#ifndef MATRIX_ACTIONS_H
#define MATRIX_ACTIONS_H
#include <fstream>

namespace alekseev {
  void input_matrix(std::istream & input, int * matrix, size_t n, size_t m);
  void output_matrix(std::ostream & output, int * matrix, size_t n, size_t m);
  void lft_top_clk(int * matrix, size_t n, size_t m);
  void modify(size_t & i, size_t & j, int & modifier_id,
              size_t & top, size_t & bottom, size_t & left, size_t & right);
  size_t min(int * start, const int * end);
  size_t cnt_sdl_pnt(int * matrix, size_t n, size_t m);
}
#endif
