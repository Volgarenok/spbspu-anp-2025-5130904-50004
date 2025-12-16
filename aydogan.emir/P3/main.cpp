#include <iostream>
#include <fstream>
#include <cctype>
#include <cstddef>
#include <stdexcept>
#include <exception>
#include "matrix.hpp"

static bool isNumber(const char* s) {
  if (!s || s[0] == '\0') return false;
  for (size_t i = 0; s[i] != '\0'; ++i) {
    unsigned char ch = static_cast< unsigned char >(s[i]);
    if (!std::isdigit(ch)) return false;
  }
  return true;
}

int main(int argc, char** argv) {
  if (argc < 4) {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4) {
    std::cerr << "Too many arguments\n";
    return 1;
  }

  if (!isNumber(argv[1])) {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }

  if (argv[1][1] != '\0') {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  int variant = argv[1][0] - '0';
  if (variant < 1 || variant > 4) {
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

  int r = 0, c = 0;
  if (!(in >> r >> c)) {
    std::cerr << "File is empty\n";
    return 2;
  }

  if ((r == 0 && c != 0) || (r != 0 && c == 0) || (r < 0 || c < 0)) {
    std::cerr << "Invalid rows or columns\n";
    return 2;
  }

  if (r == 0 && c == 0) {
    out << 0 << "\n";
    return 0;
  }

  int memVariant = (variant == 1 || variant == 3) ? 1 : 2;
  int task = (variant == 1 || variant == 2) ? 1 : 2;

  try {
    if (memVariant == 1) aydogan::work_static(r, c, in, out, task);
    else                 aydogan::work_dynamic(r, c, in, out, task);
  }
  catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what() << "\n";
    return 2;
  }

  return 0;
}
