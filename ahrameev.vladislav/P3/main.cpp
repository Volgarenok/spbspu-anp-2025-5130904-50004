#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstdlib>
#include "matrix.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: wrong arguments count\n";
    return 1;
  }

  int mode = std::atoi(argv[1]);
  if (mode != 1 && mode != 2)
  {
    std::cerr << "Error: wrong mode\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);

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

  if (rows == 0 || cols == 0)
  {
    output << rows << " " << cols << "\n";
    return 0;
  }

  int* src = nullptr;
  int* dst = nullptr;

  if (mode == 1)
  {
    if (rows * cols > 10000)
    {
      std::cerr << "Error: matrix too large\n";
      return 2;
    }

    static int static_src[10000];
    static int static_dst[10000];

    src = static_src;
    dst = static_dst;
  }
  else
  {
    src = new int[rows * cols];
    dst = new int[rows * cols];
  }

  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (!(input >> src[i]))
    {
      if (mode == 2)
      {
        delete[] src;
        delete[] dst;
      }
      std::cerr << "Error: invalid matrix data\n";
      return 2;
    }
  }

  bool is_lower = ahrameev::is_upper_triangular(src, rows, cols);
  output << std::boolalpha << is_lower << "\n";

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

  if (mode == 2)
  {
    delete[] src;
    delete[] dst;
  }

  return 0;
}
