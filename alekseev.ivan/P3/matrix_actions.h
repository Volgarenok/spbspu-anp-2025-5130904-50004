#ifndef MATRIX_ACTIONS_H
#define MATRIX_ACTIONS_H
#include <fstream>

namespace alekseev {
  void input_matrix(std::istream & input, int * matrix, size_t n, size_t m);
  void output_matrix(std::ostream & output, int * matrix, size_t n, size_t m);
  void lft_bot_clk(int * matrix, size_t n, size_t m);
  void modify(size_t & top, size_t & bot, size_t & left, size_t & right,
              size_t & i, size_t & j, size_t & modificator_id);
}
#endif
