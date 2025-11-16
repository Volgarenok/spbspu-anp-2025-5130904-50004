#include <iostream>
#include <fstream>
#include <cctype>
#include "matrix_functions.hpp"
int main(int argc, char **argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  }

  size_t temp = 0;
  while (argv[1][temp] != '\0')
  {
    if (!(std::isdigit(argv[1][temp])))
    {
      std::cerr << "First parameter is not a number" << "\n";
      return 1;
    }
    ++temp;
  }
  if ((temp > 1) || (argv[1][0] > '2'))
  {
    std::cerr << "First parameter is out of range" << "\n";
    return 1;
  }

  std::ifstream in(argv[2]);
  std::ofstream out(argv[3]);

  size_t rows = 0;
  size_t cols = 0;
  size_t res = 0;
  if (!in.is_open() || !out.is_open())
  {
    std::cerr << "Opening files error" << "\n";
    return 2;
  }
  if (!(in >> rows))
  {
    std::cerr << "Incorrect value for rows" << "\n";
    return 2;
  }
  else if (!(in >> cols))
  {
    std::cerr << "Incorrect value for columns" << "\n";
    return 2;
  }
  if ((rows == 0) && (cols == 0))
  {
    haliullin::writeMatrix(out, nullptr, 0, 0, 0);
    return 0;
  }

  int stArr[10000] = {};
  int *arr = nullptr;
  bool is_dynamic = (argv[1][0] == '2');
  if (is_dynamic)
  {
    try
    {
      arr = new int[rows * cols];
    }
    catch(const std::bad_alloc &e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
  }
  else
  {
    arr = stArr;
  }

  haliullin::readMatrix(in, arr, rows, cols);
  if (!in)
  {
    std::cerr << "Error of reading array" << "\n";
    if (is_dynamic)
    {
      delete[] arr;
    }
    return 1;
  }
  in.close();

  haliullin::FllIncrementWave(arr, rows, cols);
  res = haliullin::NumColLsr(arr, rows, cols);
  haliullin::writeMatrix(out, arr, rows, cols, res);

  return 0;
}
