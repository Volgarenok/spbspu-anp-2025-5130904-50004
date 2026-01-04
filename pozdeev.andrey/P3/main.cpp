#include "matrix_utils.hpp"
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

  size_t rows = 0;
  size_t cols = 0;
  if (!(fin >> rows >> cols)) {
    std::cerr << "ERROR: Invalid matrix dimensions format or file is empty" << std::endl;
    return 2;
  }

  const size_t numElements = rows * cols;

  int staticMatrix[pozdeev::MAX_STATIC_SIZE];
  int * dynamicMatrix = nullptr;
  int * matrixToProcess = nullptr;

  if (taskNum == 1) {
    matrixToProcess = staticMatrix;
  } else {
    try {
      dynamicMatrix = new int[numElements];
    } catch (const std::bad_alloc &) {
      std::cerr << "ERROR: Memory allocation failed" << std::endl;
      return 2;
    }
    matrixToProcess = dynamicMatrix;
  }

  pozdeev::inputMatrix(fin, matrixToProcess, numElements);

  if (!fin) {
    std::cerr << "ERROR: Invalid matrix element or not enough elements" << std::endl;
    delete[] dynamicMatrix;
    return 2;
  }

  if (taskNum == 1) {
    const int result = pozdeev::countNonSequentialRows(matrixToProcess, rows, cols);
    fout << result << "\n";
  } else {
    pozdeev::spiral(matrixToProcess, rows, cols);
    pozdeev::outputMatrix(fout, matrixToProcess, rows, cols);
  }

  delete[] dynamicMatrix;
  return 0;
}
