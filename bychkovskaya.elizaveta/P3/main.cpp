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
  if ((argv[1][0] == '1' || argv[1][0] == '2') && argv[1][1] == '\0') {
    size_t rows = 0;
    size_t cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input) {
      input.close();
      std::cerr << "Wrong matrix input" << "\n";
      return 2;
    }
    int* matrix = nullptr;
    if (argv[1][0] == '1') {
      int fixedMatrix[10000];
      matrix = fixedMatrix;
    }
    if (argv[1][0] == '2') {
      try {
        matrix = new int [rows * cols];
      } catch (const std::bad_alloc& e) {
        std::cerr << "Not enough memory" << "\n";
        return 2;
      }
    }
    try {
      bychkovskaya::inputMatrix(input, matrix, rows, cols);
    } catch (const std::invalid_argument& e) {
      if (argv[1][0] == '2') {
        delete[] matrix;
      }
      input.close();
      std::cerr << e.what() << "\n";
      return 2;
    }
    input.close();
    std::ofstream output(argv[3]);
    bychkovskaya::outputMatrix(output, matrix, rows, cols);
    output.close();
    if (argv[1][0] == '2') {
        delete[] matrix;
    }
  } else {
    if (bychkovskaya::ifNumber(argv[1]) == 1) {
      std::cerr << "First parameter is out of range" << "\n";
      return 1;
    }
    if (bychkovskaya::ifNumber(argv[1]) == 0) {
      std::cerr << "First parameter is not a number" << "\n";
      return 1;
    }
  }
}

