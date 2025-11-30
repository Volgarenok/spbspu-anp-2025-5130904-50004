#include <iostream>
#include <fstream>
#include <cctype>
namespace bychkovskaya {

bool ifNumber(char* m)
{
  size_t k = 0;
  size_t k1 = 0;
  for (size_t i = 0; m[i]!='\0'; ++i) {
    if (isdigit(m[i])) {
      ++k;
    }
    ++k1;
  }
  if (k == k1) {
    return true;
  }
  return false;
}

int* create(size_t rows, size_t cols)
{
  int* result = nullptr;
  try {
    result = new int [rows * cols];
  } catch (const std::bad_alloc& e) {
    throw std::runtime_error("Not enough memory");
  }
  return result;
}

std::ifstream& inputMatrix(std::ifstream& in, int* m, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      in >> m[i * cols + j];
      if (!in) {
        throw std::invalid_argument("Wrong matrix input");
      }
    }
  }
  return in;
}

size_t cntColNsm(const int* m, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t j = 0; j < cols; ++j) {
    size_t countCol = 0;
    for (size_t i = 0; i < rows-1; ++i) {
      if (m[i * cols + j] == m[i * cols + j + cols]) {
        ++countCol;
      }
    }
    if (countCol == 0) {
      ++count;
    }
  }
  return count;
}

size_t cntNzrDig(const int* m, size_t rows, size_t cols)
{
  size_t originalCols = cols;
  if (rows > cols) {
    rows = cols;
  } else if (rows < cols) {
    cols = rows;
  }
  size_t count = 0;
  int k = -int(rows) + 1;
  while (k < int(rows)) {
    size_t countDiag = 0;
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < cols; j++) {
        if (i == j) {
          if ((int(j) + k >= 0) && (int(j) + k < int(cols))) {
            if (m[i * originalCols + j + k] == 0) {
              ++countDiag;
            }
          }
        }
      }
    }
    if (countDiag == 0 && k != 0) {
      ++count;
    }
    ++k;
  }
  return count;
}

void outputMatrix(std::ofstream& out, const int* m, size_t rows, size_t cols) {
  out << bychkovskaya::cntColNsm(m, rows, cols) << "\n";
  out << bychkovskaya::cntNzrDig(m, rows, cols) << "\n";
}

}

int main(int argc, char** argv)
{
  if (argc > 4) {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  } else if (argc < 4) {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }
  else {
    if ((argv[1][0] == '1' || argv[1][0] == '2') && argv[1][1] == '\0') {
      size_t rows = 0;
      size_t cols = 0;
      std::ifstream input(argv[2]);
      input >> rows >> cols;
      if (!input) {
        input.close();
        std::cerr << "Wrong matrix input" << "\n";
        return 2;
      }
      if (argv[1][0] == '1') {
        int fixedMatrix[10000];
        try {
          bychkovskaya::inputMatrix(input, fixedMatrix, rows, cols);
        } catch (const std::invalid_argument& e) {
          input.close();
          std::cerr << e.what() << "\n";
          return 2;
        }
        input.close();
        std::ofstream output(argv[3]);
        bychkovskaya::outputMatrix(output, fixedMatrix, rows, cols);
        output.close();
      }
      if (argv[1][0] == '2') {
        int* dynamicMatrix = nullptr;
        try {
          dynamicMatrix = bychkovskaya::create(rows, cols);
        } catch (const std::runtime_error& e) {
          std::cerr << e.what() << "\n";
          return 2;
        }
        try {
          bychkovskaya::inputMatrix(input, dynamicMatrix, rows, cols);
          input.close();
          std::ofstream output(argv[3]);
          bychkovskaya::outputMatrix(output, dynamicMatrix, rows, cols);
          output.close();
          delete[] dynamicMatrix;
        } catch (const std::exception& e) {
          std::cerr << e.what() << "\n";
          delete[] dynamicMatrix;
          return 2;
        }
      }
    } else {
      if (bychkovskaya::ifNumber(argv[1]) == 1) {
        std::cerr << "First parameter is out of range" << "\n";
        return 1;
      }
      if (bychkovskaya::ifNumber(argv[1]) == 0) {
        std::cerr << "First parameter is not a number" << "\n";
        return 1;
      }
    }
  }
}

