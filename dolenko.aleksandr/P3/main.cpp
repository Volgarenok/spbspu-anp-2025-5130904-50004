#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

namespace dolenko {

constexpr size_t MAX_FIXED_SIZE = 10000;
constexpr size_t MAX_ROWS = 100;
constexpr size_t MAX_COLS = 100;

int** allocateDynamicMatrix(size_t rows, size_t cols);
void freeDynamicMatrix(int** data, size_t rows);
istream& readMatrix(istream& in, int* arr, size_t rows, size_t cols);
ostream& writeMatrix(ostream& out, const int* arr, size_t rows, size_t cols, size_t res);
int findLongestColumn(const int* data, size_t rows, size_t cols);
int countLocalMins(const int* data, size_t rows, size_t cols);

int** allocateDynamicMatrix(size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0) {
    return nullptr;
  }

  int** data = static_cast<int**>(malloc(rows * sizeof(int*)));
  if (data == nullptr) {
    return nullptr;
  }

  for (size_t i = 0; i < rows; ++i) {
    data[i] = static_cast<int*>(malloc(cols * sizeof(int)));
    if (data[i] == nullptr) {
      for (size_t j = 0; j < i; ++j) {
        free(data[j]);
      }
      free(data);
      return nullptr;
    }
  }

  return data;
}

void freeDynamicMatrix(int** data, size_t rows)
{
  if (data != nullptr) {
    for (size_t i = 0; i < rows; ++i) {
      free(data[i]);
    }
    free(data);
  }
}

istream& readMatrix(istream& in, int* arr, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      in >> arr[i * cols + j];
    }
  }
  return in;
}

ostream& writeMatrix(ostream& out, const int* arr, size_t rows, size_t cols, size_t res)
{
  out << res;
  return out;
}

int findLongestColumn(const int* data, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0) {
    return 0;
  }

  int maxLength = 0;
  int columnWithMax = 0;

  for (size_t j = 0; j < cols; ++j) {
    int currentLength = 1;
    int maxCurrentCol = 1;

    for (size_t i = 1; i < rows; ++i) {
      int current = data[i * cols + j];
      int previous = data[(i - 1) * cols + j];
      
      if (current == previous) {
        currentLength++;
      } else {
        if (currentLength > maxCurrentCol) {
          maxCurrentCol = currentLength;
        }
        currentLength = 1;
      }
    }

    if (currentLength > maxCurrentCol) {
      maxCurrentCol = currentLength;
    }
    
    if (maxCurrentCol > maxLength) {
      maxLength = maxCurrentCol;
      columnWithMax = static_cast<int>(j) + 1;
    }
  }

  return columnWithMax;
}

int countLocalMins(const int* data, size_t rows, size_t cols)
{
  if (rows < 3 || cols < 3) {
    return 0;
  }

  int count = 0;

  for (size_t i = 1; i < rows - 1; ++i) {
    for (size_t j = 1; j < cols - 1; ++j) {
      int current = data[i * cols + j];
      bool isLocalMin = true;

      for (int di = -1; di <= 1 && isLocalMin; ++di) {
        for (int dj = -1; dj <= 1 && isLocalMin; ++dj) {
          if (di == 0 && dj == 0) {
            continue;
          }
          size_t ni = i + di;
          size_t nj = j + dj;
          int neighbor = data[ni * cols + nj];
          if (current >= neighbor) {
            isLocalMin = false;
          }
        }
      }

      if (isLocalMin) {
        count++;
      }
    }
  }

  return count;
}

}

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    cerr << "Wrong number of arguments" << "\n";
    return 1;
  }

  if (!isdigit(argv[1][0]) || argv[1][1] != '\0' || argv[1][0] > '2')
  {
    cerr << "First parameter is invalid" << "\n";
    return 1;
  }

  int num = argv[1][0] - '0';

  ifstream in(argv[2]);
  ofstream out(argv[3]);

  if (!in.is_open()) {
    cerr << "Cannot open input file";
    return 2;
  }

  size_t rows = 0;
  size_t cols = 0;
  
  if (!(in >> rows >> cols)) {
    cerr << "Cannot read matrix dimensions";
    in.close();
    return 2;
  }

  if (num == 1) {
    if (rows > dolenko::MAX_ROWS || cols > dolenko::MAX_COLS || rows * cols > dolenko::MAX_FIXED_SIZE) {
      cerr << "Matrix too large for fixed array";
      in.close();
      return 2;
    }
  }

  int* matrix_data = nullptr;
  
  if (num == 1) {
    static int fixed_matrix[dolenko::MAX_ROWS * dolenko::MAX_COLS];
    matrix_data = fixed_matrix;
  } else {
    matrix_data = static_cast<int*>(malloc(rows * cols * sizeof(int)));
    if (matrix_data == nullptr) {
      cerr << "Memory allocation failed";
      in.close();
      return 2;
    }
  }

  dolenko::readMatrix(in, matrix_data, rows, cols);
  
  if (!in) {
    cerr << "Error reading matrix data";
    if (num == 2) {
      free(matrix_data);
    }
    in.close();
    return 2;
  }
  
  in.close();

  int localMins = dolenko::countLocalMins(matrix_data, rows, cols);
  int longestColumn = dolenko::findLongestColumn(matrix_data, rows, cols);

  if (!out.is_open()) {
    cerr << "Cannot open output file";
    if (num == 2) {
      free(matrix_data);
    }
    return 1;
  }

  out << localMins << endl;
  out << longestColumn << endl;
  
  out.close();

  if (num == 2) {
    free(matrix_data);
  }

  return 0;
}
