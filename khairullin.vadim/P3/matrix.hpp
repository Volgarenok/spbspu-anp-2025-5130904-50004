#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <fstream>

namespace khairullin
{
  int check_arguments(int argc, char ** argv);
  void fill(int * array, std::ifstream & input, size_t rows, size_t cols);
  int findLocalMax(const int * array, size_t rows, size_t cols);
  int checkZero(const int * array, size_t index1, size_t index2, size_t size);
  bool checkTriangle(const int * array, size_t size);
}

#endif
