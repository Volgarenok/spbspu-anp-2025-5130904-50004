#include "functions.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

namespace khair = khairullin;
int main (int argc, char ** argv)
{
  int command = 0;
  if (argc != 1)
  {
    command = argv[1][0] - '0';
  }
  else
  {
    std::cerr << "No arguments\n";
    return 1;
  }
  try
  {
    if (khair::check_arguments(argc, argv, command))
    {
      return 1;
    }
    std::ifstream input(argv[2]);
    std::ofstream output(argv[3]);
    int rows = 0, cols = 0;
    input >> rows >> cols;
    const int MIN_SIZE = std::min(rows, cols);
    const int MAX_SIZE = std::max(rows, cols);
    if (!input)
    {
      std::cerr << "File is empty\n";
      return 2;
    }
    else if ((rows == 0 and cols != 0) || (rows != 0 and cols == 0) || (rows < 0 or cols < 0))
    {
      std::cerr << "Invalid rows or columns\n";
      return 2;
    }
    else if (rows != 0 and cols != 0)
    {
      if (argv[1][0] == '1')
      {
        int array[10000] = {};
        khair::filling(array, input, rows, cols, command);
        output << khairullin::localmax(array, rows, cols) << "\n";
        int square_array[10000] = {};
        for (int i = 0; i < MIN_SIZE; ++i)
        {
          for (int j = 0; j < MIN_SIZE; ++j)
          {
              square_array[i * MIN_SIZE + j] = array[i * MAX_SIZE + j];
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
      }
      else if (argv[1][0] == '2')
      {
        int * array = reinterpret_cast<int *> (std::malloc(rows * cols * sizeof(int)));
        if (array == nullptr)
        {
          std::cerr << "Bad alloc\n";
          return 2;
        }
        khair::filling(array, input, rows, cols, command);
        output << khair::localmax(array, rows, cols) << "\n";
        int * square_array = reinterpret_cast<int *>(std::malloc(MIN_SIZE * MIN_SIZE * sizeof(int)));
        if (square_array == nullptr)
        {
          free(array);
          std::cerr << "Bad alloc\n";
          return 2;
        }
        for (int i = 0; i < MIN_SIZE; i++)
        {
          for (int j = 0; j < MIN_SIZE; ++j)
          {
            square_array[MIN_SIZE * i + j] = array[MAX_SIZE * i + j];
          }
        }
        free(array);
        if (khair::triangle(square_array, MIN_SIZE))
        {
          output << "True\n";
        }
        else
        {
          output << "False\n";
        }
        free(square_array);
      }
    }
    else if (rows == 0 and cols == 0)
    {
      output << "Count of local maximums - 0\n";
      output << "False\n";
    }
  }
  catch(const std::invalid_argument & msg)
  {
    std::cerr << "ERROR: " << msg.what() << "\n";
    return 2;
  }
  catch(...)
  {
    std::cerr << "Error\n";
    return 2;
  }
}
