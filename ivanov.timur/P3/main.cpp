#include <fstream>
#include <iostream>
#include "matrix_ideas.h"
int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Error: Incorrect number of arguments" << std::endl;
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  if (!input.is_open())
  {
    std::cerr << "Error: Cannot open input file" << std::endl;
    return 1;
  }
  if (!output.is_open())
  {
    std::cerr << "Error: Cannot open output file" << std::endl;
    return 2;
  }
  char num = argv[1][0];
  if (num != '1' && num != '2')
  {
    std::cerr << "Error: Wrong question" << std::endl;
    return 1;
  }
  int rows, cols;
  input >> rows >> cols;
  if (input.fail())
  {
    std::cerr << "Error: Input fail" << std::endl;
    return 1;
  }
  if (rows < 0 || cols < 0)
  {
    std::cerr << "Error: Invalid matrix dimensions" << std::endl;
    return 1;
  }
  if (rows == 0 || cols == 0)
  {
    output << 0 << std::endl;
    return 0;
  }
  if (num == '1')
  {
    int matrix[10000];
    ivanov::write_in(matrix, rows, cols, std::move(input), false);
    output << ivanov::get_result(matrix, rows, cols) << std::endl;
  }
  else
  {
    int* matrix = static_cast<int*>(malloc(sizeof(int) * rows * cols));
    if (matrix == nullptr)
    {
      std::cerr << "Error: Memory allocation failed" << std::endl;
      return 2;
    }
    ivanov::write_in(matrix, rows, cols, std::move(input), true);
    output << ivanov::get_result(matrix, rows, cols) << std::endl;
    free(matrix);
  }
  return 0;
}
