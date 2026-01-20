#include <iostream>
#include <fstream>
#include <cstddef>
#include "matrix.h"

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    std::cerr << "Error: wrong arguments count\n";
    return 1;
  }

  std::ifstream input(argv[1]);
  std::ofstream output(argv[2]);

  if (!input || !output)
  {
    std::cerr << "Error: cannot open files\n";
    return 1;
  }

  size_t rows = 0;
  size_t cols = 0;

  if (!(input >> rows >> cols))
  {
    std::cerr << "Error: invalid matrix size\n";
    return 2;
  }

  int* src = new int[rows * cols];

  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (!(input >> src[i]))
    {
      delete[] src;
      std::cerr << "Error: invalid matrix data\n";
      return 2;
    }
  }

  bool triangular = ahrameev::is_upper_triangular(src, rows, cols);
  output << std::boolalpha << triangular << "\n";

  int* dst = new int[rows * cols];

  ahrameev::build_spiral(src, dst, rows, cols);

  output << rows << " " << cols << "\n";

  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      output << dst[i * cols + j] << " ";
    }
    output << "\n";
  }

  delete[] dst;
  delete[] src;

  return 0;
}

