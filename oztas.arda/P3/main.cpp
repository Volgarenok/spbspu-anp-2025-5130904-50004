#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matrix.hpp"
#include "tasks.hpp"

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "invalid arguments\n";
    return 1;
  }

  int taskNum = 0;
  try {
    taskNum = std::stoi(argv[1]);
  } catch (const std::invalid_argument&) {
    std::cerr << "invalid task number\n";
    return 1;
  } catch (const std::out_of_range&) {
    std::cerr << "task number out of range\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  if (!input) {
    std::cerr << "input file error\n";
    return 2;
  }

  std::ofstream output(argv[3]);
  if (!output) {
    std::cerr << "output file error\n";
    return 2;
  }

  int rows = 0;
  int cols = 0;
  
  constexpr int MAX = 256;
  int matrix[MAX * MAX];

  if (!oztas::readMatrix(input, matrix, rows, cols)) {
    std::cerr << "invalid matrix data\n";
    return 2;
  }

  if (rows == 0 || cols == 0) {
    output << "0 0";
    return 0;
  }

  if (taskNum == 1) {
    const int result = oztas::countNonZeroDiagonals(matrix, rows, cols);
    output << result;
  } else if (taskNum == 2) {
    oztas::applyFillIncreasingWave(matrix, rows, cols);
    oztas::writeMatrix(output, matrix, rows, cols);
  }

  return 0;
}
