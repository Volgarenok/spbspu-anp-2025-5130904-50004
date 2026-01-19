#ifndef MATRIX_IDEAS_H
#define MATRIX_IDEAS_H
#include <fstream>

namespace ivanov
{
  void fll_inc_wav(int* mtr, size_t rows, size_t cols);
  int max_sum_mdg(const int* matrix, size_t rows, size_t cols);
  void write_in(int* matrix, size_t rows, size_t cols, std::ifstream& input);
}

#endif
