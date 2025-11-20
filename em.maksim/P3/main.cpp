#include "matrix_operations.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
  if (!em::validate_arguments(argc, argv))
  {
    return 1;
  }

  int task_number = argv[1][0] - '0';
  const char* input_file = argv[2];
  const char* output_file = argv[3];

  int rows = 0;
  int cols = 0;
  int* matrix = nullptr;

  if (!em::read_matrix(input_file, &matrix, rows, cols))
  {
    std::cerr << "Failed to read matrix from file" << std::endl;
    return 2;
  }

  if (task_number == 1 && rows * cols > 10000)
  {
    std::cerr << "Matrix too large for fixed array (max 10000 elements)" << std::endl;
    em::free_matrix(matrix);
    return 2;
  }

  bool success = true;
  if (rows > 0 && cols > 0)
  {
    em::process_left_bottom_clockwise(matrix, rows, cols);
    success = em::write_matrix(output_file, matrix, rows, cols, false);

    em::build_smooth_matrix(matrix, rows, cols);
    success = success && em::write_matrix(output_file, matrix, rows, cols, true);
  }
  else
  {
    success = em::write_matrix(output_file, matrix, rows, cols, false);
  }

  em::free_matrix(matrix);

  if (success)
  {
    return 0;
  }
  else
  {
    return 2;
  }
}
