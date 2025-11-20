#include "logic.hpp"
#include <iostream>

namespace vasilenko {

  int cntcolnsm(const int* matrix, int rows, int cols) {
    int count = 0;
    if (rows < 2) {
      return cols;
    }

    for (int j = 0; j < cols; ++j) {
      bool has_consecutive = false;
      for (size_t i = 0; i < static_cast< size_t >(rows) - 1; ++i) {
        if (matrix[i * cols + j] == matrix[(i + 1) * cols + j]) {
          has_consecutive = true;
          break;
        }
      }
      if (!has_consecutive) {
        count++;
      }
    }
    return count;
  }

  int maxsumsdg(const int* matrix, int rows, int cols) {
    if (rows == 0 || cols == 0) {
      return 0;
    }

    int max_sum = 0;
    bool first_diag = true;

    for (int k = 1 - cols; k < rows; ++k) {
      int current_sum = 0;
      for (size_t i = 0; i < static_cast< size_t >(rows); ++i) {
        int j = static_cast< int >(i) - k;
        if (j >= 0 && j < cols) {
          current_sum += matrix[i * cols + j];
        }
      }

      if (first_diag) {
        max_sum = current_sum;
        first_diag = false;
      } else {

        max_sum = (current_sum > max_sum) ? current_sum : max_sum;
      }
    }
    return max_sum;
  }

  int input_array(std::istream& in, int* matrix, size_t size) {
    for (size_t i = 0; i < size; ++i) {
      in >> matrix[i];
      if (in.fail()) {
        return 1;
      }
    }
    return 0;
  }
}
