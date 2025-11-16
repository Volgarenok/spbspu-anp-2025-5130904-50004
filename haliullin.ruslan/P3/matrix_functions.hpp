#ifndef MATRIX_FUNCTIONS_HPP
#define MATRIX_FUNCTIONS_HPP
#include <iostream>
namespace haliullin
{
  std::istream &readMatrix(std::istream &in, int *arr, size_t rows, size_t cols);
  void FllIncrementWave(int *arr, size_t rows, size_t cols);
  size_t NumColLsr(const int *arr, size_t rows, size_t cols);
  std::ostream &writeMatrix(std::ostream &out, const int *arr, size_t rows, size_t cols, size_t res);
}
#endif
