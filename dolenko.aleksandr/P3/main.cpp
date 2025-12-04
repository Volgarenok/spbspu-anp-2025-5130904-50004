#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

#include "functions.hpp"

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Wrong number of arguments" << "\n";
    return 1;
  }

  if (!std::isdigit(argv[1][0]) || argv[1][1] != '\0' || argv[1][0] > '2')
  {
    std::cerr << "First parameter is invalid" << "\n";
    return 1;
  }

  int num = argv[1][0] - '0';

  std::ifstream in(argv[2]);
  std::ofstream out(argv[3]);

  if (!in.is_open())
  {
    std::cerr << "Cannot open input file";
    return 2;
  }

  size_t rows = 0;
  size_t cols = 0;

  if (!(in >> rows >> cols))
  {
    std::cerr << "Cannot read matrix dimensions";
    in.close();
    return 2;
  }

  if (num == 1)
  {
    if (rows > dolenko::k_max_rows || cols > dolenko::k_max_cols || rows * cols > dolenko::k_max_fixed_size)
    {
      std::cerr << "Matrix too large for fixed array";
      in.close();
      return 2;
    }
  }

  int* matrix_data = nullptr;

  if (num == 1)
  {
    static int fixed_matrix[dolenko::k_max_rows * dolenko::k_max_cols];
    matrix_data = fixed_matrix;
  }
  else
  {
    matrix_data = static_cast<int*>(std::malloc(rows * cols * sizeof(int)));
    if (matrix_data == nullptr)
    {
      std::cerr << "Memory allocation failed";
      in.close();
      return 2;
    }
  }

  dolenko::read_matrix(in, matrix_data, rows, cols);

  if (!in)
  {
    std::cerr << "Error reading matrix data";
    if (num == 2)
    {
      std::free(matrix_data);
    }
    in.close();
    return 2;
  }

  in.close();

  int local_mins = dolenko::count_local_mins(matrix_data, rows, cols);
  int longest_column = dolenko::find_longest_column(matrix_data, rows, cols);

  if (!out.is_open())
  {
    std::cerr << "Cannot open output file";
    if (num == 2)
    {
      std::free(matrix_data);
    }
    return 1;
  }

  dolenko::write_matrix(out, local_mins);
  out << std::endl;
  dolenko::write_matrix(out, longest_column);
  out << std::endl;

  out.close();

  if (num == 2)
  {
    std::free(matrix_data);
  }

  return 0;
}
