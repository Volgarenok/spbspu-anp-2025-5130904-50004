#include <iostream>
#include <fstream>

namespace haliullin
{
  std::istream& input(std::istream& in, int *arr, size_t rows, size_t cols);
  std::ostream& output(std::ostream& out, const int *arr, size_t rows, size_t cols, size_t res);
  void FllIncrementWave(int *arr, size_t rows, size_t cols);
  void cutToSquare(int *arr, size_t rows, size_t cols);
  int NumColLsr(int *arr, size_t rows, size_t cols);
}

int main(int argc, char **argv)
{
}

std::istream& haliullin::input(std::istream& in, int *arr, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t i = 0; i < rows*cols && in >> arr[i]; ++i)
  {
    ++count;
  }
  if (!in)
  {
    std::cerr << "Unexpected input\n";
  }
  else if (count < rows * cols)
  {
    std::cerr << "Not enough elements\n";
  }
  return in;
}

std::ostream& haliullin::output(std::ostream& out, const int *arr, size_t rows, size_t cols, size_t res)
{
}

void haliullin::FllIncrementWave(int *arr, size_t rows, size_t cols)
{
}

void haliullin::cutToSquare(int *arr, size_t rows, size_t cols)
{
}

int haliullin::NumColLsr(int *arr, size_t rows, size_t cols)
{
}


