#include <iostream>
#include <fstream>
#include <cstdlib>

namespace ivantsova
{
  std::istream & readArr(std::istream & input, int * arr, size_t rows, size_t cols);
  std::ostream & writeArr(std::ostream & output, const int * arr, size_t rows, size_t cols, int result);
  void reduceElements(int * arr, size_t rows, size_t cols);
  int countColumns(int * arr, size_t rows, size_t cols);
}

std::istream & ivantsova::readArr(std::istream & input, int * arr, size_t rows, size_t cols)
{
  int number = 0;
  for (size_t i = 0; i < rows * cols && input >> arr[i]; i++)
  {
    ++number;
  }
  if (!input)
  {
    std::cerr << "Incorrect input" << "\n";
  }
  else if (rows * cols > number)
  {
    std::cerr << "Not enough elements" << "\n";
  }
  return input;
}

std::ostream & ivantsova::writeArr(std::ostream & output, const int * arr, size_t rows, size_t cols, int result)
{
  output << result << "\n";
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      output << arr[i * cols + j] << " ";
    }
    output << "\n";
  }
  return output;
}

void ivantsova::reduceElements(int * arr, size_t rows, size_t cols)
{
}

int ivantsova::countColumns(int * arr, size_t rows, size_t cols)
{
}

int main()
{
}
