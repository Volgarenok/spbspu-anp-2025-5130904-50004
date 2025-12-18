#include "matrix.hpp"
#include <iostream>
#include <fstream>

void khairullin::fill(int * array, std::ifstream & input, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    input >> array[i];
  }
}
int khairullin::checkZero(const int * array, size_t index1, size_t index2, size_t size)
{
  bool left_element = false;
  left_element = array[index1 * size + index2];
  bool right_element = false;
  right_element = array[index1 * size + index2 + 1];
  return left_element == right_element && left_element == 0;
}
int khairullin::findLocalMax(const int * array, size_t rows, size_t cols)
{
  int counter_of_max = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (i != 0 && j != 0 && i != rows - 1 && j != cols - 1)
      {
        bool localmax = false;
        localmax = array[i * cols + j] > array[(i - 1) * cols + j];
        localmax = localmax && array[i * cols + j] > array[(i + 1) * cols + j];
        localmax = localmax && array[i * cols + j] > array[i * cols + j - 1];
        localmax = localmax && array[i * cols + j] > array[i * cols + j + 1];
        if (localmax)
        {
          counter_of_max++;
        }
      }
    }
  }
  return counter_of_max;
}
bool khairullin::checkTriangle(const int * array, size_t size)
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
