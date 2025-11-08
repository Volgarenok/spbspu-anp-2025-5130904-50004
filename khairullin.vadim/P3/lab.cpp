#include <iostream>
#include <fstream>

void filling(int * array, std::ifstream &
  input, int rows, int cols)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (std::cin.fail() or std::cin.eof())
    {
      throw std::invalid_argument("Error:
        file includes the mistake");
    }
    input >> array[i];
  }
}

int check_arguments(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments";
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments";
  }
  else if (argv[1][0] > 2 or argv[1][0] < 1)
  {
    std::cerr << "First parameter is out of range";
  }
  else
  {
    std::cerr << "First parameter is not a number";
  }
  return 1;
}

void work_with_static(int rows, int cols,
  std::ifstream & input)
{
  int array[10000] = {};
  filling(array, input, rows, cols);
}

void worl_with_dinamic(int rows, int cols,
  std::ifstream & input)
{
  int * array = reinterpret_cast<int *> 
    (std::malloc(rows * cols *
      sizeof(int)));
  if (array == nullptr)
  {
    throw std::bad_alloc();
  }
  filling(array, input, rows, cols);
}

int main (int argc, char ** argv)
{
  int rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  input >> rows >> cols;
  check_arguments(argc, argv);
  if (rows != 0 and cols != 0)
  {
    if (argv[1][0] == 1)
    {
      work_with_static(rows, cols, input);
    }
    else if (argv[1][0] == 2)
    {
      work_with_dinamic(rows, cols, input);
    }
  }
  else if ((rows == 0 and cols != 0) or
    (rows != 0 and cols == 0))
  {
    throw std::runtime_error("Invalid rows or columns");
  }
  else if (rows == 0 and cols == 0)
  {
    output << "Count of local maximums - 0\n";
    output << "False";
  }
}
