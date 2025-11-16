#include "functions.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[])
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  }
  if (argc < 4)
  {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }
  int num = 0;
  char* endp = nullptr;
  long res = 0;
  res = std::strtol(argv[1], &endp, 10);
  if (endp == argv[1] || *endp != '\0')
  {
    std::cerr << "First parameter is not a number" << "\n";
    return 1;
  }
  num = static_cast<int>(res);
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range" << "\n";
    return 1;
  }
    std::ifstream in(argv[2]);
  if (!in.is_open())
  {
    std::cerr << "Cannot open input file" << "\n";
    return 2;
  }

  std::ofstream out(argv[3]);
  if (!out.is_open())
  {
    std::cerr << "Cannot open output file" << "\n";
    return 2;
  }

  size_t rows = 0;
  size_t cols = 0;

  if (!(in >> rows >> cols))
  {
    std::cerr << "Cannot read matrix dimensions" << "\n";
    return 2;
  }

  if (rows == 0 || cols == 0)
  {
    kuchukbaeva::writeMatrix(out, nullptr, 0, 0, 0);
    return 0;
  }

  const size_t matrixSize = rows * cols;
  int* matrix = nullptr;
  int static_matrix[10000] = {};
  if (num == 1)
  {
    matrix = static_matrix;
  }
  else
  {
    matrix = static_cast<int*>(malloc(matrixSize * sizeof(int)));
    if (matrix == nullptr)
    {
      std::cerr << "Troubles with memory" << "\n";
      return 2;
    }
  }

  if (!kuchukbaeva::readMatrix(in, matrix, rows, cols))
  {
    std::cerr << "Cannot reading matrix" << "\n";
    in.close();
    if (num == 2)
    {
      free(matrix);
    }
    return 2;
  }
  in.close();
  int locMaxCount = kuchukbaeva::countLocMax(matrix, rows, cols);
  kuchukbaeva::LftBotClk(matrix, rows, cols);
  kuchukbaeva::writeMatrix(out, matrix, rows, cols, locMaxCount);
  if (num == 2)
  {
    free(matrix);
  }

  return 0;
}

