#include "matrix.hpp"
#include <iostream>

int main(int argc, char ** argv)
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
  if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
  {
    std::cerr << "First parameter is out of range or first parameter is not a number" << "\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  if (!input.is_open() || !output.is_open())
  {
    std::cerr << "Error opening files" << "\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Incorrect number of rows or cols" << "\n";
    return 2;
  }
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  if (argv[1][0] == '1')
  {
    int arr[10000] = {};
    ivantsova::workWithArray(input, output, arr, rows, cols);
    if (!input)
    {
      std::cerr << "Incorrect input" << "\n";
      return 2;
    }
  }
  else if (argv[1][0] == '2')
  {
    int * arr = nullptr;
    try
    {
      arr = new int [rows * cols] {};
    }
    catch (std::bad_alloc & e)
    {
      std::cerr << "Memory allocation error" << e.what() << "\n";
      return 1;
    }
    ivantsova::workWithArray(input, output, arr, rows, cols);
    if (!input)
    {
      delete[] arr;
      std::cerr << "Incorrect input" << "\n";
      return 2;
    }
    delete[] arr;
  }
  return 0;
}
