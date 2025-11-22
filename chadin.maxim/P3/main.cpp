#include "matrix_actions.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
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

}
