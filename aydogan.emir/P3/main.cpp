#include <iostream>
#include <fstream>
#include <cstddef>
#include <exception>
#include <stdexcept>
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

  if (argv[1][0] < '0' || argv[1][0] > '9')
  {
    std::cerr << "First parameter is not a number\n";
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

  int r = 0;
  int c = 0;

  if (!(in >> r >> c))
  {
    std::cerr << "File is empty\n";
    return 2;
  }

  if ((r == 0 && c != 0) || (r != 0 && c == 0) || (r < 0 || c < 0))
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

  try
  {
    size_t count = static_cast< size_t >(r) * static_cast< size_t >(c);

    if (variant == 1)
    {
      constexpr size_t MAX = 10000;
      int a[MAX];

      aydogan::readMatrix(in, a, static_cast< int >(count));
      if (!in)
      {
        throw std::logic_error("Input error");
      }

      out << aydogan::numColLsr(r, c, a) << "\n";
      out << aydogan::minSumMDG(r, c, a) << "\n";
    }
    else
    {
      int* a = new int[count];

      aydogan::readMatrix(in, a, static_cast< int >(count));
      if (!in)
      {
        delete[] a;
        throw std::logic_error("Input error");
      }

      out << aydogan::numColLsr(r, c, a) << "\n";
      out << aydogan::minSumMDG(r, c, a) << "\n";

      delete[] a;
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << "ERROR: " << e.what() << "\n";
    return 2;
  }

  return 0;
}