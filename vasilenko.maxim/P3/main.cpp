#include <iostream>
#include <fstream>
#include <cstdlib>

namespace vasilenko {

  int my_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
      s1++;
      s2++;
    }
    return *reinterpret_cast<const unsigned char*>(s1) - *reinterpret_cast<const unsigned char*>(s2);
  }

  int my_max(int a, int b) {
    return (a > b) ? a : b;
  }

  void make_free(int* matrix) {
    std::free(matrix);
  }

  int cntcolnsm(const int* matrix, int rows, int cols) {
    int count = 0;

    if (rows < 2) {
      return cols;
    }

    for (int j = 0; j < cols; ++j) {
      bool has_consecutive = false;
      for (int i = 0; i < rows - 1; ++i) {
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
      for (int i = 0; i < rows; ++i) {
        int j = i - k;

        if (j >= 0 && j < cols) {
          current_sum += matrix[i * cols + j];
        }
      }

      if (first_diag) {
        max_sum = current_sum;
        first_diag = false;
      } else {
        max_sum = vasilenko::my_max(max_sum, current_sum);
      }
    }
    return max_sum;
  }
}


int main(int argc, char** argv) {

  if (argc != 4) {
    std::cerr << "Invalid number of arguments\n";
    return 1;
  }

  if (vasilenko::my_strcmp(argv[1], "1") != 0 && vasilenko::my_strcmp(argv[1], "2") != 0) {
    std::cerr << "First parameter is invalid (must be 1 or 2)\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  if (!input.is_open()) {
    std::cerr << "Cannot open input file\n";
    return 2;
  }

  if (vasilenko::my_strcmp(argv[1], "1") == 0) {
    int rows = 0, cols = 0;
    int static_matrix[10000] = {};

    input >> rows >> cols;

    if (input.fail() || rows < 0 || cols < 0) {
      std::cerr << "Cannot read matrix dimensions\n";
      return 2;
    }

    if (rows * cols > 10000) {
      std::cerr << "Static matrix size exceeds limit (10000)\n";
      return 2;
    }

    for (int i = 0; i < rows * cols; ++i) {
      input >> static_matrix[i];
      if (input.fail()) {
        std::cerr << "Invalid matrix element data\n";
        return 2;
      }
    }
    input.close();

    std::ofstream output(argv[3]);
    if (!output.is_open()) {
      std::cerr << "Cannot open output file\n";
      return 1;
    }

    output << vasilenko::cntcolnsm(static_matrix, rows, cols) << "\n";
    output << vasilenko::maxsumsdg(static_matrix, rows, cols) << "\n";
    output.close();
  }
  else {
    int rows = 0, cols = 0;
    int* dynamic_matrix = nullptr;

    input >> rows >> cols;

    if (input.fail() || rows < 0 || cols < 0) {
      std::cerr << "Cannot read matrix dimensions\n";
      return 2;
    }

    if (rows * cols > 0) {
      dynamic_matrix = static_cast<int*>(std::malloc(sizeof(int) * rows * cols));
      if (!dynamic_matrix) {
        std::cerr << "Memory allocation failed\n";
        return 1;
      }
    }

    for (int i = 0; i < rows * cols; ++i) {
      input >> dynamic_matrix[i];
      if (input.fail()) {
        std::cerr << "Invalid matrix element data\n";
        vasilenko::make_free(dynamic_matrix);
        return 2;
      }
    }
    input.close();

    std::ofstream output(argv[3]);
    if (!output.is_open()) {
      std::cerr << "Cannot open output file\n";
      vasilenko::make_free(dynamic_matrix);
      return 1;
    }

    output << vasilenko::cntcolnsm(dynamic_matrix, rows, cols) << "\n";
    output << vasilenko::maxsumsdg(dynamic_matrix, rows, cols) << "\n";
    output.close();

    vasilenko::make_free(dynamic_matrix);
    dynamic_matrix = nullptr;
  }

  return 0;
}
