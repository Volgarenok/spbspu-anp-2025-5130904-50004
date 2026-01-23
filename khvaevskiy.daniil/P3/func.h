#ifndef FUNC_H
#define FUNC_H

namespace Khvaevskii
{
  bool readMatrixFixed (std::ifstream& file, int* matrix, int rows, int cols);
  int* readMatrixDynamic (std::ifstream& file, int& rows, int& cols);
  void freeMatrix (int* matrix);
  long long maxSumDiagonal (int* matrix, int rows, int cols);
  int countSaddlePoints (int* matrix, int rows, int cols);
  bool isValidNumber (long long num);
}

#endif

