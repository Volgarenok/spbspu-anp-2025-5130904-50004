#include "io_matrix.h"

#include <cstddef>
#include <iostream>

namespace alekseev {
  void input_matrix(std::istream & input, int * matrix, const size_t n, const size_t m)
  {
    for (size_t i = 0ull; i < n; ++i) {
      for (size_t j = 0ull; j < m; ++j) {
        input >> matrix[i * m + j];
      }
    }
    if (input.fail()) {
      throw std::invalid_argument("Matrix unread");
    }
  }


  void output_matrix(std::ostream & output, int * matrix, const size_t n, const size_t m)
  {
    for (size_t i = 0ull; i < n; ++i) {
      output << matrix[i * m];
      for (size_t j = 1ull; j < m; ++j) {
        output << " " << matrix[i * m + j];
      }
      output << "\n";
    }
  }
}
