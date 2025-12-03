#include "functions.hpp"
#include <iostream>
#include <fstream>

void khairullin::filling(int * array, std::ifstream & input, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    input >> array[i];
  }
}
int khairullin::checkZero(const int * array, size_t index1, size_t index2, size_t size)
{
  if (array[index1 * size + index2] == array[index1 * size + index2 + 1] && array[index1 * size + index2] == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int khairullin::localMax(const int * array, size_t rows, size_t cols)
{
  int counter_of_max = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (i != 0 && j != 0 && i != rows - 1 && j != cols - 1)
      {
        if (array[i * cols + j] > array[(i - 1) * cols + j] && array[i * cols + j] > array[(i + 1) * cols + j]
            && array[i * cols + j] > array[i * cols + j - 1] && array[i * cols + j] > array[i * cols + j + 1])
        {
          counter_of_max++;
        }
      }
    }
  }
  return counter_of_max;
}
bool khairullin::triangle(const int * array, size_t size)
{
  size_t sum_of_zeroes = 0;
  size_t count_of_nulls_on_row = size - 1;
  size_t counter = 0;
  const size_t COUNT_OF_ROWS_WITH_ZEROES = size - 1;
  for (size_t i = 0; i < COUNT_OF_ROWS_WITH_ZEROES; ++i)
  {
    for (size_t j = 0; j < size; ++j)
    {
      if (j < size)
      {
        counter += checkZero(array, i, j, size);
      }
    }
    if (count_of_nulls_on_row - 1 == counter)
    {
      sum_of_zeroes++;
      counter = 0;
      count_of_nulls_on_row--;
    }
  }
  return (sum_of_zeroes == COUNT_OF_ROWS_WITH_ZEROES);
}
int khairullin::check_arguments(int argc, char ** argv)
{
  int command = argv[1][0] - '0';
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  else if (argv[1][1] != '\0')
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  else if (command > 2 || command < 1)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  return 0;
}
