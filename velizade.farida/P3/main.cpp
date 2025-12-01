#include "matrix_operations.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char** argv)
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
  if (argv[1][1])
  {
    std::cerr << "First parametr must be one character" << "\n";
    return 1;
  }

  char num = argv[1][0];
  if (num != '1' && num != '2')
  {
    std::cerr << "First parametr out of range or first parametr is not a number" << "\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);

  size_t rows = 0;
  size_t cols = 0;

  if (!input.is_open() || !output.is_open())
  {
    std::cerr << "Error opening files" << "\n";
    return 1;
  }

  if (!(input >> rows) || !(input >> cols))
  {
    std::cerr << "Incorrect matrix dimensions" << "\n";
    input.close();
    output.close();
    return 2;
  }

  if (num == '1')
  {
    int arr[10000] = {};
    if (!velizade::readArr(input, arr, rows, cols))
    {
      input.close();
      output.close();
      return 2;
    }

    velizade::processArray(num, arr, rows, cols, output);
  }
  else
  {
    int* arr = nullptr;
    try
    {
      arr = new int[rows * cols]();
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "Memory allocation error" << "\n";
      input.close();
      output.close();
      return 2;
    }
    if (!velizade::readArr(input, arr, rows, cols))
    {
      delete[] arr;
      input.close();
      output.close();
      return 2;
    }
    velizade::processArray(num, arr, rows, cols, output);
    delete[] arr;
  }
  input.close();
  output.close();
  return 0;
}
