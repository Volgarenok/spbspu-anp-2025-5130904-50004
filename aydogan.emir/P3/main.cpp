#include <iostream>
#include <fstream>
#include "lab.hpp"

int main(int argc, char ** argv)
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

  if (argv[1][0] == '\0')
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }

  char ch = argv[1][0];

  if (argv[1][1] != '\0' || ch < '0' || ch > '9')
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }

  int variant = ch - '0';

  if (variant != 1 && variant != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  std::ifstream in(argv[2]);
  if (!in)
  {
    std::cerr << "Cannot open input file\n";
    return 2;
  }

  std::ofstream out(argv[3]);
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

  if ((r == 0 && c != 0) || (r != 0 && c == 0) || r < 0 || c < 0)
  {
    std::cerr << "Invalid rows or columns\n";
    return 2;
  }

  if (r == 0 && c == 0)
  {
    out << "\n";
    return 0;
  }

  int count = r * c;
  int * a = new int[count];

  aydogan::readMatrix(in, a, count);

  if (!in)
  {
    delete[] a;
    return 2;
  }

  int result = aydogan::processMatrix(r, c, a, variant);

  delete[] a;

  out << result << "\n";

  return 0;
}
