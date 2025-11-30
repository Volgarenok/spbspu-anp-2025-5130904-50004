#include <iostream>
#include <fstream>
#include <cctype>
#include "matrix_work.hpp"

int main(int argc, char** argv)
{
  if (argc > 4) {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  } else if (argc < 4) {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }
  else {
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
      if (argv[1][0] == '1') {
        int fixedMatrix[10000];
        try {
          bychkovskaya::inputMatrix(input, fixedMatrix, rows, cols);
        } catch (const std::invalid_argument& e) {
          input.close();
          std::cerr << e.what() << "\n";
          return 2;
        }
        input.close();
        std::ofstream output(argv[3]);
        bychkovskaya::outputMatrix(output, fixedMatrix, rows, cols);
        output.close();
      }
      if (argv[1][0] == '2') {
        int* dynamicMatrix = nullptr;
        try {
          dynamicMatrix = bychkovskaya::create(rows, cols);
        } catch (const std::runtime_error& e) {
          std::cerr << e.what() << "\n";
          return 2;
        }
        try {
          bychkovskaya::inputMatrix(input, dynamicMatrix, rows, cols);
          input.close();
          std::ofstream output(argv[3]);
          bychkovskaya::outputMatrix(output, dynamicMatrix, rows, cols);
          output.close();
          delete[] dynamicMatrix;
        } catch (const std::exception& e) {
          std::cerr << e.what() << "\n";
          delete[] dynamicMatrix;
          return 2;
        }
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
}

