#include <iostream>
#include <fstream>
#include "array_processing.hpp"

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <num> <input> <output>\n";
    return 1;
  }

  char* end = nullptr;
  long num = std::strtol(argv[1], &end, 10);
  if (*end != '\0' || (num != 1 && num != 2)) {
    std::cerr << "First parameter is not a number or out of range\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  if (!input.is_open()) {
    std::cerr << "Cannot open input file\n";
    return 2;
  }

  std::ofstream output(argv[3]);
  if (!output.is_open()) {
    std::cerr << "Cannot open output file\n";
    return 2;
  }

  try {
    if (num == 1) {
      aushev::processFixedArray(input, output);
    } else {
      aushev::processDynamicArray(input, output);
    }
  } catch (const char* e) {
    std::cerr << "Error processing file: " << e << "\n";
    return 2;
  }

  return 0;
}
