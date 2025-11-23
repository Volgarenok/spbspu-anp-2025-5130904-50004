#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <fstream>

namespace khairullin
{
  int check_arguments(int argc, char ** argv, int command);
  void filling(int * array, std::ifstream & input, size_t rows, size_t cols, int command);
  int localMax(const int * array, size_t rows, size_t cols);
  int CheckZero(const int * array, int index1, int index2, int size);
  bool triangle(const int * array, int size);
}

#endif
