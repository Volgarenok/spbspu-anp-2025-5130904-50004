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

  char num = argv[1][0];
  if (argv[1][1] != '\0' && num != '1' && num != '2')
  {
    std::cerr << "Incorrect first parametr" << "\n";
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
  int static_arr[10000] = {};
  int* arr = nullptr;
  if (num == '1')
  {
    arr = static_arr;
  }
  else
  {
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
  }
  if (!velizade::readArr(input, arr, rows, cols))
  {
    std::cerr << "Error reading matrix data" << "\n";
    if (num == '2')
    {
      delete[] arr;
    }
    input.close();
    output.close();
    return 2;
  }
  size_t local_mins_count = velizade::countLocalMins(arr, rows, cols);
  velizade::leftTopClockwise(arr, rows, cols);
  velizade::writeResult(output, arr, rows, cols, local_mins_count);
  if (num == '2')
  {
    delete[] arr;
  }
  input.close();
  output.close();
  return 0;
}
