#include <cstdlib>
#include <fstream>
#include <iostream>

#include "matrix.hpp"

bool isStringEqual(const char* s1, const char* s2)
{
  size_t i = 0;
  while (s1[i] != '\0' && (s1[i] == s2[i]))
  {
    i++;
  }
  return (s1[i] == '\0' && s2[i] == '\0');
}

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Invalid number of arguments\n";
    return 1;
  }

  if (!isStringEqual(argv[1], "1") && !isStringEqual(argv[1], "2"))
  {
    std::cerr << "First parameter is invalid (must be 1 or 2)\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "Cannot open input file\n";
    return 2;
  }

  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cerr << "Cannot open output file\n";
    return 1;
  }

  size_t rows = 0;
  size_t cols = 0;
  input >> rows >> cols;

  if (input.fail())
  {
    std::cerr << "Cannot read matrix dimensions\n";
    return 2;
  }

  size_t numElements = rows * cols;

  if (numElements == 0)
  {
    output << "0\n0\n";
    return 0;
  }

  int* matrix = nullptr;
  const size_t MAX_STATIC_SIZE = 10000;
  int staticBuffer[MAX_STATIC_SIZE] = {};

  if (isStringEqual(argv[1], "1"))
  {
    if (numElements > MAX_STATIC_SIZE)
    {
      std::cerr << "Static matrix size exceeds limit\n";
      return 2;
    }
    matrix = staticBuffer;
  }
  else
  {
    matrix = reinterpret_cast< int* >(std::malloc(numElements * sizeof(int)));
    if (!matrix)
    {
      std::cerr << "Memory allocation failed\n";
      return 1;
    }
  }

  vasilenko::inputMatrix(input, matrix, numElements);
  if (input.fail())
  {
    std::cerr << "Invalid matrix element data\n";
    if (isStringEqual(argv[1], "2"))
    {
      std::free(matrix);
    }
    return 2;
  }
  input.close();

  output << vasilenko::countColsNsm(matrix, rows, cols) << "\n";
  output << vasilenko::maxSumSdg(matrix, rows, cols) << "\n";
  output.close();

  if (isStringEqual(argv[1], "2"))
  {
    std::free(matrix);
  }

  return 0;
}
