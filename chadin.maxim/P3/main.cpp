#include "matrix_actions.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    if (argc < 4)
    {
      std::cerr << "Not enough arguments" << "\n";
    }
    else
    {
      std::cerr << "Too many arguments" << "\n";
    }
    return 1;
  }

  if (argv[1][0] != '1' && argv[1][0] != '2')
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

  std::size_t rows = 0;
  std::size_t cols = 0;
  if (!(input >> rows) || !(input >> cols))
  {
    std::cerr << "Incorrect number of rows or columns" << "\n";
    return 2;
  }

  if (argv[1][0] == '1')
  {
    if (rows > 10000 || cols > 10000 || rows * cols > 10000)
    {
      std::cerr << "Too large matrix" << "\n";
      return 2;
    }
    int arr[10000] = {};
    chadin::readArr(input, arr, rows, cols);
    if (!input)
    {
      std::cerr << "Incorrect input" << "\n";
      return 2;
    }
    input.close();

    int result = chadin::countDiagonals(arr, rows, cols);
    chadin::writeArr(output, arr, rows, cols, result);
  }

  else if (argv[1][0] == '2')
  {
    std::size_t total = rows * cols;
    if (rows != 0 && total / rows != cols)
    {
      std::cerr << "Too large matrix" << "\n";
      return 2;
    }

    int* arr = nullptr;
    if (total > 0)
    {
      try
      {
        arr = new int[total] {};
      }
      catch (const std::bad_alloc&)
      {
        std::cerr << "Error" << "\n";
        return 1;
      }
    }

    chadin::readArr(input, arr, rows, cols);
    if (!input)
    {
      std::cerr << "Incorrect input" << "\n";
      delete[] arr;
      return 2;
    }
    input.close();

    chadin::increaseElements(arr, rows, cols);
    chadin::writeArr(output, arr, rows, cols, 0);

    delete[] arr;
  }

  return 0;
}
