#ifndef POZDEEV_H
#define POZDEEV_H

#include <iostream>
#include <fstream>

namespace pozdeev {
  constexpr int MAX_SIZE = 10000;
  constexpr int ERROR_INVALID_FORMAT = 91;
  constexpr int ERROR_INVALID_VALUE = 92;
  int countNonSequentialRows(const int* matrix, size_t rows, size_t cols);
  void spiral(int* matrix, int rows, int cols);
  int numAnalysis(const char* s);
  int processStatic(std::ifstream& fin, std::ofstream& fout, size_t rows, size_t cols);
  int processDynamic(std::ifstream& fin, std::ofstream& fout, size_t rows, size_t cols);
}

#endif
