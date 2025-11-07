#ifndef IO_MATRIX_H
#define IO_MATRIX_H
#include <fstream>

namespace alekseev {
  void input_matrix(std::istream & input, int * matrix, size_t n, size_t m);
  void output_matrix(std::ostream & output, int * matrix, size_t n, size_t m);
}
#endif
