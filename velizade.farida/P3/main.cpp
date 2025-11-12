#include <iostream>
#include <fstream>
#include <cstdlib>

namespace velizade
{
  std::istream& readArr(std::istream& input, int* arr, size_t rows, size_t cols);
  std::ostream& writeResult(std::ostream& output, const int* arr, size_t rows, size_t cols, int result);
  int countLocalMins(const int* arr, size_t rows, size_t cols);
  void leftTopClockwise(int* arr, size_t rows, size_t cols);
}

int main()
{
}
