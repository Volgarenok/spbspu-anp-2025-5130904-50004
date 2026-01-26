#include <fstream>
#include <stdexcept>
#include "io.h"

int main(int argc, char **argv) {
  size_t n = 0, m = 0, allocatedRows = 0;

  int **arr = nullptr;
  bool dynamic = false;

  const size_t MAX_N = 100;
  const size_t MAX_M = 100;

  int staticMatrix[MAX_N][MAX_M];
  int *staticRows[MAX_N];

  try {
    nepochatova::checkArgs(argc, argv);

    dynamic = argv[1][0] == '2';

    std::ifstream in(argv[2]);
    if (!in.is_open())
      throw std::runtime_error("Input file can't be opened");

    if (!(in >> n >> m))
      throw std::runtime_error("Invalid matrix format");

    if (n == 0 || m == 0) {
      std::ofstream out(argv[3]);
      out << "0 0\n";
      return 0;
    }
    if (!dynamic) {
      if (n > MAX_N || m > MAX_M) {
        throw std::runtime_error("Array too large");
      }
      for (size_t i = 0; i < n; ++i) {
        staticRows[i] = staticMatrix[i];
      }
      arr = staticRows;
    } else {
      arr = new int *[n];
      for (size_t i = 0; i < n; ++i) {
        arr[i] = new int[m];
        ++allocatedRows;
      }
    }
    nepochatova::readMatrix(argv[2], arr, n, m);
    nepochatova::transformMatrixSpiral(arr, n, m);

    std::ofstream out(argv[3]);
    nepochatova::writeMatrix(out, arr, n, m);

  } catch (...) {
    if (dynamic && arr) {
      for (size_t i = 0; i < allocatedRows; ++i)
        delete[] arr[i];
      delete[] arr;
    }
    return 1;
  }
  if (dynamic) {
    for (size_t i = 0; i < allocatedRows; ++i)
      delete[] arr[i];
    delete[] arr;
  }
  return 0;
}