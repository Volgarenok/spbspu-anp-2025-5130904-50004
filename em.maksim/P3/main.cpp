#include "matrix_operations.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
  if (!em::validate_arguments(argc, argv))
  {
    return 1;
  }

  int num = argv[1][0] - '0';
  const char* input_file = argv[2];
  const char* output_file = argv[3];

  int rows = 0;
  int cols = 0;

  if (num == 1)
  {
    const int MAX_SIZE = 10000;
    int matrix[MAX_SIZE];

    if (!em::read_matrix(input_file, matrix, rows, cols, MAX_SIZE))
    {
      std::cerr << "Failed to read matrix from file";
      return 2;
    }

    em::process_left_bottom_clockwise(matrix, rows, cols);
    bool success = em::write_matrix(output_file, matrix, rows, cols, false);

    if (success)
    {
      return 0;
    }
    else
    {
      return 2;
    }
  }
  else if (num == 2)
  {
    int* matrix = nullptr;

    if (!em::read_matrix(input_file, &matrix, rows, cols))
    {
      std::cerr << "Failed to read matrix from file";
      return 2;
    }

    em::build_smooth_matrix(matrix, rows, cols);
    bool success = em::write_matrix(output_file, matrix, rows, cols, true);

    delete[] matrix;

    if (success)
    {
      return 0;
    }
    else
    {
      return 2;
    }
  }

  return 1;
}
