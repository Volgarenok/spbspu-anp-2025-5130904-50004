#include <iostream>
#include <fstream>
#include <cctype>
#include <stdexcept>
#include <exception>
#include "lab.hpp"

int main(int argc, char** argv) {
  if (argc < 4) {
    std::cerr << "Not enough arguments\n";
    return 1;
  }

  if (argc > 4) {
    std::cerr << "Too many arguments\n";
    return 1;
  }

  std::size_t i = 0;
  while (argv[1][i] != '\0') {
    unsigned char ch = static_cast<unsigned char>(argv[1][i]);
    if (!std::isdigit(ch)) {
      std::cerr << "First parameter is not a number\n";
      return 1;
    }
    ++i;
  }

  int variant = argv[1][0] - '0';
  if (variant != 1 && variant != 2) {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  std::ifstream in(argv[2]);
  std::ofstream out(argv[3]);

  if (!in) {
    std::cerr << "Cannot open input file\n";
    return 2;
  }

  if (!out) {
    std::cerr << "Cannot open output file\n";
    return 2;
  }

  int r = 0;
  int c = 0;

  if (!(in >> r >> c)) {
    std::cerr << "File is empty\n";
    return 2;
  }

  if ((r == 0 && c != 0) || (r != 0 && c == 0) || r < 0 || c < 0) {
    std::cerr << "Invalid rows or columns\n";
    return 2;
  }

  if (r == 0 && c == 0) {
    out << 0 << "\n";
    return 0;
  }

  constexpr int MAX = 10000;

  try {
    if (r * c <= MAX) {
      aydogan::work_static(r, c, in, out, variant);
    } else {
      aydogan::work_dynamic(r, c, in, out, variant);
    }
  } catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what() << "\n";
    return 2;
  }

  return 0;
}