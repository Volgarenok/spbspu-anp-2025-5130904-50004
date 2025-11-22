#ifndef FUNC_HPP
#define FUNC_HPP
#include <fstream>

namespace ivantsova
{
  std::istream & readArr(std::istream & input, int * arr, size_t rows, size_t cols);
  std::ostream & writeArr(std::ostream & output, const int * arr, size_t rows, size_t cols, int result);
  void reduceElements(int * arr, size_t rows, size_t cols);
  int countColumns(const int * arr, size_t rows, size_t cols);
}

#endif
