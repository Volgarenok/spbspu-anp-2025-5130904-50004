#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matrix.hpp"
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "invalid arguments\n";
    return 1;
  }

  int taskNum = 0;
  try
  {
    taskNum = std::stoi(argv[1]);
  }
  catch (const std::exception&)
  {
    std::cerr << "invalid task number\n";
    return 1;
  }

  if (taskNum != 1 && taskNum != 2)
  {
    std::cerr << "unsupported task number\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "input file error\n";
    return 2;
  }

  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cerr << "output file error\n";
    return 2;
  }

  size_t rows = 0;
  size_t cols = 0;

  if (!(input >> rows >> cols))
  {
    std::cerr << "invalid matrix data\n";
    return 2;
  }

  if (taskNum == 1)
  {
    constexpr size_t MAX = 256;
    if (rows > MAX || cols > MAX)
    {
      std::cerr << "invalid matrix data\n";
      return 2;
    }

    int matrix[MAX * MAX];

    if (rows == 0 || cols == 0)
    {
      output << "0 0";
      return 0;
    }

    if (!oztas::readMatrix(input, matrix, rows, cols))
    {
      std::cerr << "invalid matrix data\n";
      return 2;
    }

    const int result = oztas::countNonZeroDiagonals(matrix, rows, cols);
    output << result;
  }
  else
  {
    if (rows == 0 || cols == 0)
    {
      output << "0 0";
      return 0;
    }

    int* matrix = new (std::nothrow) int[rows * cols];
    if (!matrix)
    {
      std::cerr << "memory allocation error\n";
      return 2;
    }

    if (!oztas::readMatrix(input, matrix, rows, cols))
    {
      delete[] matrix;
      std::cerr << "invalid matrix data\n";
      return 2;
    }

    oztas::applyFillIncreasingWave(matrix, rows, cols);
    oztas::writeMatrix(output, matrix, rows, cols);

    delete[] matrix;
  }

  return 0;
}
