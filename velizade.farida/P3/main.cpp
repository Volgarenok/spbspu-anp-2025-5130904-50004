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
  for (size_t i = 0; i < rows * cols; i++)
  {
    if (!(input >> arr[i]))
    {
      std::cerr << "Incorrect matrix input" << "\n";
      return input;
    }
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
  if (rows < 3 || cols < 3) return 0;

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

int main()
{
}
