#include <iostream>
#include <fstream>
#include <cstdlib>

namespace velizade
{
  std::istream& readArr(std::istream& input, int* arr, size_t rows, size_t cols);
  std::ostream& writeResult(std::ostream& output, const int* arr, size_t rows, size_t cols, int result);
  int countLocalMins(const int* arr, size_t rows, size_t cols);
  void leftTopClockwise(int* arr, size_t rows, size_t cols);
}

std::istream& velizade::readArr(std::istream& input, int* arr, size_t rows, size_t cols)
{
  int value;
  for (size_t i = 0; i < rows * cols; i++)
  {
    if (!(input >> value))
    {
      std::cerr << "Incorrect matrix input" << "\n";
      return input;
    }
    arr[i] = value;
  }
  return input;
}

std::ostream& velizade::writeResult(std::ostream& output, const int* arr, size_t rows, size_t cols, int result)
{
  output << result;
  if (rows > 0 && cols > 0)
  {
    output << "\n";
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < cols; j++)
      {
        output << arr[i * cols + j];
        if (j < cols - 1) output << " ";
      }
      if (i < rows - 1) output << "\n";
    }
  }
  return output;
}

int velizade::countLocalMins(const int* arr, size_t rows, size_t cols)
{
  if (rows < 3 || cols < 3) 
  {
    return 0;
  }

  int count = 0;
  for (size_t i = 1; i < rows - 1; i++)
  {
    for (size_t j = 1; j < cols - 1; j++)
    {
      int current = arr[i * cols + j];
      bool isLocalMin = true;

      for (int di = -1; di <= 1; di++)
      {
        for (int dj = -1; dj <= 1; dj++)
        {
          if (di == 0 && dj == 0) continue;
          size_t ni = i + di;
          size_t nj = j + dj;
          if (current >= arr[ni * cols + nj])
          {
            isLocalMin = false;
            break;
          }
        }
        if (!isLocalMin) break;
      }

      if (isLocalMin) count++;
    }
  }
  return count;
}

void velizade::leftTopClockwise(int* arr, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0) return;

  int* temp = new int[rows * cols];

  int top = 0, bottom = rows - 1;
  int left = 0, right = cols - 1;
  int decrement = 1;

  while (top <= bottom && left <= right)
  {
    for (int j = left; j <= right; j++)
    {
      arr[top * cols + j] -= decrement++;
    }
    top++;

    for (int i = top; i <= bottom; i++)
    {
      arr[i * cols + right] -= decrement++;
    }
    right--;

    if (top <= bottom)
    {
      for (int j = right; j >= left; j--)
      {
        arr[bottom * cols + j] -= decrement++;
      }
      bottom--;
    }

    if (left <= right)
    {
      for (int i = bottom; i >= top; i--)
      {
        arr[i * cols + left] -= decrement++;
      }
      left++;
    }
  }
}

int main(int argc, char** argv)
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  }
  if (argc < 4)
  {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }

  if (argv[1][1])
  {
    std::cerr << "First parametr must be one character"
    return 1;
  }

  char num = argv[1][0];
  if (num != '1' && num != '2')
  {
    std::cerr << "First parametr out of range or first parametr is not a number" << "\n";
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

  if (!(input >> rows) || !(input >> cols))
  {
    std::cerr << "Incorrect matrix dimensions" << "\n";
    return 2;
  }

  if (num == '1')
  {
    int arr[10000] = {};
    if (!velizade::readArr(input, arr, rows, cols))
    {
      return 2;
    }

    int result = velizade::countLocalMins(arr, rows, cols);
    velizade::writeResult(output, arr, rows, cols, result);
  }
  else
  {
    int* arr = nullptr;
    try
    {
      arr = new int[rows * cols]();
      if (!velizade::readArr(input, arr, rows, cols))
      {
        delete[] arr;
        return 2;
      }

      velizade::leftTopClockwise(arr, rows, cols);
      velizade::writeResult(output, arr, rows, cols, 0);

      delete[] arr;
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "Memory allocation error" << "\n";
      delete[] arr;
      return 2;
    }
  }

  return 0;
}
