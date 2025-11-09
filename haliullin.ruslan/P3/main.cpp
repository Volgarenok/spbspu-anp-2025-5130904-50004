#include <iostream>
#include <fstream>
namespace haliullin
{
  std::istream& input(std::istream& in, int *arr, size_t rows, size_t cols);
  std::ostream& output(std::ostream& out, const int *arr, size_t rows, size_t cols, size_t res);
  void FllIncrementWave(int *arr, size_t rows, size_t cols);
  size_t NumColLsr(int *arr, size_t rows, size_t cols);
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

  if (argv[1][0] != '1' && argv[1][0] != '2')
  {
    if (!( argv[1][0] >= '0' && argv[1][0] <= '9'))
    {
      std::cerr << "First parameter is not a number" << "\n";
      return 1;
    }
    else
    {
      std::cerr << "First parameter is out of range" << "\n";
      return 1;
    }
  }

  std::ifstream in(argv[2]);
  std::ofstream out(argv[3]);
  namespace hal = haliullin;
  if (argv[1][0] == '1')
  {
    //
  }

  else if (argv[1][0] == '2')
  {
    //
  }

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
    std::cerr << "Unexpected input" << "\n";
  }
  else if (count < rows * cols)
  {
    std::cerr << "Not enough elements" << "\n";
  }
  return in;
}

std::ostream& haliullin::output(std::ostream& out, const int *arr, size_t rows, size_t cols, size_t res)
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

void haliullin::FllIncrementWave(int *arr, size_t rows, size_t cols)
{
}

size_t haliullin::NumColLsr(int *arr, size_t rows, size_t cols)
{
}


