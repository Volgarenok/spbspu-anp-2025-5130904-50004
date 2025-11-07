#include <iostream>
#include <fstream>

void filling(int * array, std::ifstream &
  input, int rows, int cols)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    input >> array[i];
    if (std::cin.fail())
    {
      throw std::invalid_argument("Error:
        file includes the mistake");
    }
  }
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
    (std::malloc(rows * cols * sizeof(int)));
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
  input >> rows >> cols;
  int * array = nullptr;
  if (argv[1][0] == 1)
  {
    work_with_static(rows, cols, input);
  }
  else if (argv[1][0] == 2)
  {
    work_with_dinamic(rows, cols, input);
  }
  else
  {
    throw std::runtime_error("Unknown command\n");
  }
}
