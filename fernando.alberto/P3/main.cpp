#include <cstdlib>
#include <cstring>
#include <iostream>

#include "file_operations.h"
#include "matrix_operations.h"
#include "memory_management.h"

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cerr << "Usage: /lab <num> <input> <output>" << std::endl;
    std::cerr << "num: 1 (fixed array) or 2 (dynamic array)" << std::endl;
    return 1;
  }

  int num = std::atoi(argv[1]);
  if (num != 1 && num != 2) {
    std::cerr << "Error: num must be 1 or 2" << std::endl;
    return 1;
  }

  const char* input_file = argv[2];
  const char* output_file = argv[3];

  int rows = 0;
  int cols = 0;
  int* matrix = fernando::read_matrix(input_file, rows, cols);
  if (matrix == nullptr) {
    return 2;
  }

  int result = 0;
  if (num == 1) {
    const int MAX_SIZE = 10000;
    if (rows * cols > MAX_SIZE) {
      std::cerr << "Error: Matrix too large for fixed array" << std::endl;
      fernando::free_matrix(matrix);
      return 2;
    }
    int static_matrix[MAX_SIZE];
    std::memcpy(static_matrix, matrix, rows * cols * sizeof(int));
    result = fernando::process_fixed_matrix(static_matrix, rows, cols);
  } else {
    result = fernando::process_dynamic_matrix(matrix, rows, cols);
  }

  if (!fernando::write_result(output_file, result)) {
    std::cerr << "Error writing to output file" << std::endl;
    fernando::free_matrix(matrix);
    return 2;
  }

  fernando::free_matrix(matrix);
  return 0;
}
