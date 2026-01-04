#include <iostream>
#include <fstream>
#include <cstddef>
#include <new>
#include "matrix.hpp"

int main(int argc, char** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }

  if (!argv[1] || argv[1][0] == '\0' || argv[1][1] != '\0')
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  if (argv[1][0] < '1' || argv[1][0] > '2')
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  int variant = argv[1][0] - '0';

  std::ifstream in(argv[2]);
  std::ofstream out(argv[3]);

  if (!in)
  {
    std::cerr << "Cannot open input file\n";
    return 2;
  }
  if (!out)
  {
    std::cerr << "Cannot open output file\n";
    return 2;
  }

  size_t r = 0;
  size_t c = 0;

  if (!(in >> r >> c))
  {
    std::cerr << "File is empty\n";
    return 2;
  }

  if ((r == 0 && c != 0) || (r != 0 && c == 0))
  {
    std::cerr << "Invalid rows or columns\n";
    return 2;
  }

  if (r == 0 && c == 0)
  {
    out << 0 << "\n";
    out << 0 << "\n";
    return 0;
  }

  constexpr size_t MAX = 10000;
  size_t count = r * c;

  int* a = nullptr;
  int staticArray[MAX];

  if (variant == 1)
  {

    a = staticArray;
  }
  else
  {
    try
    {
      a = new int[count];
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "ERROR: Memory allocation failed\n";
      return 2;
    }
  }

  aydogan::readMatrix(in, a, count);
  if (!in)
  {
    if (variant == 2)
    {
      delete[] a;
    }
    std::cerr << "ERROR: Input error\n";
    return 2;
  }

  out << aydogan::numColLsr(r, c, a) << "\n";
  out << aydogan::minSumMDG(r, c, a) << "\n";

  if (variant == 2)
  {
    delete[] a;
  }

  return 0;
}
