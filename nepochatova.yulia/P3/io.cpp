#include <iostream>
#include <stdexcept>
#include "io.h"

int nepochatova::checkArgs(int argc, char **argv)
{
  if (argc < 4) {
    throw std::invalid_argument("Not enough arguments");
  }
  if (argc > 4) {
    throw std::invalid_argument("Too many arguments");
  }

  const char *p = argv[1];
  if (*p != '1' && *p != '2') {
    throw std::invalid_argument("First parameter is out of range");
  }

  if (*p == '\0') {
    throw std::invalid_argument("First parameter is not a number");
  }
  while (*p) {
    if (*p < '0' || *p > '9') {
      throw std::invalid_argument("First parameter is not a number");
    }
    ++p;
  }
  return 0;
}

int ** nepochatova::readMatrix(const std::string &filename, size_t &n, size_t &m, bool useDynamic) {
  std::ifstream in(filename);
  if (!in)
    throw std::runtime_error("Input file can't be opened");

  if (!(in >> n >> m))
    throw std::runtime_error("Invalid matrix format");

  if (n == 0 || m == 0)
    return nullptr;

  const size_t MAX_N = 100;
  const size_t MAX_M = 100;

  static int staticMatrix[MAX_N][MAX_M];
  static int* staticRows[MAX_N];

  int** arr = nullptr;

  if (!useDynamic) {
    if (n > MAX_N || m > MAX_M)
      throw std::runtime_error("Array too large for static memory");

    for (size_t i = 0; i < n; ++i)
      staticRows[i] = staticMatrix[i];

    arr = staticRows;
  }
  else {
    arr = new int*[n];
    try {
      for (size_t i = 0; i < n; ++i)
        arr[i] = new int[m];
    }
    catch (...) {
      for (size_t i = 0; i < n; ++i)
        delete[] arr[i];
      delete[] arr;
      throw;
    }
  }
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      if (!(in >> arr[i][j]))
        throw std::runtime_error("Invalid matrix data");
    }
  }

  return arr;
}
void nepochatova::writeMatrix(std::ofstream& out, const int* const* arr, size_t n, size_t m) {
  if (arr == nullptr || n == 0 || m == 0) {
    out << "0 0\n";
    return;
  }
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      out << arr[i][j];
      if (j != m - 1) out << " ";
    }
    out << "\n";
  }
}
