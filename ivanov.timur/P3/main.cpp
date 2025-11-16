#include<fstream>
#include<iostream>

int main(int argc, char ** argv) {
  if (argc != 4) {
    std::cerr << "Error: Incorrect number of arguments." << std::endl;
    return 1;
  }

  std::ifstream input(argv[2]);

  int num;
  input >> num;
  if ((num != 1 && num != 2) || std::cin.fail()) {
    std::cerr << "Error: Wrong question" << std::endl;
    return 1;
  }
  if (!input.is_open()) {
    std::cerr << "Error: Cannot open input file." << std::endl;
    return 1;
  }
  int rows, cols;
  input >> rows >> cols;
  if (rows < 0 || cols < 0 || !std::cin) {
    std::cerr << "Error: Invalid matrix dimensions." << std::endl;
    return 1;
  }
  if (num == 1 && rows * cols > 10000) {
    std::cerr << "Error: Matrix too large for static array." << std::endl;
    return 1;
  }

  std::ofstream output(argv[3]);
  return 0;
}