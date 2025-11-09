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
  size_t number = 0;
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
  size_t t = rows * cols;
  int * temp = new int [t];
  for (size_t i = 0; i < t; i++)
  {
    temp[i] = arr[i];
  }
  int left = 0;
  int right = cols - 1;
  int up = 0;
  int down = rows - 1;
  int step = 1;
  while (left <= right && up <= down)
  {
    for (int i = down; i >= up; i--)
    {
      size_t index = i * cols + left;
      temp[index] -= step++;
    }
    left++;
    if (left > right)
    {
      break;
    }
    for (int i = left; i <= right; i++)
    {
      size_t index = up * cols + i;
      temp[index] -= step++;
    }
    up++;
    if (up > down)
    {
      break;
    }
    for (int i = up; i <= down; i++)
    {
      size_t index = i * cols + right;
      temp[index] -= step++;
    }
    right--;
    if (left > right)
    {
      break;
    }
    for (int i = right; i >= left; i--)
    {
      size_t index = down * cols + i;
      temp[index] -= step++;
    }
    down--;
  }
  for (size_t i = 0; i < t; i++)
  {
    arr[i] = temp[i];
  }
  delete[] temp;
}

int ivantsova::countColumns(int * arr, size_t rows, size_t cols)
{
  int count = 0;
  for (size_t j = 0; j < cols; j++)
  {
    bool rep = false;
    for (size_t i = 0; i + 1 < rows; i++)
    {
      if (arr[i * cols + j] == arr[(i + 1) * cols + j])
      {
        rep = true;
        break;
      }
    }
    if (!rep)
    {
      count++;
    }
  }
  return count;
}

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
    int * arr_copy = nullptr;
    try
    {
      arr = new int [rows * cols] {};
      ivantsova::readArr(input, arr, rows, cols);
      if (!input)
      {
        delete[] arr;
        return 2;
      }
      input.close();
      arr_copy = new int [rows * cols]();
      for (size_t i = 0; i < rows * cols; i++)
      {
        arr_copy[i] = arr[i];
      }
      result = ivantsova::countColumns(arr_copy, rows, cols);
      ivantsova::reduceElements(arr, rows, cols);
      ivantsova::writeArr(output, arr, rows, cols, result);
      delete[] arr_copy;
      delete[] arr;
    }
    catch (...)
    {
      std::cerr << "Error" << "\n";
      delete[] arr;
      return 1;
    }
  }
  return 0;
}
