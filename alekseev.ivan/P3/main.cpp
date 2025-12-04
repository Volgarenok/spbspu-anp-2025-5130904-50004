#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>
#include "matrix_actions.h"


namespace alekseev {
  bool check_cl_args(int argc, char ** argv, int & num);
}


int main(int argc, char ** argv)
{
  int num = 0;
  try {
    alekseev::check_cl_args(argc, argv, num);
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
  int * matrix = nullptr;
  int temp[10000];
  if (num == 1) {
    matrix = temp;
  } else {
    matrix = new int[rows * cols];
  }

  try {
    alekseev::input_matrix(input, matrix, rows, cols);
    if (input.fail()) {
      throw std::runtime_error("Matrix unread");
    }
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


bool alekseev::check_cl_args(int argc, char ** argv, int & num)
{
  if (argc < 4) {
    throw std::invalid_argument("Not enough arguments");
  } else if (argc > 4) {
    throw std::invalid_argument("Too many arguments");
  }
  int t = 0;
  t = std::stoi(argv[1]);
  if (!(t == 1 || t == 2)) {
    throw std::invalid_argument("First parameter is out of range");
  }
  num = t;
  return true;
}
