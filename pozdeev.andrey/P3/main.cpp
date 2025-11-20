#include "pozdeev.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
  int exit = 0;

  if (argc != 4) {
    std::cerr << ((argc < 4)
      ? "Not enough arguments"
      : "Too many arguments")
      << std::endl;

    return 1;
  }

  int num = pozdeev::numAnalysis(argv[1]);

  if (num == pozdeev::ERROR_INVALID_FORMAT) {
    std::cerr << "First parameter is not a number" << std::endl;
    return 1;
  }
  if (num == pozdeev::ERROR_INVALID_VALUE) {
    std::cerr << "First parameter is out of range (must be 1 or 2)" << std::endl;
    return 1;
  }

  std::ifstream fin(argv[2]);
  if (!fin.is_open()) {
    std::cerr << "ERROR: Could not open input file" << std::endl;
    return 2;
  }

  std::ofstream fout(argv[3]);
  if (!fout.is_open()) {
    std::cerr << "ERROR: Could not open output file" << std::endl;
    fin.close();
    return 2;
  }

  int temp_rows, temp_cols;
  if (!(fin >> temp_rows) || !(fin >> temp_cols)) {
    std::cerr << "ERROR: Invalid matrix dimensions format or file is empty" << std::endl;
    fin.close();
    fout.close();
    return 2;
  }

  if (temp_rows < 0 || temp_cols < 0) {
    std::cerr << "ERROR: Matrix dimensions cannot be negative" << std::endl;
    fin.close();
    fout.close();
    return 2;
  }

  size_t rows = static_cast<size_t>(temp_rows);
  size_t cols = static_cast<size_t>(temp_cols);


  if (num == 1) {
    exit = pozdeev::processStatic(fin, fout, rows, cols);
  } else {
    exit = pozdeev::processDynamic(fin, fout, rows, cols);
  }

  fin.close();
  fout.close();

  return exit;
}
