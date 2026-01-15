#include <iostream>
#include <fstream>
#include <cctype>
#include "matrix_work.hpp"

int main(int argc, char** argv)
{
  if (argc > 4) {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  }
  if (argc < 4) {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }
  if (!((argv[1][0] == '1' || argv[1][0] == '2') && argv[1][1] == '\0')) {
    std::cerr << "Wrong first parameter" << "\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input) {
    std::cerr << "Wrong matrix input" << "\n";
    return 2;
  }
  int* matrix = nullptr;
  int* dynamicMatrix = nullptr;
  int fixedMatrix[10000];
  if (argv[1][0] == '1') {
    matrix = fixedMatrix;
  }
  if (argv[1][0] == '2') {
    try {
      dynamicMatrix = new int[rows * cols];
      matrix = dynamicMatrix;
    } catch (const std::bad_alloc& e) {
      std::cerr << "Not enough memory" << "\n";
      return 2;
    }
  }
  bychkovskaya::inputMatrix(input, matrix, rows, cols);
  if (!input) {
    delete[] dynamicMatrix;
    std::cerr << "Wrong matrix input" << "\n";
    return 2;
  }
  std::ofstream output(argv[3]);
  output << bychkovskaya::cntColNsm(matrix, rows, cols) << "\n";
  output << bychkovskaya::cntNzrDig(matrix, rows, cols) << "\n";
  delete[] dynamicMatrix;
}

