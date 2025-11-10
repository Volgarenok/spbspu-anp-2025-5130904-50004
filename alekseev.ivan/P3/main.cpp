#include <iostream>
#include <fstream>
#include <cstddef>
#include "io_matrix.h"

namespace alekseev {
  bool check_cl_args(int argc, char ** argv);
}


int main(int argc, char ** argv)
{
  size_t SIZE = 10000;
  try {
    alekseev::check_cl_args(argc, argv);
  } catch (const std::exception & e) {
    std::cerr << e.what() << "\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  if (!input.is_open()) {
    std::cerr << "Failed to open file " << argv[2] << "\n";
    return 2;
  }
  size_t n = 0ull, m = 0ull;
  input >> n >> m;
  int num = argv[1][0] == '1' ? 1 : 2;
  int * matrix = nullptr;
  if (num == 1) {
    int temp[SIZE];
    matrix = temp;
  } else {
    matrix = new int[n * m];
  }

  alekseev::input_matrix(input, matrix, n, m);
  std::ofstream output(argv[3]);
  alekseev::output_matrix(output, matrix, n, m);
}


bool alekseev::check_cl_args(int argc, char ** argv)
{
  if (argc < 4) {
    throw std::invalid_argument("Not enough arguments");
  } else if (argc > 4) {
    throw std::invalid_argument("Too many arguments");
  }
  for (char * i = argv[1]; *i != '\0'; ++i) {
    if (*i < '0' or *i > '9') {
      throw std::invalid_argument("First parameter is not a number");
    }
  }
  char num = argv[1][0];
  if (!(num == '1' || num == '2')) {
    throw std::invalid_argument("First parameter is out of range");
  }
  return true;
}
