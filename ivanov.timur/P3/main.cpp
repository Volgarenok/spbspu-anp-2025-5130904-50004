#include <fstream>
#include <iostream>
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
  if ((num != '1' && num != '2') || argv[1][1] != '\0')
  {
    std::cerr << "Error: Wrong question" << "\n";
    return 1;
  }
  int r = 0;
  int c = 0;
  input >> r >> c;
  if (input.fail())
  {
    std::cerr << "Error: Input fail" << "\n";
    return 1;
  }
  if (r < 0 || c < 0)
  {
    std::cerr << "Error: Invalid matrix dimensions" << "\n";
    return 1;
  }
  if (r == 0 || c == 0)
  {
    output << 0 << "\n";
    return 0;
  }
  size_t rows = r;
  size_t cols = c;
  int mtr[10000] = {};
  int* matrix = nullptr;
  if (num == '2')
  {
    matrix = static_cast< int * >(malloc(sizeof(int) * rows * cols));
  }
  if (matrix == nullptr && num == '2')
  {
    std::cerr << "Error: Memory allocation failed" << "\n";
    return 2;
  }
  ivanov::write_in((num == '1') ? mtr : matrix, rows, cols, input);
  if (input.fail() || input.eof())
  {
    if (num == '2')
    {
      free(matrix);
    }
    std::cerr << "Input Error\n";
    return 2;
  }
  ivanov::fll_inc_wav((num == '1') ? mtr : matrix, rows, cols);
  output << ivanov::max_sum_mdg((num == '1') ? mtr : matrix, rows, cols) << "\n";
  if (num == '2')
  {
    free(matrix);
  }
  return 0;
}
