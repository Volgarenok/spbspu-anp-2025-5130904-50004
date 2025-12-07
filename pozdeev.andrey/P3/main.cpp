#include "pozdeev.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <new>

int main(int argc, char * argv[])
{
  if (argc < 4) {
    std::cerr << "Not enough arguments" << std::endl;
    return 1;
  }
  if (argc > 4) {
    std::cerr << "Too many arguments" << std::endl;
    return 1;
  }

  int taskNum = 0;
  try {
    taskNum = pozdeev::numAnalysis(argv[1]);
  } catch (const std::exception & e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  std::ifstream fin(argv[2]);
  if (!fin.is_open()) {
    std::cerr << "ERROR: Could not open input file" << std::endl;
    return 2;
  }

  std::ofstream fout(argv[3]);
  if (!fout.is_open()) {
    std::cerr << "ERROR: Could not open output file" << std::endl;
    return 2;
  }

  int tempRows = 0;
  int tempCols = 0;
  if (!(fin >> tempRows >> tempCols)) {
    std::cerr << "ERROR: Invalid matrix dimensions format or file is empty" << std::endl;
    return 2;
  }

  if (tempRows < 0 || tempCols < 0) {
    std::cerr << "ERROR: Matrix dimensions cannot be negative" << std::endl;
    return 2;
  }

  size_t rows = static_cast < size_t > (tempRows);
  size_t cols = static_cast < size_t > (tempCols);
  const size_t numElements = rows * cols;

  if (taskNum == 1) {
    int staticMatrix[pozdeev::MAX_SIZE];

    if (numElements > 0) {
      pozdeev::inputMatrix(fin, staticMatrix, numElements);
      if (!fin) {
        std::cerr << "ERROR: Invalid matrix element or not enough elements" << std::endl;
        return 2;
      }
    }

    const int result = pozdeev::countNonSequentialRows(staticMatrix, rows, cols);
    fout << result << "\n";

  } else {
    int * dynamicMatrix = nullptr;
    try {
      dynamicMatrix = new int[numElements];
    } catch (const std::bad_alloc &) {
      std::cerr << "ERROR: Memory allocation failed" << std::endl;
      return 2;
    }

    if (numElements > 0) {
      pozdeev::inputMatrix(fin, dynamicMatrix, numElements);
      if (!fin) {
        std::cerr << "ERROR: Invalid matrix element or not enough elements" << std::endl;
        delete[] dynamicMatrix;
        return 2;
      }
    }

    pozdeev::spiral(dynamicMatrix, rows, cols);
    pozdeev::outputMatrix(fout, dynamicMatrix, rows, cols);

    delete[] dynamicMatrix;
  }

  return 0;
}
