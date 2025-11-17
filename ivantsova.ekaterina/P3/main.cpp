#include "func.hpp"
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
    std::cerr << "Not enough arguments" <<"\n";
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
  size_t rows = 0;
  size_t cols = 0;
  int result = 0;
  if (!(input >> rows))
  {
    std::cerr << "Incorrect number of rows" << "\n";
    return 2;
  }
  else if (!(input >>cols))
  {
    std::cerr << "Incorrect number of columns" << "\n";
    return 2;
  }
  if (argv[1][0] == '1')
  {
    if (rows * cols > 10000)
    {
      std::cerr << "Too large matrix" << "\n";
      return 2;
    }
    int arr[10000] = {};
    ivantsova::readArr(input, arr, rows, cols);
    if (!input)
    {
      return 2;
    }
    input.close();
    int arr_copy[10000];
    for (size_t i = 0; i < rows * cols; i++)
    {
      arr_copy[i] = arr[i];
    }
    result = ivantsova::countColumns(arr_copy, rows, cols);
    ivantsova::reduceElements(arr, rows, cols);
    ivantsova::writeArr(output, arr, rows, cols, result);
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
      std::cerr << e.what() << "\n";
      return 1;
    }
    ivantsova::readArr(input, arr, rows, cols);
    if (!input)
    {
      delete[] arr;
      return 2;
    }
    input.close();
    result = ivantsova::countColumns(arr, rows, cols);
    ivantsova::reduceElements(arr, rows, cols);
    ivantsova::writeArr(output, arr, rows, cols, result);
    delete[] arr;
  }
  return 0;
}
