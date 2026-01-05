#ifndef MATRIX_UTILS_HPP
#define MATRIX_UTILS_HPP

#include <cstddef>
#include <fstream>

namespace pozdeev {
  constexpr size_t MAX_STATIC_SIZE = 10000;

  int countNonSequentialRows(const int * matrix, size_t rows, size_t cols);
  void spiral(int * matrix, size_t rows, size_t cols);

  int numAnalysis(const char * s);
  void inputMatrix(std::ifstream & in, int * matrix, size_t size);
  void outputMatrix(std::ofstream & out, const int * matrix, size_t rows, size_t cols);
}

#endif
