#ifndef MATRIX_IDEAS_H
#define MATRIX_IDEAS_H
#include <fstream>

namespace ivanov
{
  void fll_inc_wav(int* mtr, int rows, int cols);
  int max_sum_mdg(const int* matrix, int rows, int cols);
  bool write_in(int* matrix, int rows, int cols, std::ifstream& input, bool is_dynamic);
}

#endif
