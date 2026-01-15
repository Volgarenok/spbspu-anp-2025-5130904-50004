#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

namespace khair = khairullin;
int main(int argc, char ** argv)
{
  if (argc == 1)
  {
    std::cerr << "No arguments\n";
    return 1;
  }
  if (khair::check_arguments(argc, argv))
  {
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  int rows = 0, cols = 0;
  input >> rows >> cols;
  if (input.fail() || !input)
  {
    std::cerr << "File is empty\n";
    return 2;
  }
  const size_t MIN_SIZE = std::min(rows, cols);
  const size_t MAX_SIZE = std::max(rows, cols);
  int * matrix = nullptr;
  int * square_matrix = nullptr;
  int fixed_array[10000] = {};
  int fixed_square_array[10000] = {};
  int * array = reinterpret_cast< int * > (std::malloc(rows * cols * sizeof(int)));
  int * square_array =  reinterpret_cast< int * > (std::malloc(MIN_SIZE * MIN_SIZE * sizeof(int)));
  if (!rows || !cols)
  {
    output << 0 << "\n";
    output << std::boolalpha;
    output << true << "\n";
    free(square_array);
    free(array);
    return 0;
  }
  else if (rows < 0 || cols < 0)
  {
    std::cerr << "Invalid rows or columns\n";
    free(square_array);
    free(array);
    return 2;
  }
  if (argv[1][0] == '1')
  {
    matrix = fixed_array;
    square_matrix = fixed_square_array;
  }
  else if (argv[1][0] == '2')
  {
    matrix = array;
    if (!matrix)
    {
      std::cerr << "Bad alloc\n";
      return 2;
    }
    square_matrix = square_array;
    if (!square_matrix)
    {
      std::cerr << "Bad alloc\n";
      free(array);
      return 2;
    }
  }
  khair::fill(matrix, input, rows, cols);
  if (input.fail())
  {
    std::cout << "Not enough elements\n";
    free(array);
    free(square_array);
    return 2;
  }
  input.close();
  output << khair::findLocalMax(matrix, rows, cols) << "\n";
  for (size_t i = 0; i < MIN_SIZE; i++)
  {
    for (size_t j = 0; j < MIN_SIZE; ++j)
    {
      square_matrix[MIN_SIZE * i + j] = matrix[MAX_SIZE * i + j];
    }
  }
  output << std::boolalpha;
  output << khair::checkTriangle(square_matrix, MIN_SIZE) << "\n";
  free(array);
  free(square_array);
}
