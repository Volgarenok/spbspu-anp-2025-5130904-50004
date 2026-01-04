#include <iostream>
#include <fstream>
#include <exception>
#include "matrix.hpp"

int main(int argc, char** argv)
{
  if (argc < 4) {
    std::cerr << "Not enough arguments\n";
    return 1;
  } else if (argc > 4) {
    std::cerr << "Too many arguments\n";
    return 1;
  }

  if (argv[1][0] == '\0') {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0') {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);

  if (!input.is_open()) {
    std::cerr << "ERROR: " << argv[2] << " is not open\n";
    return 1;
  } else if (!output.is_open()) {
    std::cerr << "ERROR: " << argv[3] << " is not open\n";
    return 1;
  }

  size_t rows = 0;
  size_t cols = 0;

  input >> rows;
  input >> cols;

  if (!input) {
    std::cerr << "ERROR: Incorrect input data\n";
    return 2;
  }

  if (rows == 0 || cols == 0) {
    return 0;
  }

  if (argv[1][0] == '1') {
    int array[10000] = {};
    zinovev::processArray(input, output, array, rows, cols);
  } else if (argv[1][0] == '2') {
    int* array = nullptr;

    try {
      array = new int[rows * cols]{};
    } catch (const std::bad_alloc& e) {
      std::cerr << "ERROR: Memory allocation failed - " << e.what() << "\n";
      return 1;
    }

    zinovev::processArray(input, output, array, rows, cols);
    delete[] array;
  }

  if (!input) {
    return 2;
  }

  return 0;
}
