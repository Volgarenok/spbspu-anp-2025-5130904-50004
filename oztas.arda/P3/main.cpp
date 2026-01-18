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
  catch (const std::invalid_argument&)
  {
    std::cerr << "invalid task number\n";
    return 1;
  }
  catch (const std::out_of_range&)
  {
    std::cerr << "task number out of range\n";
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

  if (rows == 0 || cols == 0)
  {
    output << "0 0";
    return 0;
  }

  if (taskNum == 1)
  {
    int* matrix = new int[rows * cols];

    if (!oztas::readMatrix(input, matrix, rows, cols))
    {
      std::cerr << "invalid matrix data\n";
      delete[] matrix;
      return 2;
    }

    const int result = oztas::countNonZeroDiagonals(matrix, rows, cols);
    output << result;
    delete[] matrix;
  }
  else
  {
    constexpr size_t max = 256;
    if (rows > max || cols > max)
    {
      std::cerr << "invalid matrix data\n";
      return 2;
    }

    int matrix[max * max];

    if (!oztas::readMatrix(input, matrix, rows, cols))
    {
      std::cerr << "invalid matrix data\n";
      return 2;
    }

    oztas::applyFillIncreasingWave(matrix, rows, cols);
    oztas::writeMatrix(output, matrix, rows, cols);
  }

  return 0;
}
