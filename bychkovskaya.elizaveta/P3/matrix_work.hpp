#ifndef MATRIX_WORK_HPP
#define MATRIX_WORK_HPP

#include <fstream>

namespace bychkovskaya {
  std::ifstream& inputMatrix(std::ifstream& in, int* m, size_t rows, size_t cols);
  size_t cntColNsm(const int* m, size_t rows, size_t cols);
  size_t cntNzrDig(const int* m, size_t rows, size_t cols);
}

#endif

