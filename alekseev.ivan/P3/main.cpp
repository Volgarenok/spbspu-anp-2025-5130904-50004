#include <iostream>
#include <fstream>
#include <cstddef>
#include "matrix_actions.h"

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
  size_t rows = 0, cols = 0;
  input >> rows >> cols;
  if (input.fail()) {
    std::cerr << "Matrix unread" << "\n";
    return 2;
  }
  int num = argv[1][0] == '1' ? 1 : 2;
  int * matrix = nullptr;
  int temp[SIZE];
  if (num == 1) {
    matrix = temp;
  } else {
    matrix = new int[rows * cols];
  }

  try {
    alekseev::input_matrix(input, matrix, rows, cols);
    std::ofstream output(argv[3]);
    output << alekseev::cnt_sdl_pnt(matrix, rows, cols) << "\n";
    alekseev::lft_top_clk(matrix, rows, cols);
    alekseev::output_matrix(output, matrix, rows, cols);
    if (num == 2) {
      delete[] matrix;
    }
  } catch (const std::exception & e) {
    std::cerr << e.what() << "\n";
    if (num == 2) {
      delete[] matrix;
    }
    return 2;
  }
}


bool alekseev::check_cl_args(int argc, char ** argv)
{
  if (argc < 4) {
    throw std::logic_error("Not enough arguments");
  } else if (argc > 4) {
    throw std::logic_error("Too many arguments");
  }
  for (char * i = argv[1]; *i != '\0'; ++i) {
    if (*i < '0' or *i > '9') {
      throw std::logic_error("First parameter is not a number");
    }
  }
  char num = argv[1][0];
  if (!(num == '1' || num == '2')) {
    throw std::logic_error("First parameter is out of range");
  }
  return true;
}
