#include "matrix_operations.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
  if (!em::validate_arguments(argc, argv))
  {
    return 1;
  }

  int num = argv[1][0] - '0';

  int rows = 0;
  int cols = 0;

  if (num == 1)
  {
    const int MAX_SIZE = 10000;
    int matrix[MAX_SIZE];
    em::read_matrix(argv[2], matrix, rows, cols, MAX_SIZE);
    em::process_left_bottom_clockwise(matrix, rows, cols);
    em::write_matrix(argv[3], matrix, rows, cols, false);
    return 0;
  }
  else if (num == 2)
  {
    int* matrix = nullptr;
    em::read_matrix(argv[2], &matrix, rows, cols);
    em::build_smooth_matrix(matrix, rows, cols);
    em::write_matrix(argv[3], matrix, rows, cols, true);
    delete[] matrix;
    return 0;
  }

  return 1;
}
