#include "io_matrix.h"

#include <cstddef>
#include <iostream>

namespace alekseev {
  void input_matrix(std::istream & input, int * matrix, const size_t n, const size_t m)
  {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cout << input.good();
        input >> matrix[i * m + j];
        std::cout << input.good() << " " << matrix[i * m + j] << "\n";
      }
    }
    if (!input.good()) {
      throw std::invalid_argument("Matrix not readed");
    }
  }


  void output_matrix(std::ostream & output, int * matrix, const size_t n, const size_t m)
  {
    for (int i = 0; i < n; i++) {
      output << matrix[i * m + i];
      for (int j = 1; j < m; j++) {
        output << " " << matrix[i * m + j];
      }
      output << "\n";
    }
  }
}
