#include <iostream>
#include <fstream>
#include <cstdlib>
namespace haliullin
{
  std::istream& readMatrix(std::istream& in, int *arr, size_t rows, size_t cols);
  void FllIncrementWave(int *arr, size_t rows, size_t cols);
  size_t NumColLsr(const int *arr, size_t rows, size_t cols);
  std::ostream& writeMatrix(std::ostream& out, const int *arr, size_t rows, size_t cols, size_t res);
}

int main(int argc, char **argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }
  else if (argc > 4)
    {
      std::cerr << "Too many arguements" << "\n";
      return 1;
    }

  int temp = 0;
  while (argv[1][temp] != '\0')
  {
    if (!(argv[1][0] >= '0' && argv[1][0] <= '9'))
    {
      std::cerr << "First parameter is not a number" << "\n";
      return 1;
    }
    ++temp;
  }

  if (temp > 1)
  {
      std::cerr << "First parameter is out of range" << "\n";
      return 1;
  }

  std::ifstream in(argv[2]);
  std::ofstream out(argv[3]);
  namespace hal = haliullin;

  size_t rows = 0;
  size_t cols = 0;
  size_t res = 0;
  if (!in.is_open() || !out.is_open())
  {
    std::cerr << "Opening files error" << "\n";
    return 2;
  }
  if (!(in >> rows))
  {
    std::cerr << "Incorrect value for rows" << "\n";
    return 2;
  }
  else if (!(in >> cols))
  {
    std::cerr << "Incorrect value for columns" << "\n";
    return 2;
  }

  if (argv[1][0] == '1')
  {
    if (rows * cols > 10000)
    {
      std::cerr << "Too large size of array" << "\n";
      return 2;
    }

    int arr[10000] = {};
    hal::readMatrix(in, arr, rows, cols);

    if (!in)
    {
      std::cerr << "Error of reading array" << "\n";
      return 2;
    }


    in.close();

    hal::FllIncrementWave(arr, rows, cols);
    res = hal::NumColLsr(arr, rows, cols);
    hal::writeMatrix(out, arr, rows, cols, res);

  }


  else if (argv[1][0] == '2')
  {
    int *arr = nullptr;
    try
    {
      arr = new int[rows*cols];
      hal::readMatrix(in, arr, rows, cols);

      if (!in)
      {
        std::cerr  << "Error of reading array" << "\n";
        delete[] arr;
        return 1;
      }

      in.close();

      hal::FllIncrementWave(arr, rows, cols);
      res = hal::NumColLsr(arr, rows, cols);
      hal::writeMatrix(out, arr, rows, cols, res);

      delete[] arr;

    }
    catch(const std::bad_alloc &e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
  }
  return 0;

}
std::istream& haliullin::readMatrix(std::istream& in, int *arr, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t i = 0; i < rows*cols && in >> arr[i]; ++i)
  {
    ++count;
  }
  if (!in)
  {
    std::cerr << "Unexpected input" << "\n";
  }
  else if (count < rows * cols)
  {
    std::cerr << "Not enough elements" << "\n";
  }
  return in;
}

void haliullin::FllIncrementWave(int *arr, size_t rows, size_t cols)
{
  (void)arr;
  (void)rows;
  (void)cols;
}

size_t haliullin::NumColLsr(const int *arr, size_t rows, size_t cols)
{
  size_t res = 0;
  size_t cur_length = 1;
  size_t max_length = 1;
  size_t max_length_total = 1;
  int prev = 0;
  for (size_t j = 0; j < cols; ++j)
  {
    cur_length = 1;
    max_length = 1;
    for (size_t i = 1; i < rows; ++i)
    {
      int cur = arr[i * cols + j];
      prev = arr[(i-1) * cols + j];

      if (cur == prev)
      {
        ++cur_length;
        max_length = std::max(cur_length, max_length);
      }
      else
      {
        cur_length = 1;
      }
    }

    if (max_length > max_length_total)
    {
      max_length_total = max_length;
      res = j;
    }
  }
  return res;
}


std::ostream& haliullin::writeMatrix(std::ostream& out, const int *arr, size_t rows, size_t cols, size_t res)
{
  out << res << "\n";
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols-1; ++j)
    {
      out << arr[i * cols + j] << " ";
    }
    out << arr[i * cols + cols - 1] << "\n";
  }
  return out;
}
