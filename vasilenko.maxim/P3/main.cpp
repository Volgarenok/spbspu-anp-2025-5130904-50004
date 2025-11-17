#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include "logic.hpp"

int main(int argc, char** argv) {
  if (argc != 4) {
    std::cerr << "Invalid number of arguments\n";
    return 1;
  }

  if (std::strcmp(argv[1], "1") != 0 && std::strcmp(argv[1], "2") != 0) {
    std::cerr << "First parameter is invalid (must be 1 or 2)\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  if (!input.is_open()) {
    std::cerr << "Cannot open input file\n";
    return 2;
  }

  int rows = 0, cols = 0;
  input >> rows >> cols;
  if (input.fail() || rows < 0 || cols < 0) {
    std::cerr << "Cannot read matrix dimensions\n";
    return 2;
  }

  int* matrix = nullptr;

  int static_buffer[10000] = {};

  if (std::strcmp(argv[1], "1") == 0) {

    matrix = static_buffer;
  } else {

    size_t num_elements = static_cast< size_t >(rows) * cols;
    if (num_elements > 0) {

      matrix = static_cast< int * >(malloc(sizeof(int) * num_elements));
      if (!matrix) {
        std::cerr << "Memory allocation failed\n";
        return 1;
      }
    }
  }


  size_t total_size = static_cast< size_t >(rows) * cols;
  if (vasilenko::input_array(input, matrix, total_size) != 0) {
    std::cerr << "Invalid matrix element data\n";
    if (std::strcmp(argv[1], "2") == 0) {
      free(matrix);
    }
    return 2;
  }
  input.close();

  std::ofstream output(argv[3]);
  if (!output.is_open()) {
    std::cerr << "Cannot open output file\n";
    if (std::strcmp(argv[1], "2") == 0) {
      free(matrix);
    }
    return 1;
  }

  output << vasilenko::cntcolnsm(matrix, rows, cols) << "\n";
  output << vasilenko::maxsumsdg(matrix, rows, cols) << "\n";
  output.close();

  if (std::strcmp(argv[1], "2") == 0) {
    free(matrix);
  }

  return 0;
}
