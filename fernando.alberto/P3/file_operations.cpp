#include "file_operations.h"

#include <fstream>
#include <iostream>

#include "memory_management.h"

namespace fernando {
  int* read_matrix(const char* filename, int& rows, int& cols)
  {
    std::ifstream file(filename);
    if (!file.is_open()) {
      std::cerr << "Error opening file: " << filename << std::endl;
      return nullptr;
    }

    file >> rows >> cols;
    if (file.fail()) {
      std::cerr << "Error reading matrix dimensions" << std::endl;
      file.close();
      return nullptr;
    }

    if (rows <= 0 || cols <= 0) {
      std::cerr << "Invalid matrix dimensions: " << rows << "x" << cols << std::endl;
      file.close();
      return nullptr;
    }

    int* matrix = allocate_matrix(rows, cols);
    if (!matrix) {
      std::cerr << "Error allocating memory for matrix" << std::endl;
      file.close();
      return nullptr;
    }

    for (int i = 0; i < rows * cols; i++) {
      file >> matrix[i];
      if (file.fail()) {
        std::cerr << "Error reading matrix element at position " << i << std::endl;
        file.close();
        free_matrix(matrix);
        return nullptr;
      }
    }

    file.close();
    return matrix;
  }

  bool write_result(const char* filename, int result)
  {
    std::ofstream file(filename);
    if (!file.is_open()) {
      return false;
    }
    file << result << std::endl;
    file.close();
    return true;
  }
}
