#include <fstream>
#include <iostream>
#include <cstring>
#include "matrix_ideas.h"
int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Error: Incorrect number of arguments" << "\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  if (!input.is_open())
  {
    std::cerr << "Error: Cannot open input file" << "\n";
    return 1;
  }
  if (!output.is_open())
  {
    std::cerr << "Error: Cannot open output file" << "\n";
    return 2;
  }
  char num = argv[1][0];
  if ((num != '1' && num != '2') || strlen(argv[1]) != 1)
  {
    std::cerr << "Error: Wrong question" << "\n";
    return 1;
  }
  int rows = 0;
  int cols = 0;
  input >> rows >> cols;
  if (input.fail())
  {
    std::cerr << "Error: Input fail" << "\n";
    return 1;
  }
  if (rows < 0 || cols < 0)
  {
    std::cerr << "Error: Invalid matrix dimensions" << "\n";
    return 1;
  }
  if (rows == 0 || cols == 0)
  {
    output << 0 << "\n";
    return 0;
  }
  int mtr[10000] = {};
  int* matrix = static_cast< int * >(malloc(sizeof(int) * rows * cols));
  if (matrix == nullptr && num == '2')
  {
    std::cerr << "Error: Memory allocation failed" << "\n";
    return 2;
  }
  if (!ivanov::write_in((num == '1') ? mtr : matrix, rows, cols, input, (num != '1')))
  {
    return 2;
  }
  ivanov::fll_inc_wav((num == '1') ? mtr : matrix, rows, cols);
  output << ivanov::max_sum_mdg((num == '1') ? mtr : matrix, rows, cols) << "\n";
  return 0;
}
