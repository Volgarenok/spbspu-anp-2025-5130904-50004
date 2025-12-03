#include "functions.hpp"
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
  const size_t MIN_SIZE = std::min(rows, cols);
  const size_t MAX_SIZE = std::max(rows, cols);
  int * array = nullptr;
  int * square_array = nullptr;
  int static_array[10000] = {};
  int static_square_array[10000] = {};
  if (!input)
  {
    std::cerr << "File is empty\n";
    return 2;
  }
  else if (rows < 0 || cols < 0)
  {
    std::cerr << "Invalid rows or columns\n";
    return 2;
  }
  else if (rows != 0 && cols != 0)
  {
    if (argv[1][0] == '1')
    {
      array = static_array;
      square_array = static_square_array;
    }
    else if (argv[1][0] == '2')
    {
      array = reinterpret_cast< int * > (std::malloc(rows * cols * sizeof(int)));
      if (array == nullptr)
      {
        std::cerr << "Bad alloc\n";
        return 2;
      }
      square_array = reinterpret_cast< int * > (std::malloc(MIN_SIZE * MIN_SIZE * sizeof(int)));
      if (square_array == nullptr)
      {
        std::cerr << "Bad alloc\n";
        free(array);
        return 2;
      }
    }
    try
    {
      khair::filling(array, input, rows, cols);
    }
    catch (const std::logic_error & err)
    {
      std::cout << err.what() << "\n";
      if (argv[1][0] == '2')
      {
        free(array);
      }
      return 1;
    }
    input.close();
    output << khair::localMax(array, rows, cols) << "\n";
    for (size_t i = 0; i < MIN_SIZE; i++)
    {
      for (size_t j = 0; j < MIN_SIZE; ++j)
      {
        square_array[MIN_SIZE * i + j] = array[MAX_SIZE * i + j];
      }
    }
    if (khair::triangle(square_array, MIN_SIZE))
    {
      output << "True\n";
    }
    else
    {
      output << "False\n";
    }
    if (argv[1][0] == '2')
    {
      free(array);
      free(square_array);
    }
  }
  else if (rows == 0 && cols == 0)
  {
    output << "Count of local maximums - 0\n";
    output << "False\n";
  }
}
