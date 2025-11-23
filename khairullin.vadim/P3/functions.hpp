#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <fstream>

namespace khairullin
{
  int check_arguments(int argc, char ** argv, int command);
  void filling(int * array, std::ifstream & input, int rows, int cols, int command);
  int localMax(const int * array, int rows, int cols);
  int CheckZero(const int * array, int index1, int index2, int size);
  bool triangle(const int * array, int size);
}

#endif
