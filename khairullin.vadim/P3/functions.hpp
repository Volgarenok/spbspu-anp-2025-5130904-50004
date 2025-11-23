#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <fstream>

namespace khairullin
{
  int check_arguments(int argc, char ** argv, int command);
  void filling(int * array, std::ifstream & input, size_t rows, size_t cols);
  int localMax(const int * array, size_t rows, size_t cols);
  int CheckZero(const int * array, size_t index1, size_t index2, size_t size);
  bool triangle(const int * array, size_t size);
}

#endif
