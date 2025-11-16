#include "zinovev.h"
#include <iostream>

std::istream& zinovev::readInput(std::istream& input, int* array, size_t rows, size_t cols)
{
  size_t quantity = 0;

  for (size_t i = 0; i < rows * cols && input >> array[i]; ++i)
  {
    ++quantity;
  }

  if (!input)
  {
    std::cerr << "ERROR: Incorrect input" << "\n";
    std::cerr << "Number of inputted items: " << quantity << "\n";
  }
  else if (rows * cols > quantity)
  {
    std::cerr << "ERROR: Not enough elements have been entered" << "\n";
    std::cerr << "Number of inputted items: " << quantity << "\n";
  }

  return input;
}

void zinovev::fillSpiral(int* array, size_t rows, size_t cols)
{
  int number = 1;
  int position = (rows - 1) * cols;

  for (size_t layer = 0; number <= rows * cols; layer++)
  {
    for (size_t i = 0; i < (cols - 2 * layer) && number <= rows * cols; i++)
    {
      if (position >= 0 && position < rows * cols)
      {
        array[position] += number;
      }
      position++;
      number++;
    }

    if (number > rows * cols)
    {
      break;
    }

    position -= (cols + 1);

    for (size_t i = 0; i < (rows - 2 * layer - 1) && number <= rows * cols; i++)
    {
      if (position >= 0 && position < rows * cols)
      {
        array[position] += number;
      }
      position -= cols;
      number++;
    }

    if (number > rows * cols)
    {
      break;
    }

    position += (cols - 1);

    for (size_t i = 0; i < (cols - 2 * layer - 1) && number <= rows * cols; i++)
    {
      if (position >= 0 && position < rows * cols)
      {
        array[position] += number;
      }
      position--;
      number++;
    }

    if (number > rows * cols)
    {
      break;
    }

    position += (cols + 1);

    for (size_t i = 0; i < (rows - 2 * layer - 2) && number <= rows * cols; i++)
    {
      if (position >= 0 && position < rows * cols)
      {
        array[position] += number;
      }
      position += cols;
      number++;
    }

    position -= (cols - 1);
  }
}

int zinovev::findLongestColumn(int* array, size_t rows, size_t cols)
{
  if (rows == 0)
  {
    return 0;
  }

  int result = 0;
  int maxCount = 0;

  for (size_t column = 0; column < cols; ++column)
  {
    int currentCount = 0;

    for (size_t row = 1; row < rows; ++row)
    {
      if (array[cols * (row - 1) + column] == array[cols * row + column])
      {
        ++currentCount;
      }
    }

    if (currentCount > maxCount)
    {
      maxCount = currentCount;
      result = column + 1;
    }
  }

  return result;
}

std::ostream& zinovev::writeOutput(std::ostream& output, const int* array, size_t rows, size_t cols, int result)
{
  output << result << "\n";

  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      output << array[i * cols + j] << " ";
    }
    output << "\n";
  }

  return output;
}
